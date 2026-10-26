
void FUN_006a41f0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092c4ae;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar7 = DAT_00fe1e44 & 1;
  *(int *)(param_1 + 0xcc) = param_2;
  if (uVar7 == 0) {
    DAT_00fe1e44 = DAT_00fe1e44 | 1;
    local_8 = 0;
    FUN_00531b40(uVar6);
    _atexit(thunk_FUN_00531c60);
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(param_1 + 0xcc);
  iVar2 = *(int *)(*(int *)(param_1 + 0xd0) + 0xcc);
  if (iVar2 != 0) {
    FUN_006438f0(iVar2);
  }
  local_14 = 0;
  do {
    uVar7 = local_14;
    local_18 = local_14;
    FUN_006a4510(&local_18);
    if (param_2 != *(int *)(&DAT_00fe1eac + iVar1 * 0x10)) {
      iVar2 = *(int *)(*(int *)(param_1 + 0xd0) + 0xcc);
      if (iVar2 != 0) {
        FUN_00412c70(*(undefined4 *)(iVar2 + 0xe4));
      }
      FUN_00757710();
      uVar7 = local_14;
    }
    local_14 = uVar7 + 1;
  } while (local_14 < 0x19);
  if (*(int *)(*(int *)(param_1 + 0xd0) + 0xcc) != 0) {
    FUN_0042c8e0(0);
  }
  piVar3 = *(int **)(param_1 + 0xd0);
  puVar4 = (undefined4 *)piVar3[0x19];
  for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
    iVar1 = puVar5[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar3 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xd0) + 200))();
  FUN_006a4360();
  ExceptionList = local_10;
  return;
}

