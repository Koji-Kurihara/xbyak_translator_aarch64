void translateMOVQ(xed_decoded_inst_t *p) {
  // unsigned int i, noperands, dstIdx, srcIdx;
  const xed_inst_t *xi = xed_decoded_inst_inst(p);

  const xed_operand_t *op1 =
      xed_inst_operand(xi, 0); // dstのオペランドのポインタを取得
  const xed_operand_t *op2 =
      xed_inst_operand(xi, 1); // dstのオペランドのポインタを取得
  xed_operand_enum_t isDst =
      xed_operand_name(op1); // dstのオペランドの名前を取得
  xed_operand_enum_t isSrc =
      xed_operand_name(op2); // srcのオペランドの名前を取得

  xed_uint_t isDstSize = xed_decoded_inst_operand_length_bits(p, 0);
  xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

  const xed_reg_class_enum_t DstRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
  const xed_reg_class_enum_t SrcRegClass =
      xed_reg_class(xed_decoded_inst_get_reg(p, isSrc));

  unsigned int a64_dstIdx;
  unsigned int a64_srcIdx;

  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_MMX &&
       SrcRegClass == XED_REG_CLASS_GPR)) {
    fmov__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
           Xbyak_aarch64::XReg(a64_srcIdx));
  }
  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_MEM0 && DstRegClass == XED_REG_CLASS_MMX &&
       SrcRegClass == XED_OPERAND_MEM0)) {
    ld1__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_GPR &&
       SrcRegClass == XED_REG_CLASS_MMX) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_GPR &&
       SrcRegClass == XED_REG_CLASS_XMM) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_GPR &&
       SrcRegClass == XED_REG_CLASS_XMM)) {
    fmov__(Xbyak_aarch64::XReg(a64_dstIdx),
           Xbyak_aarch64::VReg(a64_srcIdx).d2[0]);
  }
  if (false ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_MMX) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_XMM) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_XMM) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_MMX) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_XMM) ||
      (isDstSize == 64 && isSrcSize == 64 && isDst == XED_OPERAND_MEM0 &&
       isSrc == XED_OPERAND_REG0 && DstRegClass == XED_REG_CLASS_INVALID &&
       SrcRegClass == XED_REG_CLASS_XMM)) {
    st1__(Xbyak_aarch64::VReg(a64_srcIdx).d2[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
  }
  if (false ||
      (isDstSize == 128 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_XMM &&
       SrcRegClass == XED_REG_CLASS_GPR)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
    fmov__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
           Xbyak_aarch64::XReg(a64_srcIdx));
    xt_pop_preg();
  }
  if (false ||
      (isDstSize == 128 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_MEM0 && DstRegClass == XED_REG_CLASS_XMM &&
       SrcRegClass == XED_REG_CLASS_INVALID)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p12.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
    ld1__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
  if (false ||
      (isDstSize == 128 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_REG1 && DstRegClass == XED_REG_CLASS_XMM &&
       SrcRegClass == XED_REG_CLASS_GPR)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
    mov__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
          Xbyak_aarch64::VReg(a64_srcIdx).d2[0]);
    xt_pop_preg();
  }
  if (false ||
      (isDstSize == 128 && isSrcSize == 64 && isDst == XED_OPERAND_REG0 &&
       isSrc == XED_OPERAND_MEM0 && DstRegClass == XED_REG_CLASS_XMM &&
       SrcRegClass == XED_REG_CLASS_INVALID)) {
    Xbyak_aarch64::PReg pTmp = xt_push_preg();
    mov__(pTmp.b, p15.b);
    mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
    ld1__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
          Xbyak_aarch64::ptr(X_TMP_ADDR));
    xt_pop_preg();
  }
}
