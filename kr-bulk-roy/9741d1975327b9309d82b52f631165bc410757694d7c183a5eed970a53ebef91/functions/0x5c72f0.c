
int * FUN_005c72f0(int *param_1)

{
  wchar_t *in_EAX;
  int iVar1;
  wchar_t *_Str2;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = FUN_005c7610();
  if (iVar1 != *(int *)(unaff_ESI + 4)) {
    _Str2 = (wchar_t *)(iVar1 + 0xc);
    if (7 < *(uint *)(iVar1 + 0x20)) {
      _Str2 = *(wchar_t **)_Str2;
    }
    if (7 < *(uint *)(in_EAX + 10)) {
      in_EAX = *(wchar_t **)in_EAX;
    }
    iVar2 = __wcsicmp(in_EAX,_Str2);
    if (iVar2 < 1) {
      *param_1 = iVar1;
      return param_1;
    }
  }
  *param_1 = *(int *)(unaff_ESI + 4);
  return param_1;
}

