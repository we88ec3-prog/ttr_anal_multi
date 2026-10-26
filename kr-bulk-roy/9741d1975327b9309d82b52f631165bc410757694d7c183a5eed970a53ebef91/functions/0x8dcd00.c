
undefined4 FUN_008dcd00(int param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x290);
  *param_2 = 0;
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x5b0) != 0xffff)) {
    *param_2 = 1;
  }
  return 0;
}

