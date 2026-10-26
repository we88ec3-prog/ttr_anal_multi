
void FUN_007efdc0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092067c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xe8) == 0) {
    if ((DAT_00fd94d8 & 1) != 0) goto LAB_007efe98;
    local_8 = 0;
  }
  else {
    FUN_005366c0(param_1 + 8);
    if (param_1 != *(int *)(in_ECX + 0xd0)) {
      *(undefined4 *)(param_1 + 0x2c) = param_2;
      ExceptionList = local_10;
      return;
    }
    if ((DAT_00fd94d8 & 1) != 0) goto LAB_007efe98;
    local_8 = 1;
  }
  DAT_00fd94d8 = DAT_00fd94d8 | 1;
  FUN_007b5430(uVar1);
  _atexit((_func_4879 *)&LAB_00bce660);
  local_8 = 0xffffffff;
LAB_007efe98:
  FUN_007b67e0(&DAT_00fd9420);
  ExceptionList = local_10;
  return;
}

