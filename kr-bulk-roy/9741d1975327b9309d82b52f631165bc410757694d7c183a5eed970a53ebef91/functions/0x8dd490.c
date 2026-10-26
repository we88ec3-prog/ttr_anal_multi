
int FUN_008dd490(void)

{
  int iVar1;
  undefined4 *in_ECX;
  int unaff_ESI;
  
  if (*(char *)*in_ECX == '\x1e') {
    iVar1 = FUN_008dd160(in_ECX[1]);
    return iVar1;
  }
  iVar1 = FUN_008dd0c0();
  if (unaff_ESI != 0) {
    iVar1 = iVar1 * *(int *)(&DAT_00be9358 + unaff_ESI * 4);
  }
  if (0x7fff < iVar1) {
    return 0x7fffffff;
  }
  if (iVar1 < -0x7fff) {
    return -0x7fffffff;
  }
  return iVar1 << 0x10;
}

