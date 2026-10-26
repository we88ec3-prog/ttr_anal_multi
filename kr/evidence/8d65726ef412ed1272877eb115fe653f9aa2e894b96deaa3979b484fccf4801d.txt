
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0041f3e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b8fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7318 & 1) == 0) {
    DAT_00fb7318 = DAT_00fb7318 | 1;
    local_8 = 0;
    FUN_0075f1d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _DAT_00fb72fc = FoxUI::FXUIManagerCharSet::vftable;
    _DAT_00fb7310 = 0;
    _DAT_00fb7314 = 0;
    _atexit((_func_4879 *)&LAB_00bcd060);
  }
  ExceptionList = local_10;
  return &DAT_00fb72fc;
}

