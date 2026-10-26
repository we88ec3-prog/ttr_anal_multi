
void FUN_005f5d20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = FUI::QUANTITYDATA_INVENBANK::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  puVar1[3] = param_5;
  puVar1[4] = param_6;
  puVar1[1] = param_7;
  puVar1[2] = param_8;
  puVar2 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[5] = param_2;
    puVar2[6] = param_3;
    puVar2[9] = puVar1;
    puVar2[3] = 0;
    puVar2[4] = 0xf4310;
    *puVar2 = FoxUI::FXUIEventI4P2::vftable;
    puVar2[7] = 1;
    puVar2[8] = param_4;
    puVar2[10] = param_1;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

