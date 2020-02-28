void translateVFMADD231PS(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_structV3_t a64;
  xt_construct_a64fx_operandsV3(p, &a64);

/* 2020/02/27 15:43 */
#define CG64 CodeGeneratorAArch64
xt_reg_idx_t dstIdx;
xt_reg_idx_t srcIdx;
xt_reg_idx_t src2Idx;
xt_reg_idx_t maskIdx;
xt_reg_idx_t zTmpIdx;
/* Col=T103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_ZERO&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_MERG&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_MEM0&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_MERG&&a64.EVEXb==1&&true)) {
  XT_UNIMPLEMENTED;
}
/* Col=U103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  maskIdx = xt_push_preg(&a64);
}


/* Col=X103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::mov(xa::PRegB(maskIdx), P_ALL_ONE.b);
}





/* Col=AD103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  dstIdx = a64.operands[0].regIdx;
}

/* Col=AF103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  srcIdx = a64.operands[1].regIdx;
}
/* Col=AG103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  srcIdx = a64.operands[2].regIdx;
}
/* Col=AH103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  src2Idx = a64.operands[2].regIdx;
}
/* Col=AI103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  src2Idx = a64.operands[3].regIdx;
}













/* Col=AW103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_MEM0&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==128&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::fmla(xa::VReg4S(dstIdx), xa::VReg4S(srcIdx), xa::VReg4S(src2Idx));
}
/* Col=AX103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::fmla(xa::ZRegS(dstIdx), xa::PReg(maskIdx)/xa::T_m, xa::ZRegS(srcIdx), xa::ZRegS(src2Idx));
}



/* Col=BB103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  CG64::mov(xa::ZRegS(dstIdx), P_MSB_256/xa::T_m, 0);
}







/* Col=BJ103*/
if(false ||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_INVALID&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==256&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)||(a64.operands[2].opName==XED_OPERAND_REG2&&a64.operands[3].opName==XED_OPERAND_REG3&&a64.operands[0].opWidth==512&&a64.predType==A64_PRED_NO&&a64.EVEXb==0&&true)) {
  xt_pop_preg();
}







#undef CG64
}
