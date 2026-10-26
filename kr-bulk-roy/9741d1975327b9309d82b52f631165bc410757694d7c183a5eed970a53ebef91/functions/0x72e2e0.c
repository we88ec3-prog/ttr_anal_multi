
int FUN_0072e2e0(char *param_1)

{
  int iVar1;
  int in_EAX;
  char *_Str1;
  int iVar2;
  
  iVar1 = *(int *)(in_EAX + 0x18);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    _Str1 = (char *)(iVar1 + 0x20);
    if (0xf < *(uint *)(iVar1 + 0x34)) {
      _Str1 = *(char **)_Str1;
    }
    iVar2 = __stricmp(_Str1,param_1);
    if (iVar2 == 0) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}

