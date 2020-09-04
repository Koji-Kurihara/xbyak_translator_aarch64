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
/* 2020/07/02 15:32 */

void translateVPERMW(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64_opt;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64_opt, false, true);
  xt_construct_a64fx_operandsV3(p, &a64);
  bool isValid = false;
  xt_reg_idx_t dstIdx = XT_REG_INVALID;
  xt_reg_idx_t srcIdx = XT_REG_INVALID;
  xt_reg_idx_t src2Idx = XT_REG_INVALID;
  xt_reg_idx_t maskIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmpIdx = XT_REG_INVALID;
  xt_reg_idx_t zTmp2Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmp3Idx = XT_REG_INVALID;
  xt_reg_idx_t zTmp4Idx = XT_REG_INVALID;
  xt_reg_idx_t pTmpIdx = XT_REG_INVALID;

  /* Col=AD119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=AE119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=AF119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=AG119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    zTmp4Idx = xt_push_zreg(&a64);
  }
  /* Col=AH119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AJ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AL119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AM119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    src2Idx = zTmp4Idx;
  }
  /* Col=AN119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AQ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->ldr(xa::QReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AS119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->ldr(xa::ZReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AU119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 7);
  }
  /* Col=AV119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 15);
  }
  /* Col=AW119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 31);
  }
  /* Col=AX119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->and_(xa::ZRegB(zTmpIdx), P_ALL_ONE_0_7, xa::ZRegB(srcIdx));
  }
  /* Col=AZ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    for (int i = 0; i < 8; i++) {
      xa_->cmpeq(P_TMP_0.h, P_ALL_ONE_0_7, xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=BA119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    for (int i = 0; i < 16; i++) {
      xa_->cmpeq(P_TMP_0.h, P_ALL_ONE_0_7, xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=BB119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->sub(xa::ZRegH(zTmpIdx), 16);
  }
  /* Col=BC119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    for (int i = 0; i < 16; i++) {
      xa_->cmpeq(P_TMP_0.h, P_ALL_ONE_0_7, xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[16 + i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=BD119*/
  if (false || (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[0].opWidth == 128 &&
                a64_opt.predType == A64_PRED_ZERO &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b, xa::PRegB(maskIdx));
  }
  /* Col=BG119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=BH119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), 0);
  }
  /* Col=BI119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegH(zTmp3Idx));
  }
  /* Col=BJ119*/
  if (false || (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
                a64_opt.operands[0].opWidth == 128 &&
                a64_opt.predType == A64_PRED_ZERO &&
                isAvailAll1Preg0_7() == true && true)) {
    xa_->mov(xa::ZRegH(dstIdx), P_TMP_0 / xa::T_m, 0);
  }
  /* Col=BK119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BL119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BO119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BP119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BR119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BY119*/
  if (false ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 128 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 256 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_REG3 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 && a64_opt.predType == A64_PRED_NO &&
       isAvailAll1Preg0_7() == true && true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_ZERO && isAvailAll1Preg0_7() == true &&
       true) ||
      (a64_opt.operands[3].opName == XED_OPERAND_MEM0 &&
       a64_opt.operands[0].opWidth == 512 &&
       a64_opt.predType == A64_PRED_MERG && isAvailAll1Preg0_7() == true &&
       true)) {
    return;
  }
  /* Col=U119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=W119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp2Idx = xt_push_zreg(&a64);
  }
  /* Col=X119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp3Idx = xt_push_zreg(&a64);
  }
  /* Col=Y119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    zTmp4Idx = xt_push_zreg(&a64);
  }
  /* Col=Z119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AB119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AD119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    src2Idx = a64.operands[3].regIdx;
  }
  /* Col=AE119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    src2Idx = zTmp4Idx;
  }
  /* Col=AF119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=AH119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->not_(xa::PRegB(pTmpIdx), P_ALL_ONE, P_MSB_256.b);
  }
  /* Col=AI119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ldr(xa::QReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AJ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ld1h(xa::ZRegH(zTmp4Idx), xa::PReg(pTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->ldr(xa::ZReg(zTmp4Idx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::PRegB(pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=AM119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 7);
  }
  /* Col=AN119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 15);
  }
  /* Col=AO119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(zTmpIdx), 31);
  }
  /* Col=AP119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->and_(xa::ZRegB(zTmpIdx), xa::PReg(pTmpIdx), xa::ZRegB(srcIdx));
  }
  /* Col=AR119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 8; i++) {
      xa_->cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=AS119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 16; i++) {
      xa_->cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=AT119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->sub(xa::ZRegH(zTmpIdx), 16);
  }
  /* Col=AU119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    for (int i = 0; i < 16; i++) {
      xa_->cmpeq(P_TMP_0.h, xa::PReg(pTmpIdx), xa::ZRegH(zTmpIdx), i);
      xa_->dup(xa::ZRegH(zTmp2Idx), xa::ZRegH(src2Idx)[16 + i]);
      xa_->mov(xa::ZRegH(zTmp3Idx), P_TMP_0 / xa::T_m, xa::ZRegH(zTmp2Idx));
    }
  }
  /* Col=AV119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
              xa::PRegB(maskIdx));
  }
  /* Col=AW119*/
  if (false || (a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].opWidth == 256 &&
                a64.predType == A64_PRED_ZERO && true)) {
    xa_->orn(xa::PRegB(pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
              xa::PRegB(maskIdx));
  }
  /* Col=AY119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true)) {
    xa_->mov(xa::ZRegD(dstIdx), xa::ZRegD(zTmp3Idx));
  }
  /* Col=AZ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), 0);
  }
  /* Col=BA119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), xa::PReg(maskIdx) / xa::T_m,
              xa::ZRegH(zTmp3Idx));
  }
  /* Col=BB119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), xa::PReg(pTmpIdx) / xa::T_m, 0);
  }
  /* Col=BC119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=BD119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true)) {
    xa_->mov(xa::ZRegH(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=BG119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BH119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BI119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BJ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_zreg();
  }
  /* Col=BK119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    xt_pop_preg();
  }
  /* Col=BQ119*/
  if (false ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO && true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       true) ||
      (a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       true)) {
    XT_VALID_CHECK;
  }
  XT_VALID_CHECK_IF;
}

