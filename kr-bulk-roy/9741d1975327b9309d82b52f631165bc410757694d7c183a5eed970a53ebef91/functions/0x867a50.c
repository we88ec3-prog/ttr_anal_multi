
undefined4 * FUN_00867a50(undefined4 *param_1)

{
  *param_1 = gbParam::vftable;
  param_1[1] = 4;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_008673c0();
  if (param_1[2] != 0) {
    FUN_00891d3d(param_1[2]);
    param_1[2] = 0;
  }
  FUN_008673c0();
  return param_1;
}

