
undefined4 * FUN_007655f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    puVar1[2] = 0;
    *puVar1 = FoxUI::FXUIBackgroundColor::vftable;
    puVar1[3] = 0xff000000;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

