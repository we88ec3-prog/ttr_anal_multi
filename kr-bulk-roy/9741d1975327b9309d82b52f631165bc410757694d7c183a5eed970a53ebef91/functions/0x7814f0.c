
int * FUN_007814f0(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  byte in_stack_00000020;
  
  param_4 = param_4 + param_2;
  iVar3 = **(int **)(in_ECX + 0x24);
  if ((iVar3 != 0) && (*(int *)(in_ECX + 0x44) - iVar3 < 0)) {
    *(int *)(in_ECX + 0x44) = iVar3;
  }
  if (param_4 != -1) {
    if (((in_stack_00000020 & 1) == 0) || (**(int **)(in_ECX + 0x20) == 0)) {
      if (((in_stack_00000020 & 2) != 0) &&
         (((iVar3 = **(int **)(in_ECX + 0x24), iVar3 != 0 && (-1 < param_4)) &&
          (param_4 <= *(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10))))) {
        iVar3 = (**(int **)(in_ECX + 0x10) - iVar3) + param_4;
        **(int **)(in_ECX + 0x34) = **(int **)(in_ECX + 0x34) - iVar3;
        **(int **)(in_ECX + 0x24) = **(int **)(in_ECX + 0x24) + iVar3;
        goto LAB_007815a9;
      }
    }
    else if ((-1 < param_4) && (param_4 <= *(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x10))) {
      iVar3 = (**(int **)(in_ECX + 0x10) - **(int **)(in_ECX + 0x20)) + param_4;
      **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) - iVar3;
      **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + iVar3;
      if ((in_stack_00000020 & 2) != 0) {
        iVar3 = **(int **)(in_ECX + 0x24);
        if (iVar3 != 0) {
          iVar1 = **(int **)(in_ECX + 0x20);
          iVar2 = **(int **)(in_ECX + 0x34);
          **(int **)(in_ECX + 0x24) = iVar1;
          **(int **)(in_ECX + 0x34) = (iVar2 + iVar3) - iVar1;
        }
      }
      goto LAB_007815a9;
    }
    param_4 = -1;
  }
LAB_007815a9:
  *param_1 = param_4;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = param_4 >> 0x1f;
  return param_1;
}

