
void FUN_007f1150(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 local_30 [5];
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c591;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00543500(local_30,in_ECX + 0x40,in_ECX + 0x5c,local_14);
  iVar2 = 0;
  local_8 = 0;
  *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
  iVar1 = FUN_00891268(0x44);
  local_8._0_1_ = 1;
  if (iVar1 != 0) {
    iVar2 = FUN_007fc830(iVar1);
  }
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8._0_1_ = 2;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
  }
  local_8 = (uint)local_8._1_3_ << 8;
  iVar1 = FUN_007cf850();
  *(int *)(iVar2 + 0x30) = iVar1;
  *(int *)(iVar2 + 0x2c) = in_ECX + 0x28;
  FUN_00403040(iVar1 + 0x7c,0,0xffffffff);
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

