
undefined4 FUN_006fbca0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  double *pdVar2;
  double *pdVar3;
  
  iVar1 = param_1[2];
  if (iVar1 == 5) {
    iVar1 = *(int *)(*param_1 + 8);
  }
  else if (iVar1 == 7) {
    iVar1 = *(int *)(*param_1 + 8);
  }
  else {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x10) + 0x98 + iVar1 * 4);
  }
  if (iVar1 == 0) {
    pdVar2 = (double *)&DAT_00c0bfc8;
  }
  else {
    pdVar2 = (double *)FUN_006f9c10();
  }
  iVar1 = *(int *)(pdVar2 + 1);
  if ((iVar1 == 0) || (pdVar3 = (double *)FUN_006feab0(param_3), iVar1 != *(int *)(pdVar3 + 1))) {
    return 0xffffffff;
  }
  switch(iVar1) {
  case 0:
    break;
  default:
    if (*(int *)pdVar2 != *(int *)pdVar3) {
      return 0xffffffff;
    }
    break;
  case 3:
    if (*pdVar3 != *pdVar2) {
      return 0xffffffff;
    }
  }
  FUN_006fb700();
  iVar1 = (*(int **)(in_EAX + 8))[2];
  if ((iVar1 != 0) && ((iVar1 != 1 || (**(int **)(in_EAX + 8) != 0)))) {
    return 1;
  }
  return 0;
}

