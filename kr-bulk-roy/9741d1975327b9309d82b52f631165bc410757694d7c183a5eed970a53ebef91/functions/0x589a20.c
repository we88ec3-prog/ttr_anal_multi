
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00589a20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00916a3a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = FUN_0048a010(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  FUN_0041d9b0(*(undefined4 *)(iVar1 + 0xc),param_2);
  if ((_DAT_00fd8f0c & 1) == 0) {
    _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
    FUN_00559120();
    _atexit((_func_4879 *)&DAT_00bcdf60);
  }
  FUN_005591d0(DAT_00fd8f1c,param_1,param_2);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  FUN_00752e10(param_1,param_2);
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  FUN_00753780();
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 2;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (DAT_00f95bd4 != (int *)0x0) {
    (**(code **)(*DAT_00f95bd4 + 200))();
  }
  ExceptionList = local_14;
  return;
}

