
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00783c70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907b6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe31e8 & 1) == 0) {
    DAT_00fe31e8 = DAT_00fe31e8 | 1;
    local_8 = 0;
    FUN_00783de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _DAT_00fe31fc = 0;
    _atexit(FUN_00bd08a0);
  }
  DAT_00fe3200 = &DAT_00fe31ec;
  ExceptionList = local_10;
  return;
}

