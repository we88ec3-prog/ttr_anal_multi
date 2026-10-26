
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056b690(void)

{
  undefined4 *puVar1;
  undefined **local_78 [3];
  undefined1 local_6c [4];
  char *local_68;
  wchar_t local_64 [32];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921f69;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _DAT_00fc1c84 = 0xffffffff;
  DAT_00fc1c88 = (undefined4 *)0x0;
  puVar1 = (undefined4 *)FUN_00891268(8,local_14);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_00fc1c88 = puVar1;
    puVar1[1] = 0;
    *puVar1 = 0;
    *DAT_00fc1c88 = &DAT_00fc1c88;
    _DAT_00fc1c8c = 0;
    _DAT_00fc1c90 = 0;
    _DAT_00fc1c94 = 0;
    _DAT_00fc1c98 = 0;
    local_8 = 0;
    _DAT_00fc1ca0 = 0x11c;
    local_24 = 0;
    _memset(local_64,0,0x40);
    local_20 = 0x14;
    local_1c = 7;
    local_18 = 1;
    _wcscpy_s(local_64,0x20,(wchar_t *)PTR_DAT_00d6a234);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_8._0_1_ = 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    puVar1 = (undefined4 *)FUN_00735850(&DAT_00fb7b70,local_6c);
    _DAT_00fc1c84 = *puVar1;
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_68 = (char *)0x0;
  std::exception::exception((exception *)local_78,&local_68);
  local_78[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_78,&DAT_00c857a8);
}

