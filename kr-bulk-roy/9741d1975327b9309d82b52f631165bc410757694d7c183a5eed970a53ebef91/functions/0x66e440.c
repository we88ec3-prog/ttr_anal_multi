
void FUN_0066e440(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f942a8 == 1) {
    iVar1 = *(int *)(param_1 + 0xf0);
    if (*(char *)(iVar1 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar1 + 0x168) = 0;
    *(undefined4 *)(iVar1 + 0x160) = 0;
    *(undefined4 *)(iVar1 + 0x164) = 0;
    *(undefined4 *)(iVar1 + 0x14c) = 0;
    piVar2 = *(int **)(param_1 + 0xf0);
  }
  else {
    if (DAT_00f942a8 != 2) {
      ExceptionList = local_14;
      return;
    }
    FUN_00761430(param_2);
    piVar2 = *(int **)(param_1 + 0xf4);
  }
  (**(code **)(*piVar2 + 200))();
  ExceptionList = local_14;
  return;
}

