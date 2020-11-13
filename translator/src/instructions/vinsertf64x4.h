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
void translateVINSERTF64X4(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/03/12 14:19 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_ZERO &&
       a64.src2Type == A64_OP_MEM && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_MERG &&
       a64.src2Type == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=U103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_MEM && true)) {
    a64.zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=V103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_MEM && true)) {
    a64.pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=Z103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_MEM && true)) {
    xa_->ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
  }

  /* Col=AC103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_MEM && true)) {
    xa_->ptrue(xa::PRegD(a64.pTmpIdx), xa::VL4);
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x1) == 0) {
      xa_->sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
               xa::ZRegD(a64.src2Idx), xa::ZRegD(a64.srcIdx));
    }
  }

  /* Col=AH103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_MEM && true)) {
    if ((a64.uimm & 0x1) == 0) {
      xa_->sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
               xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
    }
  }
  /* Col=AI103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_MEM && true)) {
    if ((a64.uimm & 0x1) == 1) {
      xa_->ext(xa::ZRegB(a64.zTmpIdx), xa::ZRegB(a64.zTmpIdx), 32);
    }
  }

  /* Col=AK103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x1) == 1) {
      xa_->mov(xa::ZRegD(a64.zTmpIdx), xa::ZRegD(a64.srcIdx));
    }
  }

  /* Col=AM103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x1) == 1) {
      xa_->splice(xa::ZRegD(a64.zTmpIdx), xa::PRegD(a64.pTmpIdx),
                  xa::ZRegD(a64.src2Idx));
    }
  }

  /* Col=AS103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_REG && true)) {
    if ((a64.uimm & 0x1) == 1) {
      xa_->mov(xa::ZReg(a64.dstIdx).d, xa::ZReg(a64.zTmpIdx).d);
    }
  }

  /* Col=AV103*/
  if (false || (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
                a64.src2Type == A64_OP_MEM && true)) {
    if ((a64.uimm & 0x1) == 1) {
      xa_->sel(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx),
               xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.zTmpIdx));
    }
  }

  /* Col=BB103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_MEM && true)) {
    xt_pop_preg();
  }
  /* Col=BC103*/
  if (false ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_REG && true) ||
      (a64.dstWidth == 512 && a64.PredType == A64_PRED_NO &&
       a64.src2Type == A64_OP_MEM && true)) {
    xt_pop_zreg();
  }
}
