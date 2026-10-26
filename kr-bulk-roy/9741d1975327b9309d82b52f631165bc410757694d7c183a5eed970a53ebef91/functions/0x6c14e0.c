
void FUN_006c14e0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092be9e;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  *(undefined4 *)(param_1 + 0xac) = 1;
  iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0xcc);
  uVar8 = param_2[1] - *param_2 >> 2;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar8);
  }
  local_20 = 0;
  if (uVar8 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xa8) + 0xcc);
      iVar2 = *(int *)(*param_2 + local_20 * 4);
      if ((((iVar1 == 0) || ((int)local_20 < 0)) ||
          (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= (int)local_20)) ||
         (iVar9 = *(int *)(local_20 * 4 + *(int *)(iVar1 + 0xa8)), iVar9 == 0)) {
        iVar9 = 0;
      }
      else {
        *(int *)(iVar9 + 0x20) = iVar2;
        uVar7 = iVar2 + 1;
        if (uVar7 <= *(uint *)(iVar1 + 0xe4)) {
          uVar7 = *(uint *)(iVar1 + 0xe4);
        }
        *(uint *)(iVar1 + 0xe4) = uVar7;
      }
      iVar1 = *param_2;
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(uVar6);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6a30(*(undefined4 *)(iVar1 + local_20 * 4));
      FUN_00757710();
      *(undefined4 *)(iVar9 + 0x154) = 0xffffffff;
      if ((*(uint *)(iVar9 + 0x28) & 4) != 0) {
        *(uint *)(iVar9 + 0x28) = *(uint *)(iVar9 + 0x28) ^ 4;
      }
      local_20 = local_20 + 1;
    } while (local_20 < uVar8);
  }
  piVar3 = *(int **)(param_1 + 0xa8);
  puVar4 = (undefined4 *)piVar3[0x19];
  for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
    iVar1 = puVar5[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar3 + 0x128))();
  FUN_00749d00();
  ExceptionList = local_14;
  return;
}

