
undefined4 * FUN_00777ad0(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    puVar1[2] = 0;
    *puVar1 = FoxUI::FXUIBackgroundColorLine::vftable;
    puVar1[3] = 0xff000000;
    puVar1[4] = 0xffff0000;
    puVar1[5] = 1;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

