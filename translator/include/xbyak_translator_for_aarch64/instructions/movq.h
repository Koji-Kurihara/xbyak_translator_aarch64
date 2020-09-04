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
void translateMOVQ(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/21 21:51 */

  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=W103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ptrue(xa::PRegD(a64.pTmpIdx), xa::VL1);
  }
  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ptrue(xa::PRegD(a64.pTmpIdx), xa::VL2);
  }

  /* Col=AI103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AK103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, 0);
  }
  /* Col=AL103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_XMM && true)) {
    xa_->mov(xa::XReg(a64.dstIdx), xa::VReg2D(a64.srcIdx)[0]);
  }
  /* Col=AM103*/
  if (false ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->ptrue(xa::PRegD(a64.pTmpIdx), xa::VL1);
  }

  /* Col=AQ103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_XMM && true)) {
    xa_->st1(xa::VReg2D(a64.srcIdx)[0], xa::ptr(X_TMP_ADDR));
  }

  /* Col=AS103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true)) {
    xa_->mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
              xa::XReg(a64.srcIdx));
  }

  /* Col=AU103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xa_->mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, X_TMP_0);
  }

  /* Col=AW103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_MMX && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_GPR && true) ||
      (a64.dstWidth == 128 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && a64.srcWidth == 64 &&
       a64.srcRegClass == XED_REG_CLASS_INVALID && true)) {
    xt_pop_preg();
  }


}
