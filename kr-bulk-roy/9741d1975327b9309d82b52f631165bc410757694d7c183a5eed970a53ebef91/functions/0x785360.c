
undefined4 * FUN_00785360(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)FUN_00891268(0x1c);
  if (puVar2 != (undefined4 *)0x0) {
    puVar1 = puVar2 + 1;
    *puVar2 = gbKey<gbQuat>::vftable;
    *puVar1 = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0x3f800000;
    if (puVar1 != (undefined4 *)(in_ECX + 4)) {
      puVar2[4] = *(undefined4 *)(in_ECX + 0x10);
      *puVar1 = *(undefined4 *)(in_ECX + 4);
      puVar2[2] = *(undefined4 *)(in_ECX + 8);
      puVar2[3] = *(undefined4 *)(in_ECX + 0xc);
    }
    puVar2[5] = *(undefined4 *)(in_ECX + 0x14);
    puVar2[6] = *(undefined4 *)(in_ECX + 0x18);
    return puVar2;
  }
  return (undefined4 *)0x0;
}

