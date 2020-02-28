void translateVUNPCKHPD(xed_decoded_inst_t *p) {
  namespace xa = Xbyak_aarch64;
  struct xt_a64fx_operands_struct_t a64;
  xt_construct_a64fx_operands(p, &a64);

/* 2020/02/27 16:28 */
#define CG64 CodeGeneratorAArch64
/* Col=S103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_MERG&&a64.EVEXb==1&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  XT_UNIMPLEMENTED;
}
/* Col=T103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.pTmpIdx = xt_push_preg(&a64);
}
/* Col=U103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  a64.zTmpIdx = xt_push_zreg(&a64);
}





/* Col=AA103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
  CodeGeneratorAArch64::orn(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_384.b, xa::PRegB(a64.maskIdx));
}


/* Col=AD103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_384.b);
}

/* Col=AF103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::not_(xa::PRegB(a64.pTmpIdx), P_ALL_ONE/xa::T_z, P_MSB_256.b);
}



/* Col=AJ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ld1d(xa::ZRegD(a64.zTmpIdx), xa::PReg(a64.pTmpIdx)/xa::T_z, xa::ptr(X_TMP_ADDR));
}

/* Col=AL103*/
if(false ||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CodeGeneratorAArch64::ldr(xa::ZReg(a64.zTmpIdx), xa::ptr(X_TMP_ADDR));
}




/* Col=AQ103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
  CG64::trn2(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.src2Idx));
}
/* Col=AR103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CG64::trn2(xa::ZRegD(a64.dstIdx), xa::ZRegD(a64.srcIdx), xa::ZRegD(a64.zTmpIdx));
}




/* Col=AW103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CG64::mov(xa::ZRegS(a64.dstIdx), P_MSB_384/xa::T_m, 0);
}
/* Col=AX103*/
if(false ||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  CG64::mov(xa::ZRegS(a64.dstIdx), P_MSB_256/xa::T_m, 0);
}
/* Col=AY103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)) {
  CG64::mov(xa::ZRegD(a64.dstIdx), xa::PReg(a64.pTmpIdx)/xa::T_m, 0);
}














/* Col=BN103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==512&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_zreg();
}
/* Col=BO103*/
if(false ||(a64.dstWidth==128&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)||(a64.dstWidth==128&&a64.PredType==A64_PRED_ZERO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_REG&&true)||(a64.dstWidth==256&&a64.PredType==A64_PRED_NO&&a64.EVEXb==0&&a64.dstType==A64_OP_REG&&a64.srcType==A64_OP_REG&&a64.src2Type==A64_OP_MEM&&true)) {
  xt_pop_preg();
}

#undef CG64
}
