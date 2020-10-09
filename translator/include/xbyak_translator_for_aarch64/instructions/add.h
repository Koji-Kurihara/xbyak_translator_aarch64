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
void translateADD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

  /* 2020/02/14 19:44 */
  /* Col=S103*/
  if (false ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 8 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true) ||
      (a64.dstWidth == 16 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    XT_UNIMPLEMENTED;
  }
  /* Col=T103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    adds_imm(Xbyak_aarch64::WReg(a64.dstIdx), Xbyak_aarch64::WReg(a64.dstIdx),
             static_cast<uint32_t>(a64.uimm), W_TMP_0);
  }
  /* Col=U103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_IMM && true)) {
    adds_imm(Xbyak_aarch64::XReg(a64.dstIdx), Xbyak_aarch64::XReg(a64.dstIdx),
             a64.uimm, X_TMP_0);
  }

  /* Col=X103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=Y103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
       a64.srcType == A64_OP_MEM && true)) {
    xa_->ldr(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AB103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true)) {
    if (std::numeric_limits<uint32_t>::max() < a64.uimm &&
        a64.uimm < ~uint64_t(0xFFFFFFFF)) {
      xt_msg_err(__FILE__, __LINE__,
                 "Invalid uimm=" + std::to_string(a64.uimm));
    }
    xa_->adds_imm(W_TMP_0, W_TMP_0, static_cast<uint32_t>(a64.uimm), W_TMP_1);
  }
  /* Col=AC103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_IMM && true)) {
    xa_->adds_imm(X_TMP_0, X_TMP_0, a64.uimm, X_TMP_1);
  }

  /* Col=AF103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->adds(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx), xa::WReg(a64.srcIdx));
  }
  /* Col=AG103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->adds(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), xa::XReg(a64.srcIdx));
  }

  /* Col=AK103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->adds(W_TMP_0, W_TMP_0, xa::WReg(a64.srcIdx));
  }
  /* Col=AL103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
                a64.srcType == A64_OP_REG && true)) {
    xa_->adds(X_TMP_0, X_TMP_0, xa::XReg(a64.srcIdx));
  }

  /* Col=AR103*/
  if (false || (a64.dstWidth == 32 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xa_->adds(xa::WReg(a64.dstIdx), xa::WReg(a64.dstIdx), W_TMP_0);
  }
  /* Col=AS103*/
  if (false || (a64.dstWidth == 64 && a64.dstType == A64_OP_REG &&
                a64.srcType == A64_OP_MEM && true)) {
    xa_->adds(xa::XReg(a64.dstIdx), xa::XReg(a64.dstIdx), X_TMP_0);
  }

  /* Col=AU103*/
  if (false ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 32 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    xa_->str(W_TMP_0, xa::ptr(X_TMP_ADDR));
  }
  /* Col=AV103*/
  if (false ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_IMM && true) ||
      (a64.dstWidth == 64 && a64.dstType == A64_OP_MEM &&
       a64.srcType == A64_OP_REG && true)) {
    xa_->str(X_TMP_0, xa::ptr(X_TMP_ADDR));
  }
}
