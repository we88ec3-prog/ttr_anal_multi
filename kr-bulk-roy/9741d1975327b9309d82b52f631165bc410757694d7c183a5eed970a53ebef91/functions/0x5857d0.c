
undefined4 * FUN_005857d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = CISFontImpl::vftable;
    puVar1[1] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

