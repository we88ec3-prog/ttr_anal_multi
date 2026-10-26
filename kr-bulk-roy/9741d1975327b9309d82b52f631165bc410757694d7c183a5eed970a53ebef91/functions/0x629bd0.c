
void FUN_00629bd0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)(param_1 + 0x24c);
  do {
    if ((*(char *)(param_1 + 0x254) == '\0') || (uVar3 != 0)) {
      if (uVar3 < (uint)(param_2[1] - *param_2 >> 2)) {
        FUN_00628e70();
      }
      else {
        iVar1 = *piVar2;
        *(undefined4 *)(iVar1 + 0x250) = 0;
        *(undefined4 *)(iVar1 + 0x254) = 0;
        FUN_00757710();
      }
      if ((*(char *)(param_1 + 0x254) != '\0') && (*param_2 != param_2[1])) {
        FUN_00628e70();
      }
    }
    uVar3 = uVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (uVar3 < 2);
  if (*(char *)(param_1 + 0x254) != '\0') {
    (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(1);
    return;
  }
  if (*param_2 == param_2[1]) {
    (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(0);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(1);
  return;
}

