
undefined4 * FUN_007700f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x34);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::CReferenceFontItemImpl::vftable;
    puVar1[3] = 0;
    puVar1[9] = 7;
    puVar1[8] = 0;
    *(undefined2 *)(puVar1 + 4) = 0;
    puVar1[0xb] = 0;
    *(undefined1 *)(puVar1 + 0xc) = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

