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
void Xbyak::CodeGenerator::translateVMOVUPS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/09/18 16:47 */

  /* Col=T103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->not_(P_TMP_0.b, P_ALL_ONE / xa::T_z, xa::PRegB(a64.maskIdx));
  }

  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b);
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->bic(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z,
             xa::PRegB(a64.maskIdx), P_MSB_256.b);
  }
  /* Col=Z103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->bic(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z,
             xa::PRegB(a64.maskIdx), P_MSB_384.b);
  }
  /* Col=AA103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b,
             xa::PRegB(a64.maskIdx));
  }
  /* Col=AB103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b,
             xa::PRegB(a64.maskIdx));
  }
  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(xa::QReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AD103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(xa::ZReg(a64.dstIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AE103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ld1w(xa::ZRegS(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AF103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ld1w(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.maskIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AG103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ld1w(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AH103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->ld1w(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AI103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->str(xa::ZReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AJ103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->st1w(xa::ZRegS(a64.srcIdx), xa::PReg(a64.maskIdx),
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AK103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->st1w(xa::ZRegS(a64.srcIdx), xa::PReg(a64.pTmpIdx),
              xa::ptr(X_TMP_ADDR));
  }
  /* Col=AL103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xa_->str(xa::QReg(a64.srcIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AM103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx));
  }
  /* Col=AN103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_m,
             xa::ZRegS(a64.srcIdx));
  }
  /* Col=AO103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx));
  }
  /* Col=AP103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.maskIdx) / xa::T_m,
             xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AQ103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m,
             xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AR103*/
  if (false ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AS103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AT103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_REG && true)) {
    xa_->mov(xa::ZRegS(a64.dstIdx), P_TMP_0 / xa::T_m, 0);
  }

  /* Col=AY103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
  /* Col=AZ103*/
  if (false ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_REG && a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 128 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_NO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_ZERO &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 256 && a64.PredType == A64_PRED_MERG &&
       a64.dstType == A64_OP_MEM && a64.srcType == A64_OP_REG && true)) {
    xt_pop_preg();
  }
}
