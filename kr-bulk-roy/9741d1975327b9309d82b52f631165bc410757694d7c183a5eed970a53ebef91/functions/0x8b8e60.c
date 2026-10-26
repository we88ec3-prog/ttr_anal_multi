
undefined4 FUN_008b8e60(int *param_1)

{
  int iVar1;
  
  if (((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) && (*(int *)(iVar1 + 0x60) != 0))
  {
    *(int **)(iVar1 + 0x58) = param_1;
    return 0;
  }
  return 6;
}

