
undefined4 * FUN_00867ab0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  *param_1 = gbParam::vftable;
  param_1[1] = 5;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_008673c0();
  if (param_1[2] == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0xc);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
    }
    param_1[2] = puVar1;
  }
  puVar1 = (undefined4 *)param_1[2];
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  return param_1;
}

