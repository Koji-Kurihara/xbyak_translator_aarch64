/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not.spe this file except in compliance with the License.
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
    // setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT); // set float mode

    for (unsigned int j = 0; j < NUM_Z_REG; j++) {
      for (unsigned int i = 0; i < NUM_BYTES_Z_REG / sizeof(float); i++) {
        inputZReg[j].sp_dt[i] = float((0.5 + i) * (j));
      }
    }
    // for(int i=0; i<16; i++){
    //   inputZReg[0].sp_dt[i] = 1.0f;
    //   inputZReg[1].sp_dt[i] = 0.0f;
    //   inputZReg[2].sp_dt[i] = 0.0f;
    // }

    inputPredReg[1] = uint64_t(0);
    inputPredReg[2] = ~uint64_t(0);
#ifndef __ARM_ARCH
    inputPredReg[3] = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    inputPredReg[4] = (1 << 3) | (1 << 6);
    inputPredReg[5] = (1 << 0) | (1 << 10) | (1 << 3) | (1 << 6);
#else
    inputPredReg[3] = (1 << 16) | (1 << 20) | (1 << 24) | (1 << 28);
    inputPredReg[4] = (1 << 12) | (1 << 24);
    inputPredReg[5] = (1 << 0) | (uint64_t(1) << 40) | (1 << 12) | (1 << 24);
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    /* EVEX encode */
    vfmadd132ps(Zmm(20) | k1 | T_z, Zmm(21), Zmm(22));
    vfmadd132ps(Zmm(23) | k2 | T_z, Zmm(23), Zmm(24));
    vfmadd132ps(Zmm(25) | k3 | T_z, Zmm(26), Zmm(25));
    vfmadd132ps(Zmm(27) | k4 | T_z, Zmm(28), Zmm(28));
    vfmadd132ps(Zmm(29) | k5 | T_z, Zmm(29), Zmm(29));

    mov(rax, 0x1);
#ifndef __ARM_ARCH
    kmovq(k3, rax);
    kmovq(k4, rax);
    kmovq(k5, rax);
#else
    ptrue(p3.b, Xbyak_aarch64::VL1);
    ptrue(p4.b, Xbyak_aarch64::VL1);
    ptrue(p5.b, Xbyak_aarch64::VL1);
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
