
void FUN_0043efa0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a260;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00553ff0(uVar1);
  if (*(uint *)(in_ECX + 0x78) < 0x14) {
    FUN_004026e0(in_ECX + 0x68,0,0xffffffff);
  }
  else {
    uVar2 = FUN_0043f3e0(in_ECX + 0x68);
    local_8 = 0;
    FUN_00402800(uVar2);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    uVar2 = FUN_0043f3e0(in_ECX + 0x68);
    local_8 = 1;
    FUN_00402800(uVar2);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

