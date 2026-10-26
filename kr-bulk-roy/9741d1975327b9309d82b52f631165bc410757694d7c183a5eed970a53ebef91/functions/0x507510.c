
void FUN_00507510(void)

{
  wchar_t *_Src;
  uint in_ECX;
  int in_EDX;
  uint local_6c;
  int local_68;
  undefined1 local_64 [4];
  wchar_t local_60 [30];
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00917376;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  if ((DAT_00fe1b30 & 1) == 0) {
    DAT_00fe1b30 = DAT_00fe1b30 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0047faf0(local_14);
    _atexit((_func_4879 *)&LAB_00bceab0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_6c = in_ECX & 0xffff;
  FUN_00503cb0(&local_6c);
  if (local_68 == DAT_00fe1b38) {
    _Src = (wchar_t *)(&PTR_DAT_00d6a104)[in_ECX & 0xffff];
  }
  else {
    _Src = (wchar_t *)(local_68 + 0x10);
    if (7 < *(uint *)(local_68 + 0x24)) {
      _Src = *(wchar_t **)_Src;
    }
  }
  _wcscpy_s(local_60,0x1e,_Src);
  FUN_00507ba0(in_EDX + 8,local_64);
  if (local_24 != 0) {
    FUN_0089120c(local_24);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

