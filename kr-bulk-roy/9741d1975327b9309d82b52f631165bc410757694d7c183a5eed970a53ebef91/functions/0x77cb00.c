
undefined4 * FUN_0077cb00(void)

{
  undefined4 *puVar1;
  
  puVar1 = _malloc(0x40);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fba828 = DAT_00fba828 + 1;
    puVar1[7] = 0;
    puVar1[9] = 0;
    puVar1[1] = DAT_00fba828;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(undefined1 *)(puVar1 + 6) = 0;
    *puVar1 = FoxUI::FXUIBackgroundTextureAni::vftable;
    *(undefined1 *)(puVar1 + 0xf) = 1;
    *(undefined1 *)(puVar1 + 8) = 1;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

