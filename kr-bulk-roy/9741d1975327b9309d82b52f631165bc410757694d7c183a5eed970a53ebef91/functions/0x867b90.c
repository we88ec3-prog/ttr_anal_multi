
undefined4 * FUN_00867b90(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  *param_1 = gbParam::vftable;
  param_1[1] = 7;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_008673c0();
  if (param_1[2] == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0x3f800000;
    }
    param_1[2] = puVar1;
  }
  puVar1 = (undefined4 *)param_1[2];
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  puVar1[3] = param_2[3];
  return param_1;
}

