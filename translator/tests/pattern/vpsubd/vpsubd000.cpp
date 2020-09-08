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
#if 0
    /*
    for (int i = 0; i < 16; i++) {
      inputZReg[0].us_dt[i] = ~uint64_t(0);
      inputZReg[3].us_dt[i] = ~uint64_t(0);
      inputZReg[6].us_dt[i] = ~uint64_t(0);
    }
    for (int i = 0; i < 16; i++) {
      inputZReg[1].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[4].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
      inputZReg[7].us_dt[i] = uint32_t(0xFF00FF00AA55AA55);
    }
    */
#endif
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    vpsubd(Ymm(0), Ymm(1), Ymm(2));
    vpsubd(Ymm(3), Ymm(3), Ymm(4));
    vpsubd(Ymm(5), Ymm(6), Ymm(5));
    vpsubd(Ymm(7), Ymm(8), Ymm(8));
    vpsubd(Ymm(9), Ymm(9), Ymm(9));

    vpsubd(Zmm(10), Zmm(11), Zmm(12));
    vpsubd(Zmm(13), Zmm(13), Zmm(14));
    vpsubd(Zmm(15), Zmm(16), Zmm(15));
    vpsubd(Zmm(17), Zmm(18), Zmm(18));
    vpsubd(Zmm(19), Zmm(19), Zmm(19));
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
