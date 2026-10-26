
void FUN_0042d490(void)

{
  undefined4 *puVar1;
  
  FUN_004067f0();
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf435b;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

