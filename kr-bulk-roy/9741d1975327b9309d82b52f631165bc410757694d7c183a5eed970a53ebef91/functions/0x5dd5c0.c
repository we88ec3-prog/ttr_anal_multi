
void FUN_005dd5c0(int param_1,undefined4 param_2)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d10e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00(&param_2);
  iVar1 = *(int *)(param_1 + 0x2c0);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar1 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar1 == 0xbf6b)) {
    FUN_0077b200();
  }
  ExceptionList = local_10;
  return;
}

