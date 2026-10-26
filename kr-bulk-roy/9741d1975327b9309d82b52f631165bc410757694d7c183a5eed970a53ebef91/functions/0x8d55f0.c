
undefined4 FUN_008d55f0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_008d3fa0(param_2);
  if (iVar1 == 0) {
    return 6;
  }
  if (*(char *)(iVar1 + 4) != '\0') {
    *param_3 = 1;
    param_3[1] = *(undefined4 *)(iVar1 + 8);
    return 0;
  }
  *param_3 = 2;
  param_3[1] = *(undefined4 *)(iVar1 + 8);
  return 0;
}

