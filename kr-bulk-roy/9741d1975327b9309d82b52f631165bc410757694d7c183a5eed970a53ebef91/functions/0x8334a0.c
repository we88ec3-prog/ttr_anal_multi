
undefined4 FUN_008334a0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  int iVar7;
  int *in_EDX;
  int *piVar8;
  int iVar9;
  
  iVar7 = in_EDX[1];
  iVar1 = *in_EDX;
  iVar2 = in_EDX[2];
  iVar3 = in_EDX[5];
  iVar9 = in_ECX[1] - iVar7;
  iVar5 = *in_ECX;
  iVar4 = *(int *)(iVar3 + ((iVar2 * iVar9 - iVar1) + iVar5) * 4);
  *param_1 = iVar4;
  iVar7 = in_ECX[3] - iVar7;
  iVar5 = iVar5 - iVar1;
  if (iVar9 < iVar7) {
    piVar6 = (int *)(iVar3 + (iVar2 * iVar9 + iVar5) * 4);
    iVar3 = iVar5;
    piVar8 = piVar6;
    do {
      for (; iVar3 < in_ECX[2] - iVar1; iVar3 = iVar3 + 1) {
        if (iVar4 != *piVar6) {
          return 0;
        }
        piVar6 = piVar6 + 1;
      }
      piVar6 = piVar8 + iVar2;
      iVar9 = iVar9 + 1;
      iVar3 = iVar5;
      piVar8 = piVar6;
    } while (iVar9 < iVar7);
  }
  return 1;
}

