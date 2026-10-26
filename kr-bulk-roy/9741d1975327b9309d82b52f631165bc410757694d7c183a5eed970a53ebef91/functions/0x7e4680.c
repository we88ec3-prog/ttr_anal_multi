
void FUN_007e4680(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = (*(int *)(unaff_EDI + 0x5c) - *(int *)(unaff_EDI + 0x58)) / 0x2c;
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      (**(code **)(**(int **)(iVar2 + 0x28 + *(int *)(unaff_EDI + 0x58)) + 0x3c))(param_1);
      iVar2 = iVar2 + 0x2c;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

