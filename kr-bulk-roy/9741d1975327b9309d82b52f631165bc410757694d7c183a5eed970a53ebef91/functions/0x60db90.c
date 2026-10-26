
void FUN_0060db90(void)

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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e268;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0x15c) != -1) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 0;
    FUN_0060e150(local_30);
    FUN_00757710(uVar1);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

