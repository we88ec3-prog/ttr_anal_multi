
void FUN_00754640(void)

{
  int *unaff_ESI;
  int *piStack_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  int iStack_14;
  uint uStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_20;
  piStack_24 = &local_1c;
  (**(code **)(*unaff_ESI + 0x17c))();
  if ((iStack_18 - iStack_20 <= unaff_ESI[0x2b] - unaff_ESI[0x29]) &&
     (iStack_14 - local_1c <= unaff_ESI[0x2c] - unaff_ESI[0x2a])) {
    __security_check_cookie(uStack_10 ^ (uint)&piStack_24);
    return;
  }
  __security_check_cookie(uStack_10 ^ (uint)&piStack_24);
  return;
}

