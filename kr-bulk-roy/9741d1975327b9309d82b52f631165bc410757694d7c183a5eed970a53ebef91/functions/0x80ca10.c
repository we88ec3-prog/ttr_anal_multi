
int FUN_0080ca10(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x44) == 0) {
    return -0x7fffbffd;
  }
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (iVar1 < 0) {
LAB_0080ca37:
      iVar1 = -0x7fffbffb;
    }
    else {
      iVar1 = (**(code **)(**(int **)(unaff_EDI + iVar2 * 4) + 0x10))();
      if (iVar1 < 0) goto LAB_0080ca37;
      iVar1 = 0;
    }
    iVar2 = iVar2 + 1;
    if (0xf < iVar2) {
      return iVar1;
    }
  } while( true );
}

