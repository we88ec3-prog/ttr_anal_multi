
void FUN_004138c0(void)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0xb0) = 0;
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = 0;
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[4] = 0xf43e3;
    FUN_004072a0();
    return;
  }
  FUN_004072a0();
  return;
}

