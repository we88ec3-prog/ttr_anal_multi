
undefined4 FUN_00705f30(int param_1)

{
  uint *puVar1;
  double *pdVar2;
  double dVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar4 = FUN_006f5fa0(param_1,1);
  puVar5 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar5 < *(undefined4 **)(param_1 + 8)) && (puVar5 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    FUN_006f6370(param_1,2);
  }
  if (*(uint *)(&DAT_00c0baa4 + iVar4 * 4) < 8) {
    iVar6 = FUN_006f5ae0(param_1,0);
  }
  else {
    iVar6 = -1;
  }
  if (*(int *)(&DAT_00c0baa4 + iVar4 * 4) == 3) {
    iVar4 = FUN_006f5ae0(param_1,0);
    dVar3 = (double)iVar4 * 0.0009765625 + (double)iVar6;
  }
  else {
    if (*(int *)(&DAT_00c0baa4 + iVar4 * 4) == 5) {
      puVar1 = *(uint **)(param_1 + 8);
      puVar1[2] = 1;
      *puVar1 = (uint)(iVar6 != 0);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      return 1;
    }
    dVar3 = (double)iVar6;
  }
  pdVar2 = *(double **)(param_1 + 8);
  *pdVar2 = dVar3;
  *(undefined4 *)(pdVar2 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

