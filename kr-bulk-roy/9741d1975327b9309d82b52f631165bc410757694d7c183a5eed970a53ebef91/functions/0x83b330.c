
undefined4 FUN_0083b330(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_0083eb60(&param_3,param_3);
  if (iVar1 != 0) {
    if (0xf < (uint)param_3[5]) {
      param_3 = (undefined4 *)*param_3;
    }
    *param_2 = param_3;
    return 1;
  }
  return 0;
}

