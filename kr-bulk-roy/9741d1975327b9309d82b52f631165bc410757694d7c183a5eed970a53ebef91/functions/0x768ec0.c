
int FUN_00768ec0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x134);
  iVar4 = *(int *)(in_ECX + 0xa8) + *(int *)(in_ECX + 0x30);
  iVar2 = *(int *)(in_ECX + 0x13c);
  if ((iVar1 <= iVar2) && (iVar2 < *(int *)(in_ECX + 0x138) + iVar1)) {
    if (*(int *)(in_ECX + 0xf4) != 0) {
      iVar3 = FUN_008fed10();
      return (iVar2 - iVar1) * iVar3 + iVar4;
    }
    return iVar4;
  }
  return iVar4;
}

