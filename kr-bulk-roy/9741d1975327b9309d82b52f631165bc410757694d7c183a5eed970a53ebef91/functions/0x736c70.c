
undefined4 FUN_00736c70(int param_1)

{
  int iVar1;
  int unaff_EDI;
  
  FUN_00736f40(&param_1);
  iVar1 = param_1;
  if (param_1 != *(int *)(unaff_EDI + 0xc)) {
    (**(code **)(**(int **)(param_1 + 0x28) + 4))();
    return *(undefined4 *)(iVar1 + 0x28);
  }
  return 0;
}

