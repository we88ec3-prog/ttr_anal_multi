
undefined4 FUN_0073f880(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1;
  FUN_008438c0(&stack0x00000008);
  iVar2 = param_1;
  if (param_1 != *(int *)(iVar1 + 4)) {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x10) + 4))();
    if (iVar3 == 0) {
      iVar3 = *(int *)(iVar2 + 0x10);
      if (iVar3 != 0) {
        FUN_0073fde0(iVar3);
        FUN_0089120c(iVar3);
      }
      FUN_007b6890(iVar1,&param_1,iVar2);
      return 1;
    }
  }
  return 0;
}

