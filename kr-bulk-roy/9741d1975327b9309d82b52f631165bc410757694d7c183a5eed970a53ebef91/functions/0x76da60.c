
undefined4 * FUN_0076da60(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0xc);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    *puVar1 = FoxUI::FXUIDockInfo::vftable;
    puVar1[2] = 6;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

