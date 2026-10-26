
undefined4 FUN_006f6470(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  FUN_006f5510();
  puVar2 = (undefined4 *)FUN_006f9c50();
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar2;
  *(undefined4 *)(iVar1 + -0xc) = puVar2[1];
  *(undefined4 *)(iVar1 + -8) = puVar2[2];
  puVar2 = *(undefined4 **)(in_ECX + 8);
  if ((puVar2 != (undefined4 *)&DAT_00c0bfd8) && (puVar2[-2] == 0)) {
    *(undefined4 **)(in_ECX + 8) = puVar2 + -8;
    return 0;
  }
  puVar3 = puVar2 + -4;
  if (puVar3 < puVar2) {
    puVar2 = puVar2 + -8;
    do {
      *puVar2 = *puVar3;
      puVar2[1] = puVar3[1];
      puVar2[2] = puVar2[6];
      puVar3 = puVar3 + 4;
      puVar2 = puVar2 + 4;
    } while (puVar3 < *(undefined4 **)(in_ECX + 8));
  }
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0x10;
  return 1;
}

