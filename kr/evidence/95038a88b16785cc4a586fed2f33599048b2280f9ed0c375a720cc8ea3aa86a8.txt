
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e34b0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d72e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_8 = 0xffffffff;
  FUN_004dd220(param_1);
  ExceptionList = local_10;
  return;
}

