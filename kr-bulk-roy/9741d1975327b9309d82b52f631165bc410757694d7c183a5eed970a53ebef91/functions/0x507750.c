
int FUN_00507750(int param_1,int param_2)

{
  int in_EAX;
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = *(uint *)(in_EAX + 0x18);
  uVar7 = 0;
  if (uVar3 == 0) {
    return 0;
  }
  while( true ) {
    uVar2 = uVar7;
    FUN_00542210(uVar7);
    piVar1 = (int *)FUN_0050b4b0(uVar2);
    iVar6 = 0;
    if ((int *)*piVar1 != (int *)0x0) {
      iVar6 = *(int *)*piVar1;
    }
    uVar2 = piVar1[2];
    if (*(uint *)(iVar6 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar6 + 8);
    }
    if (**(int **)(*(int *)(iVar6 + 4) + uVar2 * 4) == param_1) break;
    uVar7 = uVar7 + 1;
    if (uVar3 <= uVar7) {
      return 0;
    }
  }
  uVar3 = uVar7;
  FUN_00542210(uVar7);
  piVar1 = (int *)FUN_0050b4b0(uVar3);
  iVar6 = 0;
  if ((int *)*piVar1 != (int *)0x0) {
    iVar6 = *(int *)*piVar1;
  }
  uVar3 = piVar1[2];
  if (*(uint *)(iVar6 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(iVar6 + 8);
  }
  iVar6 = *(int *)(*(int *)(iVar6 + 4) + uVar3 * 4);
  iVar4 = *(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x40);
  iVar6 = iVar4 >> 0x1f;
  iVar4 = iVar4 / 0x60 + iVar6;
  uVar3 = 0;
  if (iVar4 == iVar6) {
    return 0;
  }
  param_1 = 0;
  while( true ) {
    uVar2 = uVar7;
    FUN_00542210(uVar7);
    piVar1 = (int *)FUN_0050b4b0(uVar2);
    iVar5 = 0;
    if ((int *)*piVar1 != (int *)0x0) {
      iVar5 = *(int *)*piVar1;
    }
    uVar2 = piVar1[2];
    if (*(uint *)(iVar5 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar5 + 8);
    }
    if (*(int *)(param_1 + *(int *)(*(int *)(*(int *)(iVar5 + 4) + uVar2 * 4) + 0x40)) == param_2)
    break;
    param_1 = param_1 + 0x60;
    uVar3 = uVar3 + 1;
    if ((uint)(iVar4 - iVar6) <= uVar3) {
      return 0;
    }
  }
  FUN_00542210(uVar7);
  piVar1 = (int *)FUN_0050b4b0(uVar7);
  iVar6 = 0;
  if ((int *)*piVar1 != (int *)0x0) {
    iVar6 = *(int *)*piVar1;
  }
  uVar7 = piVar1[2];
  if (*(uint *)(iVar6 + 8) <= uVar7) {
    uVar7 = uVar7 - *(uint *)(iVar6 + 8);
  }
  return *(int *)(*(int *)(*(int *)(iVar6 + 4) + uVar7 * 4) + 0x40) + 0xc + uVar3 * 0x60;
}

