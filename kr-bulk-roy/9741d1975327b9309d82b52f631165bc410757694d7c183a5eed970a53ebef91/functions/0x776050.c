
undefined4 * FUN_00776050(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x14))(param_1,param_2,param_3);
    return param_1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}

