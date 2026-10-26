
bool FUN_00757130(wchar_t *param_1)

{
  wchar_t *_Str1;
  int iVar1;
  int in_ECX;
  
  _Str1 = (wchar_t *)(in_ECX + 0x84);
  if (7 < *(uint *)(in_ECX + 0x98)) {
    _Str1 = *(wchar_t **)_Str1;
  }
  iVar1 = __wcsicmp(_Str1,param_1);
  return iVar1 == 0;
}

