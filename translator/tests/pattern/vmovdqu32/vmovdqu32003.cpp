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
    //    setDumpZRegMode(SP_DT); // set float mode
    setInputZregAllRandomHex();

    /* elemet is 8 bits.
       Xmm:16 elements
       Ymm:32 elements
       Zmm:64 elements */

    // Xmm range
    inputPredReg[1] = (1 << 0) | (1 << 9) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 36); /* aarch64 */

    inputPredReg[2] = (1 << 0) | (1 << 5) | (1 << 11) |
      (1 << 15) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 44) | (uint64_t(1) << 60); /* aarch64 */

    // Ymm range
    inputPredReg[3] =
      (1 << 0) | (1 << 5) | (1 << 11) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 44); /* aarch64 */
    inputPredReg[4] = (1 << 0) | (1 << 5) | (1 << 11) |
      (uint64_t(1) << 13) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 44) | (uint64_t(1) << 52); /* aarch64 */

    // Zmm range
    inputPredReg[5] = (1 << 0) | (1 << 5) | (1 << 13) |
      (uint64_t(1) << 15) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 52) | (uint64_t(1) << 60); /* aarch64 */
    inputPredReg[6] = (1 << 0) | (1 << 5) | (1 << 11) | (uint64_t(1) << 13) | (uint64_t(1) << 15) /* x86_64 */
      | (1 << 0) | (uint64_t(1) << 20) | (uint64_t(1) << 44) | (uint64_t(1) << 52) | (uint64_t(1) << 60); /* aarch64 */
    
    inputPredReg[7] = ~uint64_t(0);
  }

  void setCheckRegFlagAll() {
    /* Here modify arrays of checkGenRegMode, checkPredRegMode, checkZRegMode */
  }

  void genJitTestCode() {
    /* Here write JIT code with x86_64 mnemonic function to be tested. */
    size_t addr;

    /* Address is aligned */
    addr = reinterpret_cast<size_t>(&(inputZReg[31].sp_dt[0]));
    mov(rax, addr);

    vmovdqu32(Xmm(1) | k1, ptr[rax]);
    vmovdqu32(Xmm(2) | k2, ptr[rax]);
    vmovdqu32(Xmm(3) | k3, ptr[rax]);
    vmovdqu32(Xmm(4) | k4, ptr[rax]);
    vmovdqu32(Xmm(5) | k5, ptr[rax]);
    vmovdqu32(Xmm(6) | k6, ptr[rax]);
    vmovdqu32(Xmm(7) | k7, ptr[rax]);

    vmovdqu32(Ymm(11) | k1, ptr[rax]);
    vmovdqu32(Ymm(12) | k2, ptr[rax]);
    vmovdqu32(Ymm(13) | k3, ptr[rax]);
    vmovdqu32(Ymm(14) | k4, ptr[rax]);
    vmovdqu32(Ymm(15) | k5, ptr[rax]);
    vmovdqu32(Ymm(16) | k6, ptr[rax]);
    vmovdqu32(Ymm(17) | k7, ptr[rax]);

    vmovdqu32(Zmm(21) | k1, ptr[rax]);
    vmovdqu32(Zmm(22) | k2, ptr[rax]);
    vmovdqu32(Zmm(23) | k3, ptr[rax]);
    vmovdqu32(Zmm(24) | k4, ptr[rax]);
    vmovdqu32(Zmm(25) | k5, ptr[rax]);
    vmovdqu32(Zmm(26) | k6, ptr[rax]);
    vmovdqu32(Zmm(27) | k7, ptr[rax]);

    mov(rax, 5);
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
