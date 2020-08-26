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
void translateVPCMPEQB(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/04/03 14:00 */
#define CG64 Xbyak_aarch64::CodeGenerator
  /* Col=N103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=O103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    a64.vTmpIdx = xt_push_vreg(&a64);
  }
  /* Col=P103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=Q103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::ld1(xa::VReg4S(a64.vTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=S103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=T103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::ld1rw(xa::ZRegS(a64.zTmpIdx), xa::PReg(a64.mask2Idx) / xa::T_z,
                xa::ptr(X_TMP_ADDR));
  }
  /* Col=U103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::mov(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b);
  }
  /* Col=W103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::mov(xa::PRegB(a64.pTmpIdx), xa::PRegB(a64.mask2Idx));
  }
  /* Col=X103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b, P_MSB_256.b);
  }
  /* Col=Y103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE.b, P_MSB_384.b);
  }
  /* Col=Z103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_256.b,
              xa::PRegB(a64.mask2Idx));
  }
  /* Col=AA103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE / xa::T_z, P_MSB_384.b,
              xa::PRegB(a64.mask2Idx));
  }
  /* Col=AB103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0)) {
    CG64::cmeq(xa::VReg16B(a64.dstIdx), xa::VReg16B(a64.srcIdx),
               xa::VReg16B(a64.src2Idx));
  }
  /* Col=AC103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::cmeq(xa::VReg4S(a64.dstIdx), xa::VReg4S(a64.srcIdx),
               xa::VReg4S(a64.vTmpIdx));
  }
  /* Col=AD103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0)) {
    CG64::cmpeq(xa::PRegS(a64.pTmpIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
                xa::ZRegS(a64.srcIdx), xa::ZRegS(a64.src2Idx));
  }
  /* Col=AE103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::cmpeq(xa::PRegS(a64.pTmpIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
                xa::ZRegS(a64.srcIdx), xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AF103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0)) {
    CG64::cmpeq(xa::PRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
                xa::ZRegS(a64.srcIdx), xa::ZRegS(a64.src2Idx));
  }
  /* Col=AG103*/
  if (false ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    CG64::cmpeq(xa::PRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_z,
                xa::ZRegS(a64.srcIdx), xa::ZRegS(a64.zTmpIdx));
  }
  /* Col=AH103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::mov(xa::ZRegD(a64.dstIdx), 0x0); // 全ビット0埋め
  }
  /* Col=AI103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::orn(W_TMP_0, W_TMP_0, W_TMP_0); // 全ビット1埋め
  }
  /* Col=AJ103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    CG64::mov(xa::ZRegS(a64.dstIdx), xa::PReg(a64.pTmpIdx) / xa::T_m, W_TMP_0);
  }
  /* Col=AK103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0)) {
    xt_pop_vreg();
  }
  /* Col=AL103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    xt_pop_zreg();
  }
  /* Col=AM103*/
  if (false ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == false && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 128 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 256 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_NO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_REG && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 0) ||
      (a64.isDstMask == true && a64.PredType == A64_PRED_ZERO &&
       a64.srcWidth == 512 && a64.src2Type == A64_OP_MEM && a64.EVEXb == 1)) {
    xt_pop_preg();
  }
}
