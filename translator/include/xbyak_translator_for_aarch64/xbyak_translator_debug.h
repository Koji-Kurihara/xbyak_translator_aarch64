#pragma once
/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
/*BEGIN_LEGAL

Copyright (c) 2019 Intel Corporation

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

END_LEGAL */
#include "xed-examples-util_aarch64.h"
#include "xed/xed-interface.h"

struct xt_a64fx_operands_structV3_t;
struct xt_a64fx_operands_struct_t;

void print_misc(xed_decoded_inst_t *xedd) {
  xed_uint_t i = 0;
  const xed_operand_values_t *ov = xed_decoded_inst_operands_const(xedd);
  const xed_inst_t *xi = xed_decoded_inst_inst(xedd);
  xed_exception_enum_t e = xed_inst_exception(xi);
  xed_uint_t np = xed_decoded_inst_get_nprefixes(xedd);

  xed_isa_set_enum_t isaset = xed_decoded_inst_get_isa_set(xedd);

  if (xed_operand_values_has_real_rep(ov)) {
    xed_iclass_enum_t norep = xed_rep_remove(xed_decoded_inst_get_iclass(xedd));
    printf("REAL REP ");
    printf("\tcorresponding no-rep iclass: %s\n", xed_iclass_enum_t2str(norep));
  }
  if (xed_operand_values_has_rep_prefix(ov)) {
    printf("F3 PREFIX\n");
  }
  if (xed_operand_values_has_repne_prefix(ov)) {
    printf("F2 PREFIX\n");
  }
  if (xed_operand_values_has_address_size_prefix(ov)) {
    printf("67 PREFIX\n");
  }
  if (xed_operand_values_has_operand_size_prefix(ov)) {
    /* this 66 prefix is not part of the opcode */
    printf("66-OSZ PREFIX\n");
  }
  if (xed_operand_values_has_66_prefix(ov)) {
    /* this is any 66 prefix including the above */
    printf("ANY 66 PREFIX\n");
  }

  if (xed_decoded_inst_get_attribute(xedd, XED_ATTRIBUTE_RING0)) {
    printf("RING0 only\n");
  }

  if (e != XED_EXCEPTION_INVALID) {
    printf("EXCEPTION TYPE: %s\n", xed_exception_enum_t2str(e));
  }
  if (xed_decoded_inst_is_broadcast(xedd))
    printf("BROADCAST\n");

  if (xed_classify_sse(xedd) || xed_classify_avx(xedd) ||
      xed_classify_avx512(xedd)) {
    if (xed_classify_avx512_maskop(xedd))
      printf("AVX512 KMASK-OP\n");
    else {
      xed_bool_t sse = 0;
      if (xed_classify_sse(xedd)) {
        sse = 1;
        printf("SSE\n");
      } else if (xed_classify_avx(xedd))
        printf("AVX\n");
      else if (xed_classify_avx512(xedd))
        printf("AVX512\n");

      if (xed_decoded_inst_get_attribute(xedd, XED_ATTRIBUTE_SIMD_SCALAR))
        printf("SCALAR\n");
      else {
        // xed_decoded_inst_vector_length_bits is only for VEX/EVEX instr.
        // This will print 128 vl for FXSAVE and LD/ST MXCSR which is
        // unfortunate.
        xed_uint_t vl_bits =
            sse ? 128 : xed_decoded_inst_vector_length_bits(xedd);
        printf("Vector length: %u \n", vl_bits);
      }
    }
  }

  // does not include instructions that have XED_ATTRIBUTE_MASK_AS_CONTROL.
  // does not include vetor instructions that have k0 as a mask register.
  if (xed_decoded_inst_masked_vector_operation(xedd))
    printf("WRITE-MASKING\n");

  if (np)
    printf("Number of legacy prefixes: %u \n", np);

  printf("ISA SET: [%s]\n", xed_isa_set_enum_t2str(isaset));
  for (i = 0; i < XED_MAX_CPUID_BITS_PER_ISA_SET; i++) {
    xed_cpuid_bit_enum_t cpuidbit;
    xed_cpuid_rec_t crec;
    int r;
    cpuidbit = xed_get_cpuid_bit_for_isa_set(isaset, i);
    if (cpuidbit == XED_CPUID_BIT_INVALID)
      break;
    printf("%d\tCPUID BIT NAME: [%s]\n", i, xed_cpuid_bit_enum_t2str(cpuidbit));

    r = xed_get_cpuid_rec(cpuidbit, &crec);
    if (r) {
      printf("\tLeaf 0x%08x, subleaf 0x%08x, %s[%u]\n", crec.leaf, crec.subleaf,
             xed_reg_enum_t2str(crec.reg), crec.bit);
    } else {
      printf("Could not find cpuid leaf information\n");
    }
  }
}

void print_attributes(xed_decoded_inst_t *xedd) {
  /* Walk the attributes. Generally, you'll know the one you want to
   * query and just access that one directly. */

  const xed_inst_t *xi = xed_decoded_inst_inst(xedd);

  unsigned int i, nattributes = xed_attribute_max();

  printf("ATTRIBUTES: ");
  for (i = 0; i < nattributes; i++) {
    xed_attribute_enum_t attr = xed_attribute(i);
    if (xed_inst_get_attribute(xi, attr))
      printf("%s ", xed_attribute_enum_t2str(attr));
  }
  printf("\n");
}

void print_reads_zf_flag(xed_decoded_inst_t *xedd) {
  /* example of reading one bit from the flags set */
  if (xed_decoded_inst_uses_rflags(xedd)) {
    xed_simple_flag_t const *rfi = xed_decoded_inst_get_rflags_info(xedd);
    xed_flag_set_t const *read_set = xed_simple_flag_get_read_flag_set(rfi);
    if (read_set->s.zf) {
      printf("READS ZF\n");
    }
  }
}

void print_flags(xed_decoded_inst_t *xedd) {
  unsigned int i, nflags;
  if (xed_decoded_inst_uses_rflags(xedd)) {
    const xed_simple_flag_t *rfi = xed_decoded_inst_get_rflags_info(xedd);
    assert(rfi);
    printf("FLAGS:\n");
    if (xed_simple_flag_reads_flags(rfi)) {
      printf("   reads-rflags ");
    } else if (xed_simple_flag_writes_flags(rfi)) {
      // XED provides may-write and must-write information
      if (xed_simple_flag_get_may_write(rfi)) {
        printf("  may-write-rflags ");
      }
      if (xed_simple_flag_get_must_write(rfi)) {
        printf("  must-write-rflags ");
      }
    }
    nflags = xed_simple_flag_get_nflags(rfi);
    for (i = 0; i < nflags; i++) {
      const xed_flag_action_t *fa = xed_simple_flag_get_flag_action(rfi, i);
      char buf[500];
      xed_flag_action_print(fa, buf, 500);
      printf("%s ", buf);
    }
    printf("\n");
    // or as as bit-union
    {
      xed_flag_set_t const *read_set = xed_simple_flag_get_read_flag_set(rfi);
      /* written set include undefined flags */
      xed_flag_set_t const *written_set =
          xed_simple_flag_get_written_flag_set(rfi);
      xed_flag_set_t const *undefined_set =
          xed_simple_flag_get_undefined_flag_set(rfi);
      char buf[500];
      xed_flag_set_print(read_set, buf, 500);
      printf("       read: %30s mask=0x%x\n", buf, xed_flag_set_mask(read_set));
      xed_flag_set_print(written_set, buf, 500);
      printf("    written: %30s mask=0x%x\n", buf,
             xed_flag_set_mask(written_set));
      xed_flag_set_print(undefined_set, buf, 500);
      printf("  undefined: %30s mask=0x%x\n", buf,
             xed_flag_set_mask(undefined_set));
    }
  }
}

void print_memops(xed_decoded_inst_t *xedd) {
  unsigned int i, memops = xed_decoded_inst_number_of_memory_operands(xedd);

  printf("Memory Operands\n");

  for (i = 0; i < memops; i++) {
    xed_bool_t r_or_w = 0;
    xed_reg_enum_t seg;
    xed_reg_enum_t base;
    xed_reg_enum_t indx;
    printf("  %u ", i);
    if (xed_decoded_inst_mem_read(xedd, i)) {
      printf("   read ");
      r_or_w = 1;
    }
    if (xed_decoded_inst_mem_written(xedd, i)) {
      printf("written ");
      r_or_w = 1;
    }
    if (!r_or_w) {
      printf("   agen "); // LEA instructions
    }
    seg = xed_decoded_inst_get_seg_reg(xedd, i);
    if (seg != XED_REG_INVALID) {
      printf("SEG= %s ", xed_reg_enum_t2str(seg));
    }
    base = xed_decoded_inst_get_base_reg(xedd, i);
    if (base != XED_REG_INVALID) {
      printf("BASE= %3s/%3s ", xed_reg_enum_t2str(base),
             xed_reg_class_enum_t2str(xed_reg_class(base)));
    }
    indx = xed_decoded_inst_get_index_reg(xedd, i);
    if (i == 0 && indx != XED_REG_INVALID) {
      printf("INDEX= %3s/%3s ", xed_reg_enum_t2str(indx),
             xed_reg_class_enum_t2str(xed_reg_class(indx)));
      if (xed_decoded_inst_get_scale(xedd, i) != 0) {
        // only have a scale if the index exists.
        printf("SCALE= %u ", xed_decoded_inst_get_scale(xedd, i));
      }
    }

    if (xed_operand_values_has_memory_displacement(xedd)) {
      xed_uint_t disp_bits =
          xed_decoded_inst_get_memory_displacement_width(xedd, i);
      if (disp_bits) {
        xed_int64_t disp;
        printf("DISPLACEMENT_BYTES= %u ", disp_bits);
        disp = xed_decoded_inst_get_memory_displacement(xedd, i);
        printf("0x" XED_FMT_LX16 " base10=" XED_FMT_LD, disp, disp);
      }
    }
    printf(" ASZ%u=%u\n", i, xed_decoded_inst_get_memop_address_width(xedd, i));
  }
  printf("  MemopBytes = %u\n",
         xed_decoded_inst_get_memory_operand_length(xedd, 0));
}

void print_operands(xed_decoded_inst_t *xedd) {
  unsigned int i, noperands;
#define TBUFSZ 90
  char tbuf[TBUFSZ];
  const xed_inst_t *xi = xed_decoded_inst_inst(xedd);
  xed_operand_action_enum_t rw;
  xed_uint_t bits;

  printf("Operands\n");
  noperands = xed_inst_noperands(xi);
  printf("#   TYPE               DETAILS        VIS  RW       OC2 BITS BYTES "
         "NELEM ELEMSZ   ELEMTYPE   REGCLASS\n");
  printf("#   ====               =======        ===  ==       === ==== ===== "
         "===== ======   ========   ========\n");
  tbuf[0] = 0;
  for (i = 0; i < noperands; i++) {
    const xed_operand_t *op = xed_inst_operand(xi, i);
    xed_operand_enum_t op_name = xed_operand_name(op);
    printf("%u %6s ", i, xed_operand_enum_t2str(op_name));

    switch (op_name) {
    case XED_OPERAND_AGEN:
    case XED_OPERAND_MEM0:
    case XED_OPERAND_MEM1:
      // we print memops in a different function
      xed_strcpy(tbuf, "(see below)");
      break;
    case XED_OPERAND_PTR:     // pointer (always in conjunction with a IMM0)
    case XED_OPERAND_RELBR: { // branch displacements
      xed_uint_t disp_bits =
          xed_decoded_inst_get_branch_displacement_width(xedd);
      if (disp_bits) {
        xed_int32_t disp = xed_decoded_inst_get_branch_displacement(xedd);
#if defined(_WIN32) && !defined(PIN_CRT)
        _snprintf_s(tbuf, TBUFSZ, TBUFSZ, "BRANCH_DISPLACEMENT_BYTES= %d %08x",
                    disp_bits, disp);
#else
        snprintf(tbuf, TBUFSZ, "BRANCH_DISPLACEMENT_BYTES= %d %08x", disp_bits,
                 disp);
#endif
      }
    } break;

    case XED_OPERAND_IMM0: { // immediates
      char buf[64];
      const unsigned int no_leading_zeros = 0;
      xed_uint_t ibits;
      const xed_bool_t lowercase = 1;
      ibits = xed_decoded_inst_get_immediate_width_bits(xedd);
      if (xed_decoded_inst_get_immediate_is_signed(xedd)) {
        xed_uint_t rbits = ibits ? ibits : 8;
        xed_int32_t x = xed_decoded_inst_get_signed_immediate(xedd);
        xed_uint64_t y = XED_STATIC_CAST(
            xed_uint64_t,
            xed_sign_extend_arbitrary_to_64((xed_uint64_t)x, ibits));
        xed_itoa_hex_ul(buf, y, rbits, no_leading_zeros, 64, lowercase);
      } else {
        xed_uint64_t x = xed_decoded_inst_get_unsigned_immediate(xedd);
        xed_uint_t rbits = ibits ? ibits : 16;
        xed_itoa_hex_ul(buf, x, rbits, no_leading_zeros, 64, lowercase);
      }
#if defined(_WIN32) && !defined(PIN_CRT)
      _snprintf_s(tbuf, TBUFSZ, TBUFSZ, "0x%s(%db)", buf, ibits);
#else
      snprintf(tbuf, TBUFSZ, "0x%s(%db)", buf, ibits);
#endif
      break;
    }
    case XED_OPERAND_IMM1: { // 2nd immediate is always 1 byte.
      xed_uint8_t x = xed_decoded_inst_get_second_immediate(xedd);
#if defined(_WIN32) && !defined(PIN_CRT)
      _snprintf_s(tbuf, TBUFSZ, TBUFSZ, "0x%02x", (int)x);
#else
      snprintf(tbuf, TBUFSZ, "0x%02x", (int)x);
#endif

      break;
    }

    case XED_OPERAND_REG0:
    case XED_OPERAND_REG1:
    case XED_OPERAND_REG2:
    case XED_OPERAND_REG3:
    case XED_OPERAND_REG4:
    case XED_OPERAND_REG5:
    case XED_OPERAND_REG6:
    case XED_OPERAND_REG7:
    case XED_OPERAND_REG8:
    case XED_OPERAND_BASE0:
    case XED_OPERAND_BASE1: {

      xed_reg_enum_t r = xed_decoded_inst_get_reg(xedd, op_name);
#if defined(_WIN32) && !defined(PIN_CRT)
      _snprintf_s(tbuf, TBUFSZ, TBUFSZ, "%s=%s",
                  xed_operand_enum_t2str(op_name), xed_reg_enum_t2str(r));
#else
      snprintf(tbuf, TBUFSZ, "%s=%s", xed_operand_enum_t2str(op_name),
               xed_reg_enum_t2str(r));
#endif
      break;
    }
    default:
      printf("need to add support for printing operand: %s",
             xed_operand_enum_t2str(op_name));
      assert(0);
    }
    printf("%21s", tbuf);

    rw = xed_decoded_inst_operand_action(xedd, i);

    printf(
        " %10s %3s %9s",
        xed_operand_visibility_enum_t2str(xed_operand_operand_visibility(op)),
        xed_operand_action_enum_t2str(rw),
        xed_operand_width_enum_t2str(xed_operand_width(op)));

    bits = xed_decoded_inst_operand_length_bits(xedd, i);
    printf("  %3u", bits);
    /* rounding, bits might not be a multiple of 8 */
    printf("  %4u", (bits + 7) >> 3);

    printf("    %2u", xed_decoded_inst_operand_elements(xedd, i));
    printf("    %3u", xed_decoded_inst_operand_element_size_bits(xedd, i));

    printf(" %10s", xed_operand_element_type_enum_t2str(
                        xed_decoded_inst_operand_element_type(xedd, i)));
    printf(" %10s\n", xed_reg_class_enum_t2str(xed_reg_class(
                          xed_decoded_inst_get_reg(xedd, op_name))));
  }
}

void xt_dump_a64fx_operandsV3(xt_a64fx_operands_structV3_t *a64) {
  std::cout << std::dec;

  std::cout << "==============================" << std::endl;
  std::cout << "A64 operand V3 information" << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << std::left << std::setw(21)
            << "predType=" << xt_to_string(a64->predType) << std::endl;
  std::cout << std::left << std::setw(21) << "EVEXb=" << a64->EVEXb
            << std::endl;
  std::cout << std::left << std::setw(21) << "EVEXrc=" << a64->EVEXrc
            << std::endl;
  for (unsigned int i = 0; i < xtNumOperands; i++) {
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].opName=" << xt_to_string(a64->operands[i].opName)
              << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].regIdx=" << a64->operands[i].regIdx << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].opWidth=" << a64->operands[i].opWidth << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].regClass=" << xt_to_string(a64->operands[i].regClass)
              << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].uimm=" << xt_to_string(a64->operands[i].uimm) << std::endl;

    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].vmIndexRegIdx="
              << xt_to_string(a64->operands[i].vmIndexRegIdx) << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].vmIndexRegWidth=" << a64->operands[i].vmIndexRegWidth
              << std::endl;

    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].memBaseIdx=" << a64->operands[i].memBaseIdx << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].memIndexIdx=" << a64->operands[i].memIndexIdx << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].memScale=" << xt_to_string(a64->operands[i].memScale)
              << std::endl;
    std::cout << std::left << "operands[" << i << std::setw(11)
              << "].memDisp=" << xt_to_string(a64->operands[i].memDisp)
              << std::endl;
  }
}

void xt_dump_a64fx_operands(xt_a64fx_operands_struct_t *a64) {
  std::cout << "==============================" << std::endl;
  std::cout << "A64 operand information" << std::endl;
  std::cout << "==============================" << std::endl;
  std::cout << std::left << std::setw(9)
            << "dstIdx=" << xt_to_string(a64->dstIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "maskIdx=" << xt_to_string(a64->maskIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "srcIdx=" << xt_to_string(a64->srcIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "src2Idx=" << xt_to_string(a64->src2Idx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "vTmpIdx=" << xt_to_string(a64->vTmpIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "pTmpIdx=" << xt_to_string(a64->pTmpIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "zTmpIdx=" << xt_to_string(a64->zTmpIdx) << std::endl;
  std::cout << std::left << std::setw(9)
            << "PredType=" << xt_to_string(a64->PredType) << std::endl;
  std::cout << std::left << std::setw(9)
            << "dstType=" << xt_to_string(a64->dstType) << std::endl;
  std::cout << std::left << std::setw(9)
            << "srcType=" << xt_to_string(a64->srcType) << std::endl;
  std::cout << std::left << std::setw(9) << "src2Type"
            << xt_to_string(a64->src2Type) << std::endl;

  std::cout << std::left << std::setw(9) << "EVEXb=" << a64->EVEXb << std::endl;
  std::cout << std::left << std::setw(9) << "dstWidth=" << a64->dstWidth
            << std::endl;
  std::cout << std::left << std::setw(9) << "srcWidth=" << a64->srcWidth
            << std::endl;
  std::cout << std::left << std::setw(9)
            << "dstRegClass=" << xt_to_string(a64->dstRegClass) << std::endl;
  std::cout << std::left << std::setw(9)
            << "srcRegClass=" << xt_to_string(a64->srcRegClass) << std::endl;
  std::cout << std::left << std::setw(9) << "uimm=" << a64->uimm << std::endl;
  std::cout << std::left << std::setw(9) << "simm=" << a64->simm << std::endl;
  std::cout << std::left << std::setw(9) << "immWidth=" << a64->immWidth
            << std::endl;

  std::cout << std::left << std::setw(9) << "uimm2=" << a64->uimm << std::endl;
  std::cout << std::left << std::setw(9) << "simm2=" << a64->simm << std::endl;
}

void xt_dump_x86_64_decoded_info(xed_decoded_inst_t *p) {
  printf("iclass %s\t", xed_iclass_enum_t2str(xed_decoded_inst_get_iclass(p)));
  printf("category %s\t",
         xed_category_enum_t2str(xed_decoded_inst_get_category(p)));
  printf("ISA-extension %s\t",
         xed_extension_enum_t2str(xed_decoded_inst_get_extension(p)));
  printf("ISA-set %s\n",
         xed_isa_set_enum_t2str(xed_decoded_inst_get_isa_set(p)));
  printf("instruction-length %u\n", xed_decoded_inst_get_length(p));
  printf("operand-width %u\n", xed_decoded_inst_get_operand_width(p));
  printf("effective-operand-width %u\n",
         xed_operand_values_get_effective_operand_width(
             xed_decoded_inst_operands_const(p)));
  printf("effective-address-width %u\n",
         xed_operand_values_get_effective_address_width(
             xed_decoded_inst_operands_const(p)));
  printf("stack-address-width %u\n", xed_operand_values_get_stack_address_width(
                                         xed_decoded_inst_operands_const(p)));
  printf("iform-enum-name %s\n",
         xed_iform_enum_t2str(xed_decoded_inst_get_iform_enum(p)));
  printf("iform-enum-name-dispatch (zero based) %u\n",
         xed_decoded_inst_get_iform_enum_dispatch(p));
  printf("iclass-max-iform-dispatch %u\n",
         xed_iform_max_per_iclass(xed_decoded_inst_get_iclass(p)));

  // operands
  print_operands(p);

  // memops
  print_memops(p);

  // flags
  print_flags(p);
  print_reads_zf_flag(p);

  // attributes
  print_attributes(p);

  // misc
  print_misc(p);
}
