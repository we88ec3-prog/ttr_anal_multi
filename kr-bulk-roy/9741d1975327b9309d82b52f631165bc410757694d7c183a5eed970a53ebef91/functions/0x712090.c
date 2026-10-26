
void FUN_00712090(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  double *pdVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  iVar5 = param_1[4];
  pdVar3 = (double *)FUN_006f9d20(iVar5);
  iVar2 = *param_1;
  iVar7 = *(int *)(iVar2 + 0x28);
  piVar6 = (int *)(iVar2 + 0x28);
  if (*(int *)(pdVar3 + 1) == 3) {
    FUN_008fed10();
    return;
  }
  iVar1 = param_1[10];
  param_1 = param_1 + 10;
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar1;
  if (*piVar6 < *param_1 + 1) {
    uVar4 = FUN_00700790(iVar5,*(undefined4 *)(iVar2 + 8),piVar6,0x10,"constant table overflow");
    *(undefined4 *)(iVar2 + 8) = uVar4;
  }
  if (iVar7 < *piVar6) {
    iVar5 = iVar7 << 4;
    do {
      *(undefined4 *)(iVar5 + 8 + *(int *)(iVar2 + 8)) = 0;
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar7 < *piVar6);
  }
  piVar6 = (int *)(*param_1 * 0x10 + *(int *)(iVar2 + 8));
  *piVar6 = *param_2;
  piVar6[1] = param_2[1];
  piVar6[2] = param_2[2];
  if (((3 < param_2[2]) && ((*(byte *)(*param_2 + 5) & 3) != 0)) &&
     ((*(byte *)(iVar2 + 5) & 4) != 0)) {
    FUN_006fb5a0(*param_2);
  }
  *param_1 = *param_1 + 1;
  return;
}

