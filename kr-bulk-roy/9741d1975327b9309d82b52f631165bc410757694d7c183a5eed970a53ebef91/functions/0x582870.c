
void FUN_00582870(void)

{
  wchar_t *pwVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090abce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  switch(DAT_00fb90d1) {
  case 2:
  case 4:
    pwVar1 = L"PMingLiU";
    PTR_DAT_00d6a230 = (undefined *)pwVar1;
    PTR_DAT_00d6a234 = (undefined *)pwVar1;
    PTR_DAT_00d6a238 = (undefined *)pwVar1;
    PTR_DAT_00d6a23c = (undefined *)pwVar1;
    PTR_DAT_00d6a240 = (undefined *)pwVar1;
    PTR_DAT_00d6a244 = (undefined *)pwVar1;
    PTR_DAT_00d6a248 = (undefined *)pwVar1;
    break;
  case 3:
    pwVar1 = L"Ume UI Gothic";
    PTR_DAT_00d6a230 = (undefined *)pwVar1;
    PTR_DAT_00d6a234 = (undefined *)pwVar1;
    PTR_DAT_00d6a238 = (undefined *)pwVar1;
    PTR_DAT_00d6a23c = (undefined *)pwVar1;
    PTR_DAT_00d6a240 = (undefined *)pwVar1;
    PTR_DAT_00d6a244 = (undefined *)pwVar1;
    PTR_DAT_00d6a248 = (undefined *)pwVar1;
    break;
  case 5:
    pwVar1 = L"Microsoft Sans Serif";
    PTR_DAT_00d6a230 = (undefined *)pwVar1;
    PTR_DAT_00d6a234 = (undefined *)pwVar1;
    PTR_DAT_00d6a238 = (undefined *)pwVar1;
    PTR_DAT_00d6a23c = (undefined *)pwVar1;
    PTR_DAT_00d6a240 = (undefined *)pwVar1;
    PTR_DAT_00d6a244 = (undefined *)pwVar1;
    PTR_DAT_00d6a248 = (undefined *)pwVar1;
    break;
  case 6:
    pwVar1 = L"Simsun";
    PTR_DAT_00d6a230 = (undefined *)pwVar1;
    PTR_DAT_00d6a234 = (undefined *)pwVar1;
    PTR_DAT_00d6a238 = (undefined *)pwVar1;
    PTR_DAT_00d6a23c = (undefined *)pwVar1;
    PTR_DAT_00d6a240 = (undefined *)pwVar1;
    PTR_DAT_00d6a244 = (undefined *)pwVar1;
    PTR_DAT_00d6a248 = (undefined *)pwVar1;
    break;
  case 7:
    pwVar1 = L"Lucida Sans Unicode";
    PTR_DAT_00d6a230 = (undefined *)pwVar1;
    PTR_DAT_00d6a234 = (undefined *)pwVar1;
    PTR_DAT_00d6a238 = (undefined *)pwVar1;
    PTR_DAT_00d6a23c = (undefined *)pwVar1;
    PTR_DAT_00d6a240 = (undefined *)pwVar1;
    PTR_DAT_00d6a244 = (undefined *)pwVar1;
    PTR_DAT_00d6a248 = (undefined *)pwVar1;
  }
  ExceptionList = local_10;
  return;
}

