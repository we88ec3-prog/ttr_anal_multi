
void FUN_006bb1a0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_38 [5];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093bfb6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_38;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  FUN_006bafd0(param_1);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (((*(uint *)(in_ECX + 0x24c) < 10) &&
      (iVar2 = *(uint *)(in_ECX + 0x24c) * 0x210 + DAT_00f94304, *(int *)(iVar2 + 0x5c) != 0)) &&
     (iVar2 != 0)) {
    uVar3 = FUN_0040ef80();
    local_c = 1;
    FUN_00757800(uVar3);
    if (7 < local_24) {
      FUN_0089120c(local_38[0]);
    }
  }
  else {
    FUN_00757710();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_38);
  return;
}

