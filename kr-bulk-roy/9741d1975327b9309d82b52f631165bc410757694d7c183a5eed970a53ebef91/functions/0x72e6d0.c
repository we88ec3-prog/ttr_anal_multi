
bool FUN_0072e6d0(undefined1 param_1)

{
  undefined4 in_EAX;
  int iVar1;
  char *_Str1;
  
  iVar1 = FUN_007300a0(in_EAX);
  if (iVar1 != 0) {
    _Str1 = (char *)(iVar1 + 0x30);
    if (0xf < *(uint *)(iVar1 + 0x44)) {
      _Str1 = *(char **)_Str1;
    }
    if (_Str1 != (char *)0x0) {
      iVar1 = __stricmp(_Str1,"true");
      return iVar1 == 0;
    }
  }
  return (bool)param_1;
}

