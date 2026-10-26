
undefined4 * FUN_007863b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = gbKey<float>::vftable;
    puVar1[1] = *(undefined4 *)(in_ECX + 4);
    puVar1[2] = *(undefined4 *)(in_ECX + 8);
    puVar1[3] = *(undefined4 *)(in_ECX + 0xc);
    *puVar1 = gbTCBKey<float>::vftable;
    puVar1[4] = *(undefined4 *)(in_ECX + 0x10);
    puVar1[5] = *(undefined4 *)(in_ECX + 0x14);
    puVar1[6] = *(undefined4 *)(in_ECX + 0x18);
    puVar1[7] = *(undefined4 *)(in_ECX + 0x1c);
    puVar1[8] = *(undefined4 *)(in_ECX + 0x20);
    puVar1[9] = *(undefined4 *)(in_ECX + 0x24);
    puVar1[10] = *(undefined4 *)(in_ECX + 0x28);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

