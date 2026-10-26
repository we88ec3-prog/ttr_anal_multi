
void FUN_0041b130(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xf4) + 0xd4))();
  FUN_0041ccf0();
  puVar1 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf441e;
    *puVar1 = FoxUI::FXUIEventI2::vftable;
    puVar1[5] = 1;
    puVar1[6] = 0;
    FUN_004072a0();
    FUN_004067f0();
    return;
  }
  FUN_004072a0();
  FUN_004067f0();
  return;
}

