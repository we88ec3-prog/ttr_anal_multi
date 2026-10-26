
bool FUN_008eba80(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (unaff_ESI == 0) {
    return false;
  }
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    cVar1 = FUN_008eb830();
    if (cVar1 != '\0') {
      return true;
    }
  }
  cVar1 = FUN_008eb930();
  return cVar1 != '\0';
}

