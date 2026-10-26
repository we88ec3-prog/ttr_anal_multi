
void FUN_008673c0(void)

{
  char cVar1;
  char *pcVar2;
  int *unaff_ESI;
  char *unaff_EDI;
  
  if (*unaff_ESI != 0) {
    FUN_00891d3d(*unaff_ESI);
    *unaff_ESI = 0;
  }
  if (unaff_EDI != (char *)0x0) {
    pcVar2 = unaff_EDI;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = (char *)FUN_0087dc3d(pcVar2 + (1 - (int)(unaff_EDI + 1)));
    *unaff_ESI = (int)pcVar2;
    do {
      cVar1 = *unaff_EDI;
      *pcVar2 = cVar1;
      unaff_EDI = unaff_EDI + 1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}

