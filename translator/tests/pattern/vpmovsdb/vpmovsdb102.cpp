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
#include <vector>

class TestPtnGenerator : public TestGenerator {
public:
  void setInitialRegValue() {
    /* Here modify arrays of inputGenReg, inputPredReg, inputZReg */
    setInputZregAllRandomHex();

    std::vector<int> pattern = {30, 31};

    for (auto i : pattern) {
      inputZReg[i].us_dt[0] = ~uint32_t(0);
      inputZReg[i].us_dt[1] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[2] = uint32_t(0xFF);
      inputZReg[i].us_dt[3] = uint32_t(0x7F);
      inputZReg[i].us_dt[4] = uint32_t(0x1);
      inputZReg[i].us_dt[9] = ~uint32_t(0);
      inputZReg[i].us_dt[8] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[7] = uint32_t(0xFF);
      inputZReg[i].us_dt[6] = uint32_t(0x7F);
      inputZReg[i].us_dt[5] = uint32_t(0x1);
      inputZReg[i].us_dt[10] = ~uint32_t(0);
      inputZReg[i].us_dt[11] = uint32_t(0x7FFFFFFF);
      inputZReg[i].us_dt[12] = uint32_t(0xFF);
      inputZReg[i].us_dt[13] = uint32_t(0x7F);
      inputZReg[i].us_dt[14] = uint32_t(0x1);
      inputZReg[i].us_dt[15] = ~uint32_t(0);
    }

    inputPredReg[1] = uint64_t(0); /* Both x86_64 and aarch64 */
#ifndef __ARM_ARCH
    inputPredReg[2] = (1 << 0) | (1 << 7);
    inputPredReg[3] = (1 << 0) | (1 << 2) | (1 << 7) | (1 << 8);
    inputPredReg[4] = (1 << 0) | (1 << 2) | (1 << 7) | (1 << 10) | (1 << 15);
#else
    inputPredReg[2] = (1 << 0) | (1 << 28);
    inputPredReg[3] = (1 << 0) | (1 << 8) | (1 << 28) | (uint64_t(1) << 32);
    inputPredReg[4] = (1 << 0) | (1 << 8) | (1 << 28) | (uint64_t(1) << 40) |
                      (uint64_t(1) << 60);
#endif
    inputPredReg[7] = ~uint64_t(0); /* Both x86_64 and aarch64 */
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;
    addr = reinterpret_cast<size_t>(&(inputZReg[0].ud_dt[0]));
    mov(rax, addr);

    /* Dst=Mem, src=Zmm */
    vpmovsdb(ptr[rax], Zmm(31) | k1);
    vmovups(Zmm(1), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Zmm(31) | k2);
    vmovups(Zmm(2), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Zmm(31) | k3);
    vmovups(Zmm(3), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Zmm(31) | k4);
    vmovups(Zmm(4), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Zmm(31) | k7);
    vmovups(Zmm(5), ptr[rax]);

    /* Dst=Mem, src=Ymm */
    vpmovsdb(ptr[rax], Ymm(31) | k1);
    vmovups(Zmm(6), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Ymm(31) | k2);
    vmovups(Zmm(7), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Ymm(31) | k3);
    vmovups(Zmm(8), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Ymm(31) | k4);
    vmovups(Zmm(9), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Ymm(31) | k7);
    vmovups(Zmm(10), ptr[rax]);

    /* Dst=Mem, src=Xmm */
    vpmovsdb(ptr[rax], Xmm(31) | k1);
    vmovups(Zmm(11), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Xmm(31) | k2);
    vmovups(Zmm(12), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Xmm(31) | k3);
    vmovups(Zmm(13), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Xmm(31) | k4);
    vmovups(Zmm(14), ptr[rax]);

    add(rax, 64);
    vpmovsdb(ptr[rax], Xmm(31) | k7);
    vmovups(Zmm(15), ptr[rax]);

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k2, rax);
    kmovq(k3, rax);
    kmovq(k4, rax);
#else
    ptrue(p2.b, Xbyak_aarch64::VL1);
    ptrue(p3.b, Xbyak_aarch64::VL1);
    ptrue(p4.b, Xbyak_aarch64::VL1);
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
