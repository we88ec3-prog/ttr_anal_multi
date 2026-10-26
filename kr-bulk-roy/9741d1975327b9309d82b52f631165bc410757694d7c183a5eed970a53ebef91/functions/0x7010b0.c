
undefined4 FUN_007010b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_10;
  int local_8;
  
  piVar3 = *(int **)(param_1 + 0xc);
  if (((piVar3 < *(int **)(param_1 + 8)) && (piVar3 != &DAT_00c0bfc8)) && (piVar3[2] == 8)) {
    local_8 = 1;
    if (*(int **)(param_1 + 8) <= piVar3) {
      piVar3 = &DAT_00c0bfc8;
    }
    if (piVar3[2] == 8) {
      iVar9 = *piVar3;
    }
    else {
      iVar9 = 0;
    }
  }
  else {
    local_8 = 0;
    iVar9 = param_1;
  }
  FUN_006f6370(param_1,local_8 + 1);
  iVar4 = FUN_006f7dd0();
  if (iVar4 == 0) {
    uVar5 = FUN_006f5da0(local_8 + 1);
    return uVar5;
  }
  puVar6 = (undefined4 *)FUN_006f50f0();
  if ((puVar6 == &DAT_00c0bfc8) || (puVar6[2] == -1)) {
    FUN_006f5da0(local_8 + 3);
  }
  FUN_006f5220();
  if (param_1 != iVar9) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
    puVar6 = *(undefined4 **)(iVar9 + 8);
    puVar1 = *(undefined4 **)(param_1 + 8);
    *(undefined4 **)(iVar9 + 8) = puVar6 + 4;
    *puVar6 = *puVar1;
    puVar6[1] = puVar1[1];
    puVar6[2] = puVar1[2];
  }
  iVar7 = FUN_006f6370(param_1,local_8 + 2);
  iVar4 = *(int *)(iVar9 + 0x28);
  iVar8 = FUN_006f7e40(iVar9,iVar7);
  if (iVar8 != 0) {
    iVar2 = *(int *)(iVar9 + 8);
    puVar6 = (undefined4 *)(*(int *)(iVar4 + local_10 * 0x18) + -0x10 + iVar7 * 0x10);
    *puVar6 = *(undefined4 *)(iVar2 + -0x10);
    puVar6[1] = *(undefined4 *)(iVar2 + -0xc);
    puVar6[2] = *(undefined4 *)(iVar2 + -8);
  }
  *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + -0x10;
  FUN_006f5510(iVar8);
  return 1;
}

