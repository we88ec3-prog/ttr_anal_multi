
void FUN_005f3050(void)

{
  uint uVar1;
  int in_ECX;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  local_14 = uVar1;
  if (0 < *(int *)(*(int *)(in_ECX + 0x184) + 0x58)) {
    FUN_005e1d10(local_30);
  }
  FUN_00757800(local_30);
  *(undefined4 *)(*(int *)(in_ECX + 0x194) + 0x154) = 0xffffffff;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0],uVar1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

