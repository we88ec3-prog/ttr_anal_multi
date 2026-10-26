
undefined4 FUN_0083b2a0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = FUN_0083fd10(param_1,&param_1);
  if (iVar1 != 0) {
    if (0xf < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    *param_2 = param_1;
    return 1;
  }
  return 0;
}

