
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005646e0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ac3e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((_DAT_00fe38cc & 1) == 0) {
    _DAT_00fe38cc = _DAT_00fe38cc | 1;
    _DAT_00fe36e4 = 0x400;
    _DAT_00fe36e8 = 0x300;
    _DAT_00fe36ec = 0;
    _atexit((_func_4879 *)&DAT_00bcf2d0);
  }
  FUN_0055ecc0(uVar1);
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_8 = 0;
    FUN_0055e680();
    _atexit((_func_4879 *)&DAT_00bcf2a0);
    local_8 = 0xffffffff;
  }
  FUN_0055e7f0();
  ExceptionList = local_10;
  return 0;
}

