
int FUN_007300a0(char *param_1)

{
  int iVar1;
  char *_Str1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x50);
  while( true ) {
    if (iVar1 == unaff_EDI) {
      return 0;
    }
    _Str1 = (char *)(iVar1 + 0x14);
    if (0xf < *(uint *)(iVar1 + 0x28)) {
      _Str1 = *(char **)_Str1;
    }
    iVar2 = __stricmp(_Str1,param_1);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x50);
  }
  return iVar1;
}

