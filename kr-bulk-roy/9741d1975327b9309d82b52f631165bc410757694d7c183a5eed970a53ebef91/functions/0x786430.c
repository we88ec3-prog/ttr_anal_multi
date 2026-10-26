
undefined4 * FUN_00786430(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00891268(0x18);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = gbKey<gbVec3<float>_>::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[1] = *(undefined4 *)(in_ECX + 4);
    puVar1[2] = *(undefined4 *)(in_ECX + 8);
    puVar1[3] = *(undefined4 *)(in_ECX + 0xc);
    puVar1[4] = *(undefined4 *)(in_ECX + 0x10);
    puVar1[5] = *(undefined4 *)(in_ECX + 0x14);
    return puVar1;
  }
  return (undefined4 *)0x0;
}

