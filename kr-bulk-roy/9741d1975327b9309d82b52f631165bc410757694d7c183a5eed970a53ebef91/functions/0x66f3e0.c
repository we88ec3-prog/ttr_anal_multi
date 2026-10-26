
void FUN_0066f3e0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uVar1 = param_2;
  puStack_c = &LAB_0091d8fc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  if (uVar1 != 0) {
    param_2 = (uVar1 - 1) / 6;
    FUN_0082ef00(&param_2);
  }
  iVar2 = *(int *)(param_1 + 0x254);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x254) + 200))();
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
  if ((uVar1 != 0x25) && (uVar1 != 0)) {
    param_2 = 0xc - (uVar1 - 1) % 6;
    FUN_0082ef00(&param_2);
  }
  iVar2 = *(int *)(param_1 + 600);
  if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
     (iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar2 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 600) + 200))();
  ExceptionList = local_10;
  return;
}

