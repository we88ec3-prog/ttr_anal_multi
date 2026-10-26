
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00587480(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009219d3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00faaddc = 0;
  _DAT_00faade0 = 0;
  _DAT_00faade4 = 0;
  local_8 = 0;
  uStack_7 = 0;
  DAT_00faadec = 0xffffffff;
  _DAT_00faadf0 = 0xffffffff;
  _DAT_00faadf4 = 0;
  _DAT_00faadf8 = 0;
  DAT_00faadfa = 0;
  local_14 = uVar1;
  _memset(&DAT_00faae14,0,0x100);
  _DAT_00faaf30 = 0xffffffff;
  _DAT_00faaf1c = 0;
  _DAT_00faaf18 = 0;
  _DAT_00faaf14 = 0;
  _DAT_00faaf20 = 0;
  DAT_00faaf22 = 0;
  _DAT_00faaf23 = 0;
  DAT_00faaf25 = 0;
  DAT_00faaf28 = 0xff;
  if ((_DAT_00fe6990 & 1) == 0) {
    _DAT_00fe6990 = _DAT_00fe6990 | 1;
    _DAT_00fe3540 = CISFontImplEntry::vftable;
  }
  if (((_DAT_00fe2890 & 1) == 0) && (_DAT_00fe2890 = _DAT_00fe2890 | 1, (_DAT_00fe37e8 & 1) == 0)) {
    _DAT_00fe37e8 = _DAT_00fe37e8 | 1;
    DAT_00fe37e4 = FoxUI::CReferenceFontImplEntry::vftable;
  }
  DAT_00fe2894 = &DAT_00fe3540;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0;
  }
  DAT_00faadfc = &DAT_00f94810;
  _DAT_00faae0c = FUN_0041f3e0();
  local_68 = FUN_00891268(0x14);
  local_8 = 2;
  if (local_68 == 0) {
    DAT_00faae04 = 0;
  }
  else {
    DAT_00faae04 = FUN_007701e0(local_68);
  }
  local_8 = 0;
  local_68 = FUN_00891268(0x2c);
  local_8 = 3;
  if (local_68 == 0) {
    DAT_00faae08 = 0;
  }
  else {
    DAT_00faae08 = FUN_007703f0(local_68);
  }
  local_8 = 0;
  local_68 = FUN_00891268(0x14);
  local_8 = 4;
  if (local_68 == 0) {
    DAT_00faae00 = 0;
  }
  else {
    DAT_00faae00 = FUN_00770da0(local_68);
  }
  local_8 = 0;
  local_68 = FUN_00891268(0x58);
  local_8 = 5;
  if (local_68 == 0) {
    DAT_00faae10 = 0;
  }
  else {
    DAT_00faae10 = FUN_005ca940(local_68);
  }
  local_8 = 0;
  *(undefined4 *)(DAT_00faadfc + 0x165b4) = DAT_00faae10;
  DAT_00faadfc[0x165b8] = 1;
  *(undefined4 *)(DAT_00faadfc + 0x165bc) = 5;
  local_24 = 0;
  _memset(local_64,0,0x40);
  local_20 = 0xe;
  local_1c = 4;
  local_18 = 1;
  _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a248);
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8 = 6;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8 = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,&local_68);
  _DAT_00faaf30 = *puVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

