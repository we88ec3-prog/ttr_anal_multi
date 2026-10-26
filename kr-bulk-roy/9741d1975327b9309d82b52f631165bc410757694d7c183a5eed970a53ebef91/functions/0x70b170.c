
undefined4 FUN_0070b170(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar1 != &DAT_00c0bfc8) && (puVar1[2] == 5)) goto LAB_0070b1d9;
    if ((*(undefined4 **)(param_1 + 8) <= puVar1) ||
       ((puVar1 == &DAT_00c0bfc8 || (puVar1[2] == -1)))) goto LAB_0070b1ad;
    pcVar3 = (&PTR_DAT_00c0be1c)[puVar1[2]];
  }
  else {
LAB_0070b1ad:
    pcVar3 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar3);
  FUN_006f5da0(1);
LAB_0070b1d9:
  piVar4 = *(int **)(param_1 + 0xc);
  piVar2 = *(int **)(param_1 + 8);
  if (piVar2 <= piVar4) {
    piVar4 = &DAT_00c0bfc8;
  }
  iVar5 = piVar4[2];
  if (iVar5 == 5) {
    iVar5 = *(int *)(*piVar4 + 8);
  }
  else if (iVar5 == 7) {
    iVar5 = *(int *)(*piVar4 + 8);
  }
  else {
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar5 * 4);
  }
  if (iVar5 == 0) {
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar1 = *(undefined4 **)(param_1 + 8);
    uVar6 = FUN_006f99a0(param_1,0,1);
    *puVar1 = uVar6;
    puVar1[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    puVar1 = *(undefined4 **)(param_1 + 8);
    *puVar1 = puVar1[-4];
    puVar1[1] = puVar1[-3];
    puVar1[2] = puVar1[-2];
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006f5910();
  }
  else {
    *piVar2 = iVar5;
    piVar2[2] = 5;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  }
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *(undefined4 *)(param_1 + 0x48);
  puVar1[1] = *(undefined4 *)(param_1 + 0x4c);
  puVar1[2] = *(undefined4 *)(param_1 + 0x50);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  iVar5 = *(int *)(param_1 + 8);
  local_18[0] = FUN_006fec70(param_1,"__index",7);
  local_10 = 4;
  FUN_006fb9a0(param_1,iVar5 + -0x20,local_18,*(int *)(param_1 + 8) + -0x10);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
  return 0;
}

