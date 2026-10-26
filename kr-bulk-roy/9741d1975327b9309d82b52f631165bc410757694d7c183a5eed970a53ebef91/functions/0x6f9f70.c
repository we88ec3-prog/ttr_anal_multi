
void FUN_006f9f70(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) & 0xfc;
  uVar2 = *(byte *)(param_2 + 4) - 4;
  if (6 < uVar2) {
    return;
  }
switchD_006f9f90_switchD:
  switch(uVar2) {
  case 1:
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    return;
  case 2:
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    return;
  case 3:
    goto switchD_006f9f90_caseD_3;
  case 4:
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    return;
  case 5:
    *(undefined4 *)(param_2 + 0x44) = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    break;
  case 6:
    if ((3 < (*(int **)(param_2 + 8))[2]) &&
       (iVar1 = **(int **)(param_2 + 8), (*(byte *)(iVar1 + 5) & 3) != 0)) {
      FUN_006f9f70(param_1,iVar1);
    }
    if (*(int *)(param_2 + 8) == param_2 + 0x10) {
      *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) | 4;
      return;
    }
  }
  return;
switchD_006f9f90_caseD_3:
  iVar1 = *(int *)(param_2 + 8);
  *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) | 4;
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 5) & 3) != 0)) {
    FUN_006f9f70(param_1,iVar1);
  }
  param_2 = *(int *)(param_2 + 0xc);
  if ((*(byte *)(param_2 + 5) & 3) == 0) {
    return;
  }
  *(byte *)(param_2 + 5) = *(byte *)(param_2 + 5) & 0xfc;
  uVar2 = *(byte *)(param_2 + 4) - 4;
  if (6 < uVar2) {
    return;
  }
  goto switchD_006f9f90_switchD;
}

