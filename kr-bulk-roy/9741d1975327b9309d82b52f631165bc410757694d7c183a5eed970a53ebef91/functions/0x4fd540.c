
int FUN_004fd540(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  wchar_t *_Str1;
  int *unaff_EDI;
  int local_8;
  
  iVar2 = *unaff_EDI;
  iVar1 = unaff_EDI[1] - iVar2 >> 0x1f;
  uVar3 = 0;
  if ((unaff_EDI[1] - iVar2) / 0x58 + iVar1 != iVar1) {
    local_8 = 0;
    do {
      _Str1 = (wchar_t *)(iVar2 + local_8);
      if (7 < *(uint *)(_Str1 + 10)) {
        _Str1 = *(wchar_t **)_Str1;
      }
      iVar2 = _wcsncmp(_Str1,param_1,4);
      if (iVar2 == 0) {
        return uVar3 * 0x58 + *unaff_EDI;
      }
      iVar2 = *unaff_EDI;
      local_8 = local_8 + 0x58;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)((unaff_EDI[1] - iVar2) / 0x58));
  }
  return 0;
}

