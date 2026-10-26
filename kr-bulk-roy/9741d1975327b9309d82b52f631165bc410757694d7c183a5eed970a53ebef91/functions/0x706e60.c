
undefined4 FUN_00706e60(int param_1)

{
  byte bVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  int *piVar9;
  
  if (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U) {
    do {
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    } while (*(uint *)(param_1 + 8) < *(int *)(param_1 + 0xc) + 0x10U);
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc) + 0x10;
  if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  if (*(int *)(param_1 + 0x14) == *(int *)(param_1 + 0x28)) {
    uVar5 = *(undefined4 *)(param_1 + 0x48);
  }
  else {
    uVar5 = *(undefined4 *)(**(int **)(*(int *)(param_1 + 0x14) + 4) + 0xc);
  }
  iVar6 = *(int *)(param_1 + 0x10);
  puVar4 = (undefined4 *)(**(code **)(iVar6 + 0xc))(*(undefined4 *)(iVar6 + 0x10),0,0,0x18);
  uVar8 = 0;
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)FUN_006fdb40(param_1,4);
    uVar8 = extraout_ECX;
  }
  *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + 0x18;
  bVar1 = *(byte *)(*(int *)(param_1 + 0x10) + 0x14);
  puVar4[3] = uVar5;
  puVar4[4] = uVar8;
  puVar4[2] = uVar8;
  *(byte *)((int)puVar4 + 5) = bVar1 & 3;
  *(undefined1 *)(puVar4 + 1) = 7;
  *puVar4 = **(undefined4 **)(*(int *)(param_1 + 0x10) + 0x70);
  **(undefined4 **)(*(int *)(param_1 + 0x10) + 0x70) = puVar4;
  puVar2 = *(undefined4 **)(param_1 + 8);
  *puVar2 = puVar4;
  puVar2[2] = 7;
  piVar7 = *(int **)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  piVar9 = &DAT_00c0bfc8;
  if (piVar7 < *(int **)(param_1 + 8)) {
    piVar9 = piVar7;
  }
  if (piVar9[2] == 0) {
    return 1;
  }
  if ((piVar9[2] == 1) && (*piVar9 == 0)) {
    return 1;
  }
  if (((piVar7 < *(int **)(param_1 + 8)) && (piVar7 != &DAT_00c0bfc8)) && (piVar7[2] == 1)) {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar4 = *(undefined4 **)(param_1 + 8);
    uVar5 = FUN_006f99a0(param_1,0,0);
    *puVar4 = uVar5;
    puVar4[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar4 = *(undefined4 **)(param_1 + 8);
    *puVar4 = puVar4[-4];
    puVar4[1] = puVar4[-3];
    puVar4[2] = puVar4[-2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar4 = *(undefined4 **)(param_1 + 8);
    *puVar4 = 1;
    puVar4[2] = 1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f57f0(param_1);
    goto LAB_00707057;
  }
  iVar6 = FUN_006f56e0();
  if (iVar6 == 0) {
LAB_0070703e:
    FUN_006f5da0(1);
  }
  else {
    puVar4 = (undefined4 *)FUN_006f9c50();
    iVar6 = *(int *)(param_1 + 8);
    *(undefined4 *)(iVar6 + -0x10) = *puVar4;
    *(undefined4 *)(iVar6 + -0xc) = puVar4[1];
    *(undefined4 *)(iVar6 + -8) = puVar4[2];
    iVar6 = *(int *)(*(int *)(param_1 + 8) + -8);
    piVar7 = (int *)(*(int *)(param_1 + 8) + -0x10);
    if ((iVar6 == 0) || ((iVar6 == 1 && (*piVar7 == 0)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    *(int **)(param_1 + 8) = piVar7;
    if (!bVar3) goto LAB_0070703e;
  }
  FUN_006f56e0();
LAB_00707057:
  FUN_006f5910();
  return 1;
}

