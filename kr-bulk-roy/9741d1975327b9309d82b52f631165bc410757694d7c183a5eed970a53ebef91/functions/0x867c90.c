
undefined4 * FUN_00867c90(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = gbParam::vftable;
  param_1[1] = 9;
  param_1[2] = 0;
  param_1[3] = 0;
  FUN_008673c0();
  if (param_1[2] == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x44);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      _memset(puVar1,0,0x44);
      puVar1[0xf] = 0x3f800000;
      puVar1[10] = 0x3f800000;
      puVar1[5] = 0x3f800000;
      *puVar1 = 0x3f800000;
    }
    param_1[2] = puVar1;
  }
  puVar1 = (undefined4 *)param_1[2];
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  return param_1;
}

