
undefined4 FUN_00541ae0(undefined4 param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092985e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007b6d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fd8ef8 & 1) == 0) {
    DAT_00fd8ef8 = DAT_00fd8ef8 | 1;
    local_8 = 0;
    FUN_00498280();
    _atexit(FUN_00bcddd0);
    local_8 = 0xffffffff;
  }
  FUN_008438c0(&param_2);
  if (local_14 != DAT_00fd8f00) {
    iVar3 = *(int *)(local_14 + 0x10);
    param_2 = iVar3;
    if (*(int *)(iVar3 + 0x48) == 0) {
      FUN_0053e120();
    }
    *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1;
    uVar2 = 0;
    uVar4 = (*(int **)(iVar3 + 0x44))[1] - **(int **)(iVar3 + 0x44) >> 2;
    if (uVar4 != 0) {
      do {
        local_14 = *(int *)(**(int **)(iVar3 + 0x44) + uVar2 * 4);
        FUN_00804260(&local_14);
        uVar2 = uVar2 + 1;
        iVar3 = param_2;
      } while (uVar2 < uVar4);
    }
    piVar1 = (int *)(iVar3 + 0x48);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      FUN_0053e1d0();
    }
    if (*(int *)(iVar3 + 0x48) < 0) {
      FUN_006edb60("Stage::Release(): refCount < 0");
    }
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

