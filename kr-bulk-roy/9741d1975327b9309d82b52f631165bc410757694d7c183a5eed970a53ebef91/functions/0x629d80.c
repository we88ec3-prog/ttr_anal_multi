
void FUN_00629d80(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint local_8;
  
  local_8 = 0;
  piVar2 = (int *)(param_1 + 0x24c);
  do {
    if (local_8 < (uint)(param_2[1] - *param_2 >> 2)) {
      FUN_00628f40();
    }
    else {
      iVar1 = *piVar2;
      *(undefined4 *)(iVar1 + 0x250) = 0;
      *(undefined4 *)(iVar1 + 0x254) = 0;
      FUN_00757710();
    }
    local_8 = local_8 + 1;
    piVar2 = piVar2 + 1;
  } while (local_8 < 2);
  if (*param_2 == param_2[1]) {
    (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(0);
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x250) + 0x90))(1);
  return;
}

