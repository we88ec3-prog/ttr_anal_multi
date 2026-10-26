
int * FUN_007813a0(int *param_1,int param_2,undefined4 param_3,int param_4,byte param_5)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = **(int **)(in_ECX + 0x24);
  if ((iVar3 != 0) && (*(int *)(in_ECX + 0x44) - iVar3 < 0)) {
    *(int *)(in_ECX + 0x44) = iVar3;
  }
  if (((param_5 & 1) == 0) || (iVar3 = **(int **)(in_ECX + 0x20), iVar3 == 0)) {
    if (((param_5 & 2) == 0) || (iVar3 = **(int **)(in_ECX + 0x24), iVar3 == 0)) {
      param_2 = -1;
    }
    else {
      if (param_4 == 2) {
        param_2 = (*(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10)) + param_2;
      }
      else if (param_4 == 1) {
        param_2 = (iVar3 - **(int **)(in_ECX + 0x10)) + param_2;
      }
      else if ((param_4 != 0) || (param_2 == -1)) {
        param_2 = -1;
      }
      if ((param_2 < 0) || (*(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10) < param_2)) {
        param_2 = -1;
      }
      else {
        iVar3 = (**(int **)(in_ECX + 0x10) - iVar3) + param_2;
        **(int **)(in_ECX + 0x34) = **(int **)(in_ECX + 0x34) - iVar3;
        **(int **)(in_ECX + 0x24) = **(int **)(in_ECX + 0x24) + iVar3;
      }
    }
    goto LAB_007814cd;
  }
  if (param_4 == 2) {
    param_2 = (*(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10)) + param_2;
  }
  else if (param_4 == 1) {
    if ((param_5 & 2) == 0) {
      param_2 = (iVar3 - **(int **)(in_ECX + 0x10)) + param_2;
    }
    else {
LAB_0078140f:
      param_2 = -1;
    }
  }
  else if ((param_4 != 0) || (param_2 == -1)) goto LAB_0078140f;
  if ((param_2 < 0) || (*(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10) < param_2)) {
    param_2 = -1;
  }
  else {
    iVar3 = (**(int **)(in_ECX + 0x10) - iVar3) + param_2;
    **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar3;
    **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar3;
    if ((param_5 & 2) != 0) {
      iVar3 = **(int **)(in_ECX + 0x24);
      if (iVar3 != 0) {
        iVar1 = **(int **)(in_ECX + 0x20);
        iVar2 = **(int **)(in_ECX + 0x34);
        **(int **)(in_ECX + 0x24) = iVar1;
        **(int **)(in_ECX + 0x34) = (iVar2 + iVar3) - iVar1;
      }
    }
  }
LAB_007814cd:
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = param_2 >> 0x1f;
  return param_1;
}

