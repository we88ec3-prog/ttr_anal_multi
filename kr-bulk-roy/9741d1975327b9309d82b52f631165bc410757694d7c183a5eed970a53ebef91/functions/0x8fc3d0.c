
undefined4 FUN_008fc3d0(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 == (undefined4 *)0x0) {
    return 0x21;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 6;
  }
  FUN_008b9f80(*param_1,param_2[3]);
  param_2[3] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  return 0;
}

