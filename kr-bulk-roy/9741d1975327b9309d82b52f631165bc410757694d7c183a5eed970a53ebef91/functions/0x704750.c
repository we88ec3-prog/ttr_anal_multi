
void FUN_00704750(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  char *pcVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  iVar1 = *(int *)(in_ECX + 8);
  puVar4 = *(undefined4 **)(iVar1 + 8);
  puVar7 = (undefined4 *)(*(int *)(iVar1 + 0xc) + 0x20);
  if ((puVar7 < puVar4) && (puVar7 != &DAT_00c0bfc8)) {
    uVar8 = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x28);
  }
  else {
    uVar8 = 0xffffffff;
  }
  switch(uVar8) {
  case 3:
  case 4:
    FUN_00704660();
    return;
  case 5:
    FUN_00703fd0(param_2,param_3);
    puVar4 = (undefined4 *)(*(int *)(iVar1 + 0xc) + 0x20);
    if (*(undefined4 **)(iVar1 + 8) <= puVar4) {
      puVar4 = &DAT_00c0bfc8;
    }
    puVar7 = *(undefined4 **)(iVar1 + 8) + -4;
    FUN_006fb850(iVar1,puVar4,puVar7,puVar7);
    break;
  case 6:
    if (puVar4 <= puVar7) {
      puVar7 = &DAT_00c0bfc8;
    }
    *puVar4 = *puVar7;
    puVar4[1] = puVar7[1];
    puVar4[2] = puVar7[2];
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
    iVar3 = FUN_007040b0();
    FUN_006fe550(iVar1,*(int *)(iVar1 + 8) + (iVar3 + 1) * -0x10,1);
  }
  iVar3 = *(int *)(iVar1 + 8);
  iVar2 = *(int *)(iVar3 + -8);
  piVar5 = (int *)(iVar3 + -0x10);
  if ((iVar2 == 0) || ((iVar2 == 1 && (*piVar5 == 0)))) {
    *(int **)(iVar1 + 8) = piVar5;
    if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar4 = *(undefined4 **)(iVar1 + 8);
    uVar8 = FUN_006fec70(iVar1,param_2,param_3 - param_2);
    *puVar4 = uVar8;
    puVar4[2] = 4;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
    FUN_006f6cd0();
    return;
  }
  if (piVar5 == &DAT_00c0bfc8) {
LAB_0070488c:
    pcVar6 = "no value";
  }
  else {
    if ((iVar2 == 4) || (iVar2 == 3)) goto LAB_007048a9;
    if ((piVar5 == &DAT_00c0bfc8) || (*(int *)(iVar3 + -8) == -1)) goto LAB_0070488c;
    pcVar6 = (&PTR_DAT_00c0be1c)[*(int *)(iVar3 + -8)];
  }
  FUN_006f5f30(iVar1,"invalid replacement value (a %s)",pcVar6);
LAB_007048a9:
  FUN_006f6cd0();
  return;
}

