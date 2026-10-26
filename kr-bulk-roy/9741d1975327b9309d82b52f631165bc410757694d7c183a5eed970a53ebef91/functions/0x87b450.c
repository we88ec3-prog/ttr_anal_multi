
bool FUN_0087b450(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  if ((param_5 != 0) && (*(int **)(param_5 + 0x3c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_5 + 0x3c) + 4))();
    if (*(int *)(iVar1 + 4) == -0x5ece0000) {
      iVar1 = (**(code **)(*param_2 + 0x78))
                        (param_2,param_3,*(undefined4 *)(*(int *)(param_5 + 0x3c) + 0x1cc));
      return iVar1 == 0;
    }
  }
  return false;
}

