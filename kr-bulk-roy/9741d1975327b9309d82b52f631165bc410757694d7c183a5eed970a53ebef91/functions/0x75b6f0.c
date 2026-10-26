
undefined2 * FUN_0075b6f0(undefined2 *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x44);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 10) = 7;
    *(undefined4 *)(param_1 + 8) = 0;
    *param_1 = 0;
    FUN_004026e0(iVar1 + 0xa0,0,0xffffffff);
    return param_1;
  }
  FUN_0040ed30(param_1);
  return param_1;
}

