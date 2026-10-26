
undefined4 * FUN_00867910(undefined4 *param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  *param_1 = gbParam::vftable;
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_008673c0();
  if (param_1[2] == 0) {
    uVar1 = FUN_00891268(1);
    param_1[2] = uVar1;
  }
  *(undefined1 *)param_1[2] = *param_2;
  return param_1;
}

