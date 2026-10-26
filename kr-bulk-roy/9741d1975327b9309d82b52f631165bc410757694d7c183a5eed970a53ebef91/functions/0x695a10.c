
int FUN_00695a10(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x80) + 0xcc);
  if (iVar2 == 0) {
    iVar3 = 0;
    iVar2 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2;
    iVar2 = *(int *)(iVar2 + 0xd4);
  }
  iVar1 = *(int *)(in_ECX + 0x84);
  if (iVar1 < iVar2 * iVar3 + 10) {
    iVar2 = *(int *)(*(int *)(in_ECX + 0x80) + 0xcc);
    if (iVar2 != 0) {
      return *(int *)(iVar2 + 0xd4) * (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2) + 10;
    }
    iVar1 = 10;
  }
  return iVar1;
}

