
void FUN_00628f40(void)

{
  undefined4 uVar1;
  undefined4 in_ECX;
  int unaff_EDI;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092d36e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_EDI + 0x250) = in_ECX;
  *(undefined4 *)(unaff_EDI + 0x254) = in_ECX;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8._1_3_ = 0;
  if ((DAT_00fe657c & 1) == 0) {
    DAT_00fe657c = DAT_00fe657c | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00590370(local_14);
    _atexit((_func_4879 *)&LAB_00bcfb30);
  }
  local_8._0_1_ = 0;
  uVar1 = FUN_00590720(&DAT_00fe4ca0,in_ECX);
  local_8._0_1_ = 2;
  FUN_00402800(uVar1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  FUN_00757800(local_30);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

