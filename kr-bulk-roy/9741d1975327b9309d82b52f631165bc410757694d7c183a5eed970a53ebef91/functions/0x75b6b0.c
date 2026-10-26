
undefined4 FUN_0075b6b0(wchar_t *param_1)

{
  wchar_t *_Str1;
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x44);
  if (iVar1 != 0) {
    _Str1 = (wchar_t *)(iVar1 + 0xa0);
    if (7 < *(uint *)(iVar1 + 0xb4)) {
      _Str1 = *(wchar_t **)_Str1;
    }
    iVar1 = __wcsicmp(_Str1,param_1);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}

