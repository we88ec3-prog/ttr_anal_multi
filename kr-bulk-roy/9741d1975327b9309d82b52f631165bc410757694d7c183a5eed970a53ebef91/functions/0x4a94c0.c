
void FUN_004a94c0(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092771c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 != 0) {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 0;
      FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    DAT_00fb8830 = DAT_00fb8830 & 0xfffffffd;
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 1;
    FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  DAT_00fb8830 = DAT_00fb8830 | 2;
  ExceptionList = local_10;
  return;
}

