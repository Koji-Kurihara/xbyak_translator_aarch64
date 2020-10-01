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
#include "test_generator2.h"

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();
    for (int i = 0; i < 16; i++) {
      if (i % 2 == 0)
        inputZReg[1].us_dt[i] = uint32_t(286392319);
      else
        inputZReg[1].us_dt[i] = uint32_t(286326784);
      inputZReg[3].us_dt[i] = uint32_t(17);
    }
#ifndef __ARM_ARCH
    inputPredReg[1] = (1 << 0) | (1 << 1);
    inputPredReg[2] = (1 << 0) | (1 << 7) | (1 << 8) | (1 << 15);
#else
    inputPredReg[1] = (1 << 0) | (1 << 4);
    inputPredReg[2] =
        (1 << 0) | (1 << 28) | (uint64_t(1) << 32) | (uint64_t(1) << 60);
#endif
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    size_t addr1;
    size_t addr2;

/* Address is aligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[29].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[27].ud_dt[0]));
    mov(rbx, addr);
    vpmovdw(ptr[rbx], Zmm(1) | k1); // truncate
    vmovdqu8(Zmm(0), ptr[rbx]);
    mov(rbx, addr1);
    vpmovdw(ptr[rbx], Zmm(3) | k2); // no truncate
    vmovdqu8(Zmm(2), ptr[rbx]);
    mov(rbx, addr2);
    vpmovdw(ptr[rbx], Zmm(5) | k2); // random
    vmovdqu8(Zmm(4), ptr[rbx]);
#endif

/* Address is unaligned */
#if 1
    addr = reinterpret_cast<size_t>(&(inputZReg[25].ud_dt[0])) + 3;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[23].ud_dt[0])) + 5;
    addr2 = reinterpret_cast<size_t>(&(inputZReg[21].ud_dt[0])) + 7;
    mov(rbx, addr);
    vpmovdw(ptr[rbx], Zmm(1) | k1);
    vmovdqu8(Zmm(7), ptr[rbx]);
    mov(rbx, addr1);
    vpmovdw(ptr[rbx], Zmm(3) | k2);
    vmovdqu8(Zmm(9), ptr[rbx]);
    mov(rbx, addr2);
    vpmovdw(ptr[rbx], Zmm(5) | k2);
    vmovdqu8(Zmm(11), ptr[rbx]);
#endif

    mov(rax,
        size_t(0x5)); // Clear RAX for diff check between x86_64 and aarch64
    mov(rbx,
        size_t(0xf)); // Clear RAX for diff check between x86_64 and aarch64

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k1, rax);
    kmovq(k2, rax);
#else
    ptrue(p1.b, Xbyak_aarch64::VL1);
    ptrue(p2.b, Xbyak_aarch64::VL1);
#endif
  }
};

int main(int argc, char *argv[]) {
  /* Initializing arrays of inputData, inputGenReg, inputPredReg, inputZReg,
   * checkGenRegMode, checkPredRegMode,checkZRegMode */
  TestPtnGenerator gen;

  /* Set bool output_jit_on_, bool exec_jit_on_ = 0; */
  gen.parseArgs(argc, argv);

  /* Generate JIT code and get function pointer */
  void (*f)();
  if (gen.isOutputJitOn()) {
    f = (void (*)())gen.gen();
  }

  /* Dump generated JIT code to a binary file */
  gen.dumpJitCode();

  /* 1:Execute JIT code, 2:dump all register values, 3:dump register values to
   * be checked */
  if (gen.isExecJitOn()) {
    /* Before executing JIT code, dump inputData, inputGenReg, inputPredReg,
     * inputZReg. */
    gen.dumpInputReg();
    f();                 /* Execute JIT code */
    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
