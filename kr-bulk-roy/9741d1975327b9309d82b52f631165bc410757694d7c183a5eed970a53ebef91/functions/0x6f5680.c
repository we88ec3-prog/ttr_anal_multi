
void FUN_006f5680(void)

{
  char cVar1;
  int unaff_ESI;
  char *unaff_EDI;
  
  FUN_006f50f0();
  do {
    cVar1 = *unaff_EDI;
    unaff_EDI = unaff_EDI + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}

