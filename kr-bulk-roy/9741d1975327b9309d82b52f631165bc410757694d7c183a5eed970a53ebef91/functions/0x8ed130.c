
void FUN_008ed130(void)

{
  char cVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = 1;
  do {
    cVar1 = FUN_008ed050();
    if (cVar1 == '\x01') {
      return;
    }
    if (*(char *)(unaff_EDI + 0x170) == 'X') {
      iVar2 = iVar2 + 1;
    }
    else if (*(char *)(unaff_EDI + 0x170) == 'Y') {
      iVar2 = iVar2 + -1;
    }
  } while (iVar2 != 0);
  return;
}

