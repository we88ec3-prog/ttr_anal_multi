
void FUN_0070e110(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int iVar8;
  
  iVar1 = *(int *)(param_1 + 0x34);
  piVar2 = *(int **)(param_1 + 0x30);
  iVar3 = *piVar2;
  FUN_0070db10();
  FUN_00713370(0x80001e,*(undefined4 *)(piVar2[3] + 8));
  if (piVar2[6] + 1U < 0x40000000) {
    iVar4 = *(int *)(iVar3 + 0x2c);
    iVar8 = piVar2[6] * 4;
    iVar6 = *(int *)(iVar1 + 0x10);
    iVar5 = (**(code **)(iVar6 + 0xc))
                      (*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar3 + 0xc),iVar4 * 4,iVar8);
    if ((iVar5 == 0) && (iVar8 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
      iVar8 = extraout_ECX;
    }
    *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + iVar8 + iVar4 * -4;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 0xc) = iVar5;
  *(int *)(iVar3 + 0x2c) = piVar2[6];
  if (piVar2[6] + 1U < 0x40000000) {
    iVar8 = *(int *)(iVar3 + 0x30);
    iVar4 = *(int *)(iVar1 + 0x10);
    iVar6 = piVar2[6] * 4;
    iVar5 = (**(code **)(iVar4 + 0xc))
                      (*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar3 + 0x14),iVar8 * 4,iVar6);
    if ((iVar5 == 0) && (iVar6 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
    }
    *(int *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x44) + iVar6 + iVar8 * -4;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 0x14) = iVar5;
  *(int *)(iVar3 + 0x30) = piVar2[6];
  if (piVar2[10] + 1U < 0x10000000) {
    iVar8 = *(int *)(iVar3 + 0x28);
    iVar4 = *(int *)(iVar1 + 0x10);
    iVar6 = piVar2[10] << 4;
    iVar5 = (**(code **)(iVar4 + 0xc))
                      (*(undefined4 *)(iVar4 + 0x10),*(undefined4 *)(iVar3 + 8),iVar8 * 0x10,iVar6);
    if ((iVar5 == 0) && (iVar6 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
      iVar6 = extraout_ECX_00;
    }
    *(int *)(iVar4 + 0x44) = *(int *)(iVar4 + 0x44) + iVar6 + iVar8 * -0x10;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 8) = iVar5;
  *(int *)(iVar3 + 0x28) = piVar2[10];
  if (piVar2[0xb] + 1U < 0x40000000) {
    iVar4 = *(int *)(iVar3 + 0x34);
    iVar8 = piVar2[0xb] * 4;
    iVar6 = *(int *)(iVar1 + 0x10);
    iVar5 = (**(code **)(iVar6 + 0xc))
                      (*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar3 + 0x10),iVar4 * 4,iVar8);
    if ((iVar5 == 0) && (iVar8 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
      iVar8 = extraout_ECX_01;
    }
    *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + iVar8 + iVar4 * -4;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 0x10) = iVar5;
  *(int *)(iVar3 + 0x34) = piVar2[0xb];
  if ((int)(short)piVar2[0xc] + 1U < 0x15555556) {
    iVar8 = *(int *)(iVar1 + 0x10);
    iVar4 = *(int *)(iVar3 + 0x38);
    iVar6 = (short)piVar2[0xc] * 0xc;
    iVar5 = (**(code **)(iVar8 + 0xc))
                      (*(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar3 + 0x18),iVar4 * 0xc,iVar6
                      );
    if ((iVar5 == 0) && (iVar6 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
    }
    *(int *)(iVar8 + 0x44) = *(int *)(iVar8 + 0x44) + iVar6 + iVar4 * -0xc;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 0x18) = iVar5;
  uVar7 = (uint)*(byte *)(iVar3 + 0x48);
  *(int *)(iVar3 + 0x38) = (int)(short)piVar2[0xc];
  if (uVar7 + 1 < 0x40000000) {
    iVar4 = *(int *)(iVar3 + 0x24);
    iVar8 = uVar7 * 4;
    iVar6 = *(int *)(iVar1 + 0x10);
    iVar5 = (**(code **)(iVar6 + 0xc))
                      (*(undefined4 *)(iVar6 + 0x10),*(undefined4 *)(iVar3 + 0x1c),iVar4 * 4,iVar8);
    if ((iVar5 == 0) && (uVar7 != 0)) {
      iVar5 = FUN_006fdb40(iVar1,4);
      iVar8 = extraout_ECX_02;
    }
    *(int *)(iVar6 + 0x44) = *(int *)(iVar6 + 0x44) + iVar8 + iVar4 * -4;
  }
  else {
    FUN_006f8b60(iVar1,"memory allocation error: block too big");
    iVar5 = 0;
  }
  *(int *)(iVar3 + 0x1c) = iVar5;
  *(uint *)(iVar3 + 0x24) = (uint)*(byte *)(iVar3 + 0x48);
  *(int *)(param_1 + 0x30) = piVar2[2];
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -0x20;
  FUN_0070d6f0();
  return;
}

