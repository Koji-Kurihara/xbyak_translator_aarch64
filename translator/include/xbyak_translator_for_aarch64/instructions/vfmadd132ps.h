/* 2020/04/02 14:38 */
#define CG64 CodeGeneratorAArch64
void translateVFMADD132PS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

  bool isValid = false;
  xt_reg_idx_t dstIdx;
  xt_reg_idx_t srcIdx;
  xt_reg_idx_t src2Idx;
  xt_reg_idx_t maskIdx;
  xt_reg_idx_t zTmpIdx;
  xt_reg_idx_t pTmpIdx;
  /* Col=T103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 1 && true)) {
    XT_UNIMPLEMENTED;
  }

  /* Col=V103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    maskIdx = a64.operands[1].regIdx;
  }
  /* Col=W103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    zTmpIdx = xt_push_zreg(&a64);
  }
  /* Col=X103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    pTmpIdx = xt_push_preg(&a64);
  }

  /* Col=Z103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
                a64.operands[0].opWidth == 512 &&
                a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::not_(P_TMP_0.b, P_ALL_ONE.b, xa::PRegB(maskIdx));
  }
  /* Col=AA103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 &&
                a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_256.b, xa::PReg(maskIdx).b);
  }
  /* Col=AB103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::orn(P_TMP_0.b, P_ALL_ONE / xa::T_z, P_MSB_384.b, xa::PReg(maskIdx).b);
  }

  /* Col=AD103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::not_(P_TMP_1.b, P_ALL_ONE.b, P_MSB_256.b);
  }
  /* Col=AE103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::not_(P_TMP_1.b, P_ALL_ONE.b, P_MSB_384.b);
  }

  /* Col=AG103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    dstIdx = a64.operands[0].regIdx;
  }
  /* Col=AH103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[1].regIdx;
  }
  /* Col=AI103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    srcIdx = a64.operands[2].regIdx;
  }
  /* Col=AJ103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[2].regIdx;
  }
  /* Col=AK103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    src2Idx = a64.operands[3].regIdx;
  }

  /* Col=AM103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
                a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    ldr(xa::ZReg(zTmpIdx), xa::ptr(X_TMP_ADDR));
  }
  /* Col=AN103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    ld1w(xa::ZReg(zTmpIdx).s, P_TMP_1 / xa::T_z, xa::ptr(X_TMP_ADDR));
  }

  /* Col=AP103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::mov(xa::PReg(pTmpIdx).b, P_ALL_ONE.b);
  }
  /* Col=AQ103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
               xa::ZRegS(src2Idx), xa::ZRegS(srcIdx));
  }
  /* Col=AR103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(pTmpIdx) / xa::T_m,
               xa::ZRegS(zTmpIdx), xa::ZRegS(srcIdx));
  }
  /* Col=AS103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
               xa::ZRegS(src2Idx), xa::ZRegS(srcIdx));
  }
  /* Col=AT103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_MEM0 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_MERG && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::fmad(xa::ZRegS(dstIdx), xa::PReg(maskIdx) / xa::T_m,
               xa::ZRegS(zTmpIdx), xa::ZRegS(srcIdx));
  }

  /* Col=AV103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_YMM &&
                a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_256 / xa::T_m, 0);
  }
  /* Col=AW103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_MSB_384 / xa::T_m, 0);
  }
  /* Col=AX103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_REG3 &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 &&
                a64.predType == A64_PRED_ZERO && a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true)) {
    CG64::mov(xa::ZRegS(dstIdx), P_TMP_0 / xa::T_m, 0);
  }

  /* Col=AZ103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_REG2 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_REG3 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xt_pop_preg();
  }
  /* Col=BA103*/
  if (false || (a64.operands[2].opName == XED_OPERAND_MEM0 &&
                a64.operands[3].opName == XED_OPERAND_INVALID &&
                a64.operands[0].regClass == XED_REG_CLASS_XMM &&
                a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
                a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_MEM0 &&
       a64.operands[3].opName == XED_OPERAND_INVALID &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_XMM &&
       a64.operands[0].opWidth == 128 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_YMM &&
       a64.operands[0].opWidth == 256 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_NO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_ZERO &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true) ||
      (a64.operands[2].opName == XED_OPERAND_REG2 &&
       a64.operands[3].opName == XED_OPERAND_MEM0 &&
       a64.operands[0].regClass == XED_REG_CLASS_ZMM &&
       a64.operands[0].opWidth == 512 && a64.predType == A64_PRED_MERG &&
       a64.EVEXb == 0 && true)) {
    xt_pop_zreg();
  }

>>>>>>> 3_implement_translation_higuchi
  #undef CG64
}
