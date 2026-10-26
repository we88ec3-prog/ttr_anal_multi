
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055b8a0(void)

{
  uint uVar1;
  undefined4 *puVar2;
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
  puStack_c = &LAB_00921ffa;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  _eh_vector_constructor_iterator_
            (&DAT_00fcde48,0x4c,0x104,(_func_void_void_ptr *)&LAB_0055bb30,FUN_0055b800);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  _DAT_00fd2b7c = 0xffffffff;
  _DAT_00fd2b80 = 0xffffffff;
  _DAT_00fd2b84 = 0xffffffff;
  _DAT_00fd2b88 = 0xffffffff;
  _DAT_00fd2b8c = 0xffffffff;
  _DAT_00fd2b90 = 0xffffffff;
  DAT_00fd2b78 = 0;
  _DAT_00fd2b94 = 1;
  local_24 = 0;
  local_20 = 0;
  _memset(local_64,0,0x40);
  local_1c = 7;
  local_18 = 1;
  _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a234);
  local_20 = 0xc;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 1;
    FUN_00734ef0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b7c = *puVar2;
  local_20 = 0xe;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 2;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b80 = *puVar2;
  local_20 = 0x10;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 3;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b84 = *puVar2;
  local_20 = 0x12;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 4;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b88 = *puVar2;
  local_20 = 0x14;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 5;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b8c = *puVar2;
  local_20 = 0x16;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_8._0_1_ = 6;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
    local_8._0_1_ = 0;
  }
  puVar2 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_68);
  _DAT_00fd2b90 = *puVar2;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

