void translateVMOVD(xed_decoded_inst_t *p) {
    //unsigned int i, noperands, dstIdx, srcIdx;
    const xed_inst_t *xi = xed_decoded_inst_inst(p);

    const xed_operand_t *op1
            = xed_inst_operand(xi, 0); // get dst operand pointer
    const xed_operand_t *op2
            = xed_inst_operand(xi, 1); // get src operand pointer
    xed_operand_enum_t isDst
            = xed_operand_name(op1); // get dst operand name
    xed_operand_enum_t isSrc
            = xed_operand_name(op2); // get src operand name

	xed_uint_t isDstSize = xed_decoded_inst_operand_length_bits(p, 0);
    xed_uint_t isSrcSize = xed_decoded_inst_operand_length_bits(p, 1);

	/*
	const xed_reg_class_enum_t DstRegClass
            = xed_reg_class(xed_decoded_inst_get_reg(p, isDst));
    const xed_reg_class_enum_t SrcRegClass
            = xed_reg_class(xed_decoded_inst_get_reg(p, isSrc));
			*/

	unsigned int a64_dstIdx;
    unsigned int a64_srcIdx;
	
	if (false
            || (isDstSize == 128 && isSrcSize == 32 && isDst == XED_OPERAND_REG0
                    && isSrc == XED_OPERAND_REG1)) {
        Xbyak_aarch64::PReg pTmp = xt_push_preg();
        mov__(pTmp.b, p15.b);
        mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
        lsl__(Xbyak_aarch64::XReg(a64_dstIdx), Xbyak_aarch64::XReg(a64_dstIdx),
                32);
        lsr(Xbyak_aarch64::XReg(a64_dstIdx), Xbyak_aarch64::XReg(a64_dstIdx),
                32);
        fmov__(Xbyak_aarch64::VReg(a64_dstIdx).d2[0],
                Xbyak_aarch64::XReg(a64_dstIdx));
        xt_pop_preg();
    }
    if (false
            || (isDstSize == 128 && isSrcSize == 32 && isDst == XED_OPERAND_REG0
                    && isSrc == XED_OPERAND_MEM0)) {
        Xbyak_aarch64::PReg pTmp = xt_push_preg();
        mov__(pTmp.b, p15.b);
        mov__(Xbyak_aarch64::ZReg(a64_dstIdx).d, pTmp / Xbyak_aarch64::T_m, 0);
        ld1__(Xbyak_aarch64::VReg(a64_dstIdx).s4[0],
                Xbyak_aarch64::ptr(X_TMP_ADDR));
        xt_pop_preg();
    }
    if (false
            || (isDstSize == 32 && isSrcSize == 32 && isDst == XED_OPERAND_REG0
                    && isSrc == XED_OPERAND_REG1)) {
        fmov__(Xbyak_aarch64::XReg(a64_dstIdx),
                Xbyak_aarch64::VReg(a64_dstIdx).d2[0]);
        lsl__(Xbyak_aarch64::XReg(a64_dstIdx), Xbyak_aarch64::XReg(a64_dstIdx),
                32);
        lsr(Xbyak_aarch64::XReg(a64_dstIdx), Xbyak_aarch64::XReg(a64_dstIdx),
                32);
    }
    if (false
            || (isDstSize == 32 && isSrcSize == 32 && isDst == XED_OPERAND_MEM0
                    && isSrc == XED_OPERAND_REG0)) {
        st1__(Xbyak_aarch64::VReg(a64_srcIdx).s4[0],
                Xbyak_aarch64::ptr(X_TMP_ADDR));
    }



}
