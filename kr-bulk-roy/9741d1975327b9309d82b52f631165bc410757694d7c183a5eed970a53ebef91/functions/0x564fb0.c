
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00564fb0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093ac0e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_8 = 0;
    FUN_0055e680(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bcf2a0);
  }
  _DAT_00fe2758 = 1;
  _DAT_00fe275c = param_1;
  _DAT_00fe2760 = 0;
  _DAT_00fe2750 = 1;
  _DAT_00fe2754 = 0xff;
  ExceptionList = local_10;
  return;
}

