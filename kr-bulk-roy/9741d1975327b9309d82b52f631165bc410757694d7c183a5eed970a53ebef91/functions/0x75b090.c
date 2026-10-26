
void FUN_0075b090(void)

{
  int *in_ECX;
  undefined4 unaff_EBX;
  int local_1c;
  undefined4 uStack_18;
  int iStack_14;
  uint uStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_1c;
  (**(code **)(*in_ECX + 0x178))(&local_1c);
  if (in_ECX[0x20] != 0) {
    if (iStack_14 < local_1c) {
      iStack_14 = local_1c;
    }
    (**(code **)(*(int *)in_ECX[0x20] + 0xbc))(unaff_EBX,local_1c,uStack_18,iStack_14);
  }
  __security_check_cookie(uStack_10 ^ (uint)&stack0xffffffe0);
  return;
}

