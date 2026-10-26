
void FUN_00413960(void)

{
  undefined4 *puVar1;
  undefined4 in_ECX;
  
  FUN_00745930();
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = in_ECX;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf4350;
    *puVar1 = FoxUI::FXUIEventP1::vftable;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

