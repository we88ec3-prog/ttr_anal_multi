
int FUN_00730069(void)

{
  char *_Str2;
  int iVar1;
  int unaff_EBX;
  int unaff_ESI;
  char *unaff_EDI;
  
  while( true ) {
    _Str2 = (char *)FUN_00403030();
    iVar1 = __stricmp(unaff_EDI,_Str2);
    if (iVar1 == 0) {
      return unaff_ESI;
    }
    unaff_ESI = *(int *)(unaff_ESI + 0x50);
    if (unaff_ESI == unaff_EBX) break;
    if (*(uint *)(unaff_ESI + 0x28) < 0x10) {
      unaff_EDI = (char *)(unaff_ESI + 0x14);
    }
    else {
      unaff_EDI = *(char **)(unaff_ESI + 0x14);
    }
  }
  return 0;
}

