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
#ifndef __ARM_ARCH
    inputPredReg[1] = (1 << 0) | (1 << 2) | (1 << 4) | (1 << 6);
    inputPredReg[2] = (1 << 1) | (1 << 3) | (1 << 5) | (1 << 7);
    inputPredReg[3] = ~uint64_t(0);
    inputPredReg[4] = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 6);
#else
    inputPredReg[1] =
        (1 << 0) | (1 << 16) | (uint64_t(1) << 32) | (uint64_t(1) << 48);
    inputPredReg[2] =
        (1 << 8) | (1 << 24) | (uint64_t(1) << 40) | (uint64_t(1) << 56);
    inputPredReg[3] = ~uint64_t(0);
    inputPredReg[4] =
        (1 << 8) | (1 << 24) | (uint64_t(1) << 32) | (uint64_t(1) << 48);
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr1, addr2, addr3, addr4, addr5;
    size_t addr6, addr7, addr8, addr9, addr10;
    size_t addr11, addr12, addr13, addr14, addr15;
    addr1 = reinterpret_cast<size_t>(&(inputZReg[1].sp_dt[0])) + 1;
    addr2 = reinterpret_cast<size_t>(&(inputZReg[4].sp_dt[0])) + 3;
    addr3 = reinterpret_cast<size_t>(&(inputZReg[7].sp_dt[0])) + 5;
    addr4 = reinterpret_cast<size_t>(&(inputZReg[6].sp_dt[0])) + 1;
    addr5 = reinterpret_cast<size_t>(&(inputZReg[7].sp_dt[0])) + 3;
    addr6 = reinterpret_cast<size_t>(&(inputZReg[11].sp_dt[0])) + 5;
    addr7 = reinterpret_cast<size_t>(&(inputZReg[13].sp_dt[0])) + 1;
    addr8 = reinterpret_cast<size_t>(&(inputZReg[16].sp_dt[0])) + 3;
    addr9 = reinterpret_cast<size_t>(&(inputZReg[18].sp_dt[0])) + 5;
    addr10 = reinterpret_cast<size_t>(&(inputZReg[21].sp_dt[0])) + 1;
    addr11 = reinterpret_cast<size_t>(&(inputZReg[24].sp_dt[0])) + 3;
    addr12 = reinterpret_cast<size_t>(&(inputZReg[26].sp_dt[0])) + 5;
    addr13 = reinterpret_cast<size_t>(&(inputZReg[29].sp_dt[0])) + 1;
    addr14 = reinterpret_cast<size_t>(&(inputZReg[30].sp_dt[0])) + 3;
    addr15 = reinterpret_cast<size_t>(&(inputZReg[31].sp_dt[0])) + 5;

    mov(rax, addr1);
    vpxorq(Xmm(2) | k1 | T_z, Xmm(0), ptr[rax]);
    mov(rax, addr2);
    vpxorq(Ymm(5) | k1 | T_z, Ymm(3), ptr[rax]);
    mov(rax, addr3);
    vpxorq(Zmm(8) | k1 | T_z, Zmm(6), ptr[rax]);

    mov(rax, addr4);
    vpxorq(Xmm(6) | k2 | T_z, Xmm(7), ptr[rax]);
    mov(rax, addr5);
    vpxorq(Xmm(8) | k3 | T_z, Xmm(9), ptr[rax]);
    mov(rax, addr6);
    vpxorq(Xmm(10) | k4 | T_z, Xmm(10), ptr[rax]);

    mov(rax, addr7);
    vpxorq(Ymm(13) | k2 | T_z, Ymm(14), ptr[rax]);
    mov(rax, addr8);
    vpxorq(Ymm(15) | k3 | T_z, Ymm(16), ptr[rax]);
    mov(rax, addr9);
    vpxorq(Ymm(17) | k4 | T_z, Ymm(17), ptr[rax]);

    mov(rax, addr10);
    vpxorq(Zmm(21) | k2 | T_z, Zmm(22), ptr[rax]);
    mov(rax, addr11);
    vpxorq(Zmm(23) | k3 | T_z, Zmm(24), ptr[rax]);
    mov(rax, addr12);
    vpxorq(Zmm(25) | k4 | T_z, Zmm(25), ptr[rax]);

    mov(rax, addr13);
    vpxorq(Xmm(29) | k1 | T_z, Xmm(29), ptr[rax]);
    mov(rax, addr14);
    vpxorq(Ymm(30) | k1 | T_z, Ymm(30), ptr[rax]);
    mov(rax, addr15);
    vpxorq(Zmm(31) | k1 | T_z, Zmm(31), ptr[rax]);

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k1, rax);
    kmovq(k2, rax);
    kmovq(k3, rax);
    kmovq(k4, rax);
#else
    ptrue(p1.b, Xbyak_aarch64::VL1);
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
