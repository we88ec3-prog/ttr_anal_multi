
void FUN_0066ae40(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_3;
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
  param_3 = param_2;
  FUN_0082ef00(&param_3);
  iVar2 = *(int *)(param_1 + 0x160 + iVar1 * 4);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x160 + iVar1 * 4) + 0x94))(1);
  ExceptionList = local_10;
  return;
}

