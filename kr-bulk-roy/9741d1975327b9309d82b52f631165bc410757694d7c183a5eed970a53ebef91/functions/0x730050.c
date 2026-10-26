
int FUN_00730050(int param_1)

{
  int iVar1;
  char *_Str2;
  int iVar2;
  char *_Str1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  while( true ) {
    if (iVar1 == param_1) {
      return 0;
    }
    if (*(uint *)(iVar1 + 0x28) < 0x10) {
      _Str1 = (char *)(iVar1 + 0x14);
    }
    else {
      _Str1 = *(char **)(iVar1 + 0x14);
    }
    _Str2 = (char *)FUN_00403030();
    iVar2 = __stricmp(_Str1,_Str2);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x50);
  }
  return iVar1;
}

