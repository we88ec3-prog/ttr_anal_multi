
void FUN_00754510(void)

{
  int *unaff_ESI;
  int iStack_34;
  int iStack_30;
  int *piStack_2c;
  uint uStack_20;
  int local_1c;
  int iStack_18;
  int iStack_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&uStack_20;
  piStack_2c = &local_1c;
  iStack_30 = 0x754537;
  (**(code **)(*unaff_ESI + 0x17c))();
  iStack_30 = ((unaff_ESI[0x30] + unaff_ESI[0x2e]) - local_1c) + unaff_ESI[3] + unaff_ESI[0x31] * 2
              + iStack_14;
  iStack_34 = ((unaff_ESI[0x2f] + unaff_ESI[0x2d]) - uStack_20) + unaff_ESI[0x31] * 2 + unaff_ESI[2]
              + iStack_18;
  (**(code **)(*unaff_ESI + 0xbc))(unaff_ESI[2],unaff_ESI[3]);
  __security_check_cookie(uStack_20 ^ (uint)&iStack_34);
  return;
}

