
undefined4 * FUN_007849c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00891268(0x60);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_007852a0();
    *puVar1 = gbTCBRotKey::vftable;
    puVar1[0x14] = *(undefined4 *)(in_ECX + 0x50);
    puVar1[0x15] = *(undefined4 *)(in_ECX + 0x54);
    puVar1[0x16] = *(undefined4 *)(in_ECX + 0x58);
    puVar1[0x17] = *(undefined4 *)(in_ECX + 0x5c);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

