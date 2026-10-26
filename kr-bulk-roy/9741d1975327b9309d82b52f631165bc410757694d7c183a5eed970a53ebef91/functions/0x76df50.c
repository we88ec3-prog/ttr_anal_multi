
undefined4 * FUN_0076df50(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    puVar1[2] = 6;
    *puVar1 = FoxUI::FXUIDockInfoGuide::vftable;
    puVar1[6] = 0;
    puVar1[5] = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[7] = 6;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

