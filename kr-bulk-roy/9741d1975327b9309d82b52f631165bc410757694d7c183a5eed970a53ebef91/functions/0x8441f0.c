
undefined4 FUN_008441f0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int in_ECX;
  
  FUN_00515790(param_1);
  if (param_1 != *(int *)(in_ECX + 0x58)) {
    *param_2 = *(undefined4 *)(param_1 + 0x10);
    *param_3 = *(undefined4 *)(param_1 + 0x14);
    return 1;
  }
  return 0;
}

