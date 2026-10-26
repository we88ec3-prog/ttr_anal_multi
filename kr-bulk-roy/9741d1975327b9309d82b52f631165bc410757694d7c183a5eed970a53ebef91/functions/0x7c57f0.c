
undefined4 FUN_007c57f0(int param_1)

{
  int iVar1;
  int in_ECX;
  int unaff_EDI;
  
  FUN_0082ef00(&param_1);
  if (in_ECX != *(int *)(unaff_EDI + 0xd8)) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
    if (iVar1 == param_1) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 0x24))();
      return 1;
    }
  }
  return 0;
}

