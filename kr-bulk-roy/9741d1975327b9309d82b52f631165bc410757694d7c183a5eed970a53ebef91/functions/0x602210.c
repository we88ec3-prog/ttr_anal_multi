
void FUN_00602210(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4436;
    *puVar1 = FoxUI::FXUIEventI2::vftable;
    puVar1[5] = param_1;
    puVar1[6] = param_2;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

