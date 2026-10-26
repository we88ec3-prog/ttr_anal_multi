
undefined4 FUN_00700f80(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_8;
  
  piVar3 = *(int **)(param_1 + 0xc);
  if (((piVar3 < *(int **)(param_1 + 8)) && (piVar3 != &DAT_00c0bfc8)) && (piVar3[2] == 8)) {
    local_8 = 1;
    if (*(int **)(param_1 + 8) <= piVar3) {
      piVar3 = &DAT_00c0bfc8;
    }
    if (piVar3[2] == 8) {
      iVar8 = *piVar3;
    }
    else {
      iVar8 = 0;
    }
  }
  else {
    local_8 = 0;
    iVar8 = param_1;
  }
  FUN_006f6370(param_1,local_8 + 1);
  iVar4 = FUN_006f7dd0();
  if (iVar4 == 0) {
    uVar5 = FUN_006f5da0(local_8 + 1);
    return uVar5;
  }
  iVar6 = FUN_006f6370(param_1,local_8 + 2);
  iVar4 = *(int *)(iVar8 + 0x28);
  iVar7 = FUN_006f7e40(iVar8,iVar6);
  if (iVar7 != 0) {
    puVar2 = *(undefined4 **)(iVar8 + 8);
    puVar1 = (undefined4 *)(*(int *)(iVar4 + local_10 * 0x18) + -0x10 + iVar6 * 0x10);
    *puVar2 = *puVar1;
    puVar2[1] = puVar1[1];
    puVar2[2] = puVar1[2];
    *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 0x10;
    FUN_006f51d0();
    FUN_006f5510(iVar7);
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = puVar1[-8];
    puVar1[1] = puVar1[-7];
    puVar1[2] = puVar1[-6];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    return 2;
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

