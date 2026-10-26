
void FUN_005d77e0(void)

{
  int iVar1;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f63e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_005c7190();
  if (iVar1 != 0) {
    local_14 = 0xf423e;
    FUN_0082ef00(&local_14);
  }
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

