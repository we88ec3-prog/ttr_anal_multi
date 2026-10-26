
int FUN_008dd500(void)

{
  int iVar1;
  int iVar2;
  undefined4 *in_ECX;
  int iVar3;
  int *unaff_EBX;
  
  if (*(char *)*in_ECX == '\x1e') {
    iVar2 = FUN_008dd160(in_ECX[1],0);
    return iVar2;
  }
  iVar2 = FUN_008dd0c0();
  if (iVar2 < 0x8000) {
    *unaff_EBX = 0;
    return iVar2 << 0x10;
  }
  iVar3 = 5;
  do {
    if (iVar2 < *(int *)(&DAT_00be9358 + iVar3 * 4)) break;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  iVar1 = iVar3 + -5;
  if (0x7fff < iVar2 / *(int *)(&DAT_00be9358 + iVar1 * 4)) {
    *unaff_EBX = iVar3 + -4;
    iVar2 = FUN_008b7f40(iVar2,*(undefined4 *)(&DAT_00be9358 + (iVar3 + -4) * 4));
    return iVar2;
  }
  *unaff_EBX = iVar1;
  iVar2 = FUN_008b7f40(iVar2,*(undefined4 *)(&DAT_00be9358 + iVar1 * 4));
  return iVar2;
}

