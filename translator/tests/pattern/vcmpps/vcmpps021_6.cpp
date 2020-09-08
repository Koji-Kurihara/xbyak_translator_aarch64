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
    setInputZregAllRandomFloat();
    setDumpZRegMode(SP_DT);

    inputZReg[0].us_dt[0] = 0;
    inputZReg[1].us_dt[0] = 0;

    inputZReg[2].us_dt[0] = inputZReg[3].us_dt[0] = float(1.1);
    inputZReg[2].us_dt[7] = inputZReg[3].us_dt[7] = float(2.2);

    inputZReg[4].us_dt[0] = inputZReg[5].us_dt[0] = float(3.3);
    inputZReg[4].us_dt[7] = inputZReg[5].us_dt[7] = float(4.4);
    inputZReg[4].us_dt[15] = inputZReg[5].us_dt[15] = float(5.5);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr0, addr1, addr2, addr3;
    addr0 = reinterpret_cast<size_t>(&(inputZReg[1].ud_dt[0]));
    addr1 = reinterpret_cast<size_t>(&(inputZReg[3].ud_dt[0]));
    addr2 = reinterpret_cast<size_t>(&(inputZReg[5].ud_dt[0]));
    addr3 = reinterpret_cast<size_t>(&(inputZReg[15].ud_dt[0]));

    mov(rax, addr0);
    mov(rcx, addr1);
    mov(rdx, addr2);
    mov(rbx, addr3);

    vcmpps(Ymm(8), Ymm(0), ptr[rax], 6);   // NLE_US
    vcmpps(Ymm(9), Ymm(2), ptr[rcx], 6);   // NLE_US
    vcmpps(Ymm(10), Ymm(4), ptr[rdx], 6);  // NLE_US
    vcmpps(Ymm(11), Ymm(15), ptr[rbx], 6); // NLE_US

    mov(rax, 5);
    mov(rcx, 5);
    mov(rdx, 5);
    mov(rbx, 5);
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
    f(); /* Execute JIT code */

#ifndef XBYAK_TRANSLATE_AARCH64
    /* Bit order of mask registers are different from x86_64 and aarch64.
       In order to compare output values of mask registers by test script,
       Bit order of x86_64 mask register values is modified here. */
    gen.modifyPredReg(SP_DT);
#endif

    gen.dumpOutputReg(); /* Dump all register values */
    gen.dumpCheckReg();  /* Dump register values to be checked */
  }

  return 0;
}
