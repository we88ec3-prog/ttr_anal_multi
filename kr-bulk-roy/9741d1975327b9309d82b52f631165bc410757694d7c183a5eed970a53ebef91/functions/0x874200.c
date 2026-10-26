
undefined4 FUN_00874200(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  undefined4 local_18 [2];
  int iStack_10;
  int local_c;
  
  iVar10 = DAT_00f7b044;
  bVar5 = 0;
  if (param_1 != (int *)0x0) {
    for (iVar6 = (**(code **)(*param_1 + 4))(); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x28)) {
      if (*(int *)(iVar6 + 4) == iVar10) {
        bVar5 = 1;
        goto LAB_00874242;
      }
    }
    bVar5 = 0;
  }
LAB_00874242:
  uVar9 = -(uint)bVar5 & (uint)param_1;
  if (uVar9 != 0) {
    iVar10 = 0;
    local_c = 0;
    if (*(int *)(in_ECX + 0x30) != 0) {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x30) + 4))(local_18);
      if (*piVar7 < 0) {
        iVar10 = *piVar7;
      }
      if (0 < piVar7[1]) {
        local_c = piVar7[1];
      }
    }
    if (*(int *)(in_ECX + 0x34) != 0) {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x34) + 4))(local_18);
      if (*piVar7 < iVar10) {
        iVar10 = *piVar7;
      }
      if (local_c < piVar7[1]) {
        local_c = piVar7[1];
      }
    }
    if (*(int *)(in_ECX + 0x38) != 0) {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x38) + 4))(local_18);
      if (*piVar7 < iVar10) {
        iVar10 = *piVar7;
      }
      if (local_c < piVar7[1]) {
        local_c = piVar7[1];
      }
    }
    if (*(int *)(in_ECX + 0x3c) != 0) {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x3c) + 4))(local_18);
      if (*piVar7 < iVar10) {
        iVar10 = *piVar7;
      }
      if (local_c < piVar7[1]) {
        local_c = piVar7[1];
      }
    }
    if (*(int *)(in_ECX + 0x40) != 0) {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 0x40) + 4))(local_18);
      if (*piVar7 < iVar10) {
        iVar10 = *piVar7;
      }
      if (local_c < piVar7[1]) {
        local_c = piVar7[1];
      }
    }
    uVar8 = FUN_00796de0(iVar10,param_2,*(undefined4 *)(in_ECX + 0x44));
    uVar1 = *(undefined4 *)(uVar9 + 0x54);
    uVar2 = *(undefined4 *)(uVar9 + 0x58);
    uVar3 = *(undefined4 *)(uVar9 + 0x5c);
    uVar4 = *(undefined4 *)(uVar9 + 0x60);
    local_18[0] = *(undefined4 *)(uVar9 + 100);
    iStack_10 = FUN_00876040(uVar8);
    iVar10 = FUN_008760c0(uVar8);
    if ((iStack_10 != 0) || (iVar10 != 0)) {
      *(undefined4 *)(uVar9 + 0x54) = uVar1;
      *(undefined4 *)(uVar9 + 0x58) = uVar2;
    }
    iStack_10 = FUN_00875700(uVar8);
    iVar10 = FUN_00876140(uVar8);
    if ((iVar10 != 0) || (iStack_10 != 0)) {
      *(undefined4 *)(uVar9 + 0x5c) = uVar3;
      *(undefined4 *)(uVar9 + 0x60) = uVar4;
    }
    iVar10 = FUN_008761c0(uVar8);
    if (iVar10 != 0) {
      *(undefined4 *)(uVar9 + 100) = local_18[0];
    }
    return 1;
  }
  return 0;
}

