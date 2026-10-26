
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c4d30(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094232e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  uVar1 = FUN_004f6a30(*(undefined4 *)(param_1 + 0xb4));
  FUN_004f2db0(uVar1);
  ExceptionList = local_10;
  return;
}

