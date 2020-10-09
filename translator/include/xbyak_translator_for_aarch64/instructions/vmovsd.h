/*******************************************************************************
 * Copyright 2020 FUJITSU LIMITED
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/
void translateVMOVSD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/03/10 22:22 */

  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=U103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=W103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=Y103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=Z103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AA103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AB103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AC103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && true)) {
    srcIdx = a64.operands[3].regIdx;
  }

  /* Col=AE103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AF103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->ptrue(P_TMP_0.d, xa::VL1);
  }
  /* Col=AG103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->ptrue(xa::PReg(pTmpIdx).d, xa::VL1);
  }
  /* Col=AH103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, xa::PRegB(pTmpIdx));
  }
  /* Col=AI103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx),
               xa::PRegB(pTmpIdx));
  }
  /* Col=AJ103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(xa::PRegB(pTmpIdx), P_ALL_ONE, xa::PRegB(maskIdx),
               xa::PRegB(pTmpIdx));
  }
  /* Col=AK103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->and_(P_TMP_0.b, P_ALL_ONE, xa::PRegB(maskIdx), P_TMP_0.b);
  }

  /* Col=AM103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE, P_TMP_0.b);
  }

  /* Col=AO103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_ZERO && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE, P_MSB_384.b, xa::PRegB(maskIdx));
  }
  /* Col=AP103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_ZERO && true)) {
    xa_->ld1d(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AQ103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->ld1d(xa::ZRegD(zTmpIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AR103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    xa_->ld1(xa::VReg2D(dstIdx)[0], xa::ptr(X_TMP_ADDR));
  }
  /* Col=AS103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true)) {
    xa_->st1(xa::VReg2D(srcIdx)[0], xa::ptr(X_TMP_ADDR));
  }
  /* Col=AT103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->st1d(xa::ZRegD(srcIdx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_NO && true)) {
    xa_->sel(xa::ZRegD(dstIdx), P_TMP_0, xa::ZRegD(srcIdx),
              xa::ZRegD(src2Idx));
  }
  /* Col=AV103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_XMM &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::VReg2D(dstIdx)[1], xa::VReg2D(srcIdx)[1]);
  }
  /* Col=AW103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true)) {
    xa_->mov(xa::VReg2D(dstIdx)[0], xa::VReg2D(src2Idx)[0]);
  }

  /* Col=AX103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_XMM &&
                a64.operands[3].regClass == XED_REG_CLASS_XMM &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, xa::ZRegD(src2Idx));
  }
  /* Col=AY103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true)) {
    xa_->mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=AZ103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->mov(xa::ZRegD(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BA103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->mov(xa::ZRegD(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=BB103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
              xa::ZRegD(zTmpIdx));
  }
  /* Col=BC103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true)) {
    xa_->mov(xa::VReg2D(dstIdx)[1], xa::VReg2D(srcIdx)[1]);
  }
  /* Col=BD103*/
  if (false || (a64.operands[0].opName == XED_OPERAND_REG0 &&
                a64.operands[1].opName == XED_OPERAND_REG1 &&
                a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[1].regClass == XED_REG_CLASS_MASK &&
                a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
                a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
                a64.predType == A64_PRED_MERG && true)) {
    xt_pop_zreg();
  }
  /* Col=BE103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    xt_pop_preg();
  }
  /* Col=BF103*/
  if (false ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_MEM0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_INVALID &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_XMM &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_REG0 &&
       a64.operands[1].opName == XED_OPERAND_REG1 &&
       a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_XMM &&
       a64.predType == A64_PRED_MERG && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_NO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_ZERO && true) ||
      (a64.operands[0].opName == XED_OPERAND_MEM0 &&
       a64.operands[1].opName == XED_OPERAND_REG0 &&
       a64.operands[2].opName == XED_OPERAND_REG1 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_INVALID &&
       a64.operands[1].regClass == XED_REG_CLASS_MASK &&
       a64.operands[2].regClass == XED_REG_CLASS_XMM &&
       a64.operands[3].regClass == XED_REG_CLASS_INVALID &&
       a64.predType == A64_PRED_MERG && true)) {
    XT_VALID_CHECK;
  }

  XT_VALID_CHECK_IF;

}
