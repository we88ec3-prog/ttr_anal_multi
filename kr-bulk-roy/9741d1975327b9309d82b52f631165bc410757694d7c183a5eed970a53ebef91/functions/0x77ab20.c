
undefined4 * FUN_0077ab20(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x54);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = 0;
    *puVar1 = FoxUI::FXUIBackgroundPattern::vftable;
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[1] = DAT_00fba828;
    puVar1[4] = 0;
    puVar1[3] = FoxUI::FXUIImageSetItemLink::vftable;
    puVar1[9] = 0;
    puVar1[10] = 7;
    *(undefined2 *)(puVar1 + 5) = 0;
    puVar1[0x11] = 7;
    puVar1[0x10] = 0;
    *(undefined2 *)(puVar1 + 0xc) = 0;
    puVar1[0x14] = 0;
    *(undefined1 *)(puVar1 + 0x13) = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

