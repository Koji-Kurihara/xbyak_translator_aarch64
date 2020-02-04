void translateVZEROUPPER(xed_decoded_inst_t *p) {

  xed_uint_t machineMode = xed_decoded_inst_get_machine_mode_bits(p);

  unsigned int limit;

  if (false || (machineMode == 64)) {
    limit = 15;
  }
  if (false || (machineMode == 32) || (machineMode == 16)) {
    limit = 7;
  }

  Xbyak_aarch64::PReg pTmp = xt_push_preg();
  mov__(pTmp.b, p14.b);
  for (int i = 0; i <= limit; i++) {
    mov__(Xbyak_aarch64::ZReg(i).s, pTmp / Xbyak_aarch64::T_m, 0);
  }
  xt_pop_preg();
}
