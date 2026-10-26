
void FUN_007c5430(undefined4 param_1)

{
  uint uVar1;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined4 local_50 [5];
  uint local_3c;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918958;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_54 = param_1;
  local_18 = uVar1;
  FUN_007c5e90(local_50,&local_54,local_58);
  local_8 = 0;
  FUN_007c5dd0(uVar1);
  if (0xf < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  if (0xf < local_3c) {
    FUN_0089120c(local_50[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

