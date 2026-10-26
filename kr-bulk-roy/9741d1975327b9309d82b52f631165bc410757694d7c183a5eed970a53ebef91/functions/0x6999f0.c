
void FUN_006999f0(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  iVar1 = *(int *)(*(int *)(param_1 + 0x94) + 0x24c);
  if ((iVar1 != 0) && (iVar1 = *(int *)(iVar1 + 0xcc), iVar1 != 0)) {
    FUN_006438f0(iVar1);
  }
  FUN_00757710(uVar2);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar2 = (uint)DAT_00f94240;
  iVar1 = *(int *)(*(int *)(param_1 + 0x94) + 0x24c);
  iVar4 = 1;
  uVar3 = 2;
  do {
    if ((uVar3 >> 1 & uVar2) != 0) {
      if (*(int *)(iVar1 + 0xcc) != 0) {
        FUN_00412c70(iVar4);
      }
      FUN_00757710();
    }
    iVar4 = iVar4 + 1;
    uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
  } while (iVar4 < 10);
  iVar1 = *(int *)(*(int *)(param_1 + 0x94) + 0x24c);
  if (iVar1 != 0) {
    FUN_00749920(iVar1);
  }
  (**(code **)(**(int **)(param_1 + 0x94) + 200))();
  ExceptionList = local_14;
  return;
}

