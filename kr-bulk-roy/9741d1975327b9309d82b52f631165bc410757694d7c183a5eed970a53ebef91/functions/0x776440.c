
void FUN_00776440(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    uVar1 = FUN_00764d80(local_30,&DAT_00bed1fc,local_14);
    local_8 = 0;
    FUN_00402800(uVar1);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_30[0] = local_30[0] & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    FUN_00429860(in_ECX + 0x28);
    FUN_00429860(in_ECX + 0x30);
    FUN_00429860(in_ECX + 0x2c);
    FUN_00429860(in_ECX + 0x34);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

