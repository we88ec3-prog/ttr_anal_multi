
void FUN_0082c340(void)

{
  uint uVar1;
  int in_ECX;
  ushort *in_EDX;
  int local_140;
  ushort local_ac [2];
  undefined1 local_a8 [148];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914226;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_0082c420(in_EDX);
  if ((local_140 == *(int *)(in_ECX + 4)) || (*in_EDX < *(ushort *)(local_140 + 0xc))) {
    FUN_0082baa0(uVar1);
    local_8 = 0;
    local_ac[0] = *in_EDX;
    FUN_0082c460(local_a8);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0082c980(local_ac);
    FUN_0082c560(in_ECX,local_140);
    FUN_004ccf90();
    FUN_004ccf90();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

