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
    //    setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT); // set float mode

    float tmp = float(0.1);

    for (int j = 0; j < 32; j++) {
      for (int i = 0; i < 16; i++) {
        inputZReg[j].sp_dt[i] = tmp;
        tmp += 0.1;
      }
    }
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    /* rax, rcx, rdx, rbx, rsp, rbp, rsi, rdi, r8, r9, r10, r11, r12, r13, r14,
     * r15 */

    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[31].ub_dt[0]));
    std::cout << "Address is " << std::hex << addr << std::endl;
    mov(rax, addr);

    /* VEX encode */
    vfnmadd231ps(Xmm(0), Xmm(1), ptr[rax]);
    vfnmadd231ps(Xmm(3), Xmm(3), ptr[rax]);
    vfnmadd231ps(Xmm(5), Xmm(6), ptr[rax]);
    vfnmadd231ps(Xmm(7), Xmm(8), ptr[rax]);
    vfnmadd231ps(Xmm(9), Xmm(9), ptr[rax]);

    /* EVEX encode */
    vfnmadd231ps(Xmm(10), Xmm(11), ptr[rax]);
    vfnmadd231ps(Xmm(13), Xmm(13), ptr[rax]);
    vfnmadd231ps(Xmm(15), Xmm(16), ptr[rax]);
    vfnmadd231ps(Xmm(17), Xmm(18), ptr[rax]);
    vfnmadd231ps(Xmm(19), Xmm(19), ptr[rax]);

    mov(rax, 0x5);
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
