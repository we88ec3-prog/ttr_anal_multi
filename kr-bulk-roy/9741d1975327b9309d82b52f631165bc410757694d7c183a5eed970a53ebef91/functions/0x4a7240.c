
void FUN_004a7240(void)

{
  wchar_t wVar1;
  short sVar2;
  wchar_t *pwVar3;
  int in_ECX;
  int iVar4;
  wchar_t *in_EDX;
  short *psVar5;
  wchar_t *local_258 [6];
  uint local_240;
  undefined4 local_238;
  undefined4 local_228;
  uint local_224;
  wchar_t local_21c [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e4b6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_258[0] = (wchar_t *)0x0;
  pwVar3 = _wcsstr(in_EDX,L"%");
  _wcsstr(in_EDX,L"10x");
  iVar4 = (int)local_21c - (int)in_EDX;
  do {
    wVar1 = *in_EDX;
    *(wchar_t *)(iVar4 + (int)in_EDX) = wVar1;
    in_EDX = in_EDX + 1;
  } while (wVar1 != L'\0');
  local_258[0] = (wchar_t *)0x0;
  _wcstok_s(local_21c,L"(",local_258);
  if (local_258[0] != (wchar_t *)0x0) {
    *local_258[0] = L'\0';
  }
  psVar5 = &DAT_00c02bac;
  if (in_ECX < 0) {
    psVar5 = &DAT_00bed1fc;
  }
  local_238 = (uint)local_238._2_2_ << 0x10;
  local_228 = 0;
  local_224 = 7;
  do {
    sVar2 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar2 != 0);
  FUN_00402160();
  local_8 = 0;
  FUN_0040ef80();
  local_8._0_1_ = 1;
  FUN_004041f0();
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_240) {
    FUN_0089120c();
  }
  psVar5 = &DAT_00c02ba8;
  if (pwVar3 == (wchar_t *)0x0) {
    psVar5 = &DAT_00bed1fc;
  }
  do {
    sVar2 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar2 != 0);
  FUN_00404300();
  FUN_004026e0(&local_238,0,0xffffffff);
  FUN_004796c0(local_21c);
  if (7 < local_224) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

