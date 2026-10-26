
undefined4 * FUN_00786380(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00891268(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = gbKey<float>::vftable;
    puVar1[1] = *(undefined4 *)(in_ECX + 4);
    puVar1[2] = *(undefined4 *)(in_ECX + 8);
    puVar1[3] = *(undefined4 *)(in_ECX + 0xc);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

