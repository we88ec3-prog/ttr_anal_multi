
undefined4 FUN_006f6060(void)

{
  char cVar1;
  char *in_EAX;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  do {
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
  puVar2 = (undefined4 *)(*(int *)(in_ECX + 8) + -0x10);
  if ((puVar2 != &DAT_00c0bfc8) && (*(int *)(*(int *)(in_ECX + 8) + -8) == 0)) {
    *(undefined4 **)(in_ECX + 8) = puVar2;
    if (*(uint *)(*(int *)(in_ECX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_ECX + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    puVar2 = *(undefined4 **)(in_ECX + 8);
    uVar3 = FUN_006f99a0();
    *puVar2 = uVar3;
    puVar2[2] = 5;
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
    puVar2 = *(undefined4 **)(in_ECX + 8);
    *puVar2 = puVar2[-4];
    puVar2[1] = puVar2[-3];
    puVar2[2] = puVar2[-2];
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 0x10;
    FUN_006f5790();
    return 1;
  }
  return 0;
}

