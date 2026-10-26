
undefined4 FUN_00844510(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int in_ECX;
  
  FUN_00515790(param_2);
  if (param_1 != *(int *)(param_1 * 0x10 + in_ECX + 0xe8)) {
    *param_3 = *(undefined4 *)(param_1 + 0x10);
    *param_4 = *(undefined4 *)(param_1 + 0x14);
    return 1;
  }
  return 0;
}

