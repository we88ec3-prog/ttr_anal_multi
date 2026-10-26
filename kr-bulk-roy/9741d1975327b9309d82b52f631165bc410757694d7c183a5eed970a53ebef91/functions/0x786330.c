
undefined4 * FUN_00786330(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = (undefined4 *)FUN_00891268(0x18);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = gbKey<float>::vftable;
    puVar2[1] = *(undefined4 *)(in_ECX + 4);
    puVar2[2] = *(undefined4 *)(in_ECX + 8);
    puVar2[3] = *(undefined4 *)(in_ECX + 0xc);
    *puVar2 = gbBezKey<float>::vftable;
    puVar2[4] = *(undefined4 *)(in_ECX + 0x10);
    uVar1 = *(undefined4 *)(in_ECX + 0x14);
    puVar2[3] = 0;
    puVar2[5] = uVar1;
    return puVar2;
  }
  return (undefined4 *)0x0;
}

