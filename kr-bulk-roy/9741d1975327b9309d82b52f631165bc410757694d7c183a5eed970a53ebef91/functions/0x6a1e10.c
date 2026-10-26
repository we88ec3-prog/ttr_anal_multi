
void FUN_006a1e10(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
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
  param_1 = param_2;
  FUN_0082ef00(&param_1);
  iVar2 = *(int *)(iVar1 + 0x118);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(iVar1 + 0x118) + 0x94))(1);
  ExceptionList = local_10;
  return;
}

