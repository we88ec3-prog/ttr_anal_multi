
void FUN_004d47f0(undefined4 param_1,undefined4 param_2)

{
  undefined3 uVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *unaff_ESI;
  undefined1 local_68 [4];
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930541;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_00553e90(unaff_ESI,100,0x19,1);
  *unaff_ESI = CNoticeFadeObject::vftable;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x1c] = 0;
  local_8._1_3_ = 0;
  uVar1 = local_8._1_3_;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  unaff_ESI[0x1e] = param_2;
  unaff_ESI[0xf] = 0;
  if (DAT_00e1951c == -1) {
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0x16;
    local_1c = 7;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a244);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8._0_1_ = 2;
      FUN_00734ef0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8._0_1_ = 1;
    }
    piVar3 = (int *)FUN_00735850(&DAT_00fb7b70,local_68);
    DAT_00e1951c = *piVar3;
    uVar1 = local_8._1_3_;
  }
  local_8._1_3_ = uVar1;
  FUN_004d4620(DAT_00e1951c,param_1,0x280,unaff_ESI + 0x1a);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

