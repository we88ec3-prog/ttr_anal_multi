
undefined4 * FUN_006d6300(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00891268(100);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[7] = 0;
    puVar1[8] = 0xf;
    *(undefined1 *)(puVar1 + 3) = 0;
    puVar1[1] = 0;
    *puVar1 = CLoginModuleGSP::vftable;
    puVar1[0x10] = 0xf;
    puVar1[0xf] = 0;
    *(undefined1 *)(puVar1 + 0xb) = 0;
    puVar1[0x17] = 0xf;
    puVar1[0x16] = 0;
    *(undefined1 *)(puVar1 + 0x12) = 0;
    puVar1[10] = 1;
    puVar1[2] = 0x52;
    return puVar1;
  }
  return (undefined4 *)0x0;
}

