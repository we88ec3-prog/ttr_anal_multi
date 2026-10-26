
int FUN_00714770(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092156c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_00713910(param_2,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (iVar2 != 0) {
    ExceptionList = local_10;
    return iVar2;
  }
  if ((DAT_00fe4c98 & 1) == 0) {
    DAT_00fe4c98 = DAT_00fe4c98 | 1;
    local_8 = iVar2;
    FUN_007142d0();
    _atexit((_func_4879 *)&LAB_00bd0760);
    local_8 = 0xffffffff;
  }
  if (DAT_00fe4c94 != '\0') {
    if ((DAT_00fe4c98 & 1) == 0) {
      DAT_00fe4c98 = DAT_00fe4c98 | 1;
      local_8 = 1;
      FUN_007142d0();
      _atexit((_func_4879 *)&LAB_00bd0760);
      local_8 = 0xffffffff;
    }
    cVar1 = FUN_007143b0();
    if (cVar1 == '\0') {
      uVar3 = FUN_00714260();
      cVar1 = FUN_00714470(uVar3);
      if (cVar1 == '\0') {
        ExceptionList = local_10;
        return 0;
      }
    }
    iVar2 = FUN_00714030();
    ExceptionList = local_10;
    return iVar2;
  }
  iVar2 = FUN_00714030();
  ExceptionList = local_10;
  return iVar2;
}

