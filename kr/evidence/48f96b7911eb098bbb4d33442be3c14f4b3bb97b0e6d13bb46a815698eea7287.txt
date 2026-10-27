
uint FUN_004a7810(undefined4 *param_1)

{
  uint uVar1;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092777e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_8 = 0;
    FUN_0050caf0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  param_1 = (undefined4 *)*param_1;
  FUN_0050db00(&param_1);
  uVar1 = in_ECX;
  if ((in_ECX != DAT_00fe17c4) && (uVar1 = 0, in_ECX + 0x10 != 0)) {
    ExceptionList = local_10;
    return CONCAT31((int3)(in_ECX + 0x10 >> 8),*(undefined1 *)(in_ECX + 0x2c));
  }
  ExceptionList = local_10;
  return uVar1 & 0xffffff00;
}

