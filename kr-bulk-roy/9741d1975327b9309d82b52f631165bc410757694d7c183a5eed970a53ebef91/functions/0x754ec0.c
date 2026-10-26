
bool FUN_00754ec0(wchar_t *param_1)

{
  wchar_t *_Str1;
  int iVar1;
  int in_ECX;
  
  _Str1 = (wchar_t *)(in_ECX + 0xcc);
  if (7 < *(uint *)(in_ECX + 0xe0)) {
    _Str1 = *(wchar_t **)_Str1;
  }
  iVar1 = __wcsicmp(_Str1,param_1);
  return iVar1 == 0;
}

