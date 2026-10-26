
int FUN_0049f420(wchar_t *param_1)

{
  wchar_t *_Str1;
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  uint uVar3;
  
  iVar1 = *unaff_ESI;
  uVar3 = 0;
  if (unaff_ESI[1] - iVar1 >> 6 != 0) {
    iVar2 = 0;
    do {
      _Str1 = (wchar_t *)(iVar1 + iVar2);
      if (7 < *(uint *)(_Str1 + 10)) {
        _Str1 = *(wchar_t **)_Str1;
      }
      iVar1 = _wcsncmp(_Str1,param_1,4);
      if (iVar1 == 0) {
        return uVar3 * 0x40 + *unaff_ESI;
      }
      iVar1 = *unaff_ESI;
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x40;
    } while (uVar3 < (uint)(unaff_ESI[1] - iVar1 >> 6));
  }
  return 0;
}

