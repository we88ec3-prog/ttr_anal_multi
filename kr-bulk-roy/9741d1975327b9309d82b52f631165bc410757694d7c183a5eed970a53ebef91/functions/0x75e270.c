
undefined4 FUN_0075e270(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  
  if (*(int *)(in_ECX + 0x24) == 0) {
    return 0;
  }
  if (*(char *)(in_ECX + 0xd4) == '\0') {
    iVar2 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) + *(int *)(in_ECX + 0xbc) * -2;
  }
  else {
    iVar2 = (*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0xbc) * -2) - *(int *)(in_ECX + 8);
  }
  if ((0 < iVar2) && (0 < iVar2)) {
    uVar1 = FUN_008fed10();
    return uVar1;
  }
  return 0;
}

