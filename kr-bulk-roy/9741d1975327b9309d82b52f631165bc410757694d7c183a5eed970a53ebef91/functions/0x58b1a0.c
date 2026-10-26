
void FUN_0058b1a0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091694c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = 0;
  if ((DAT_00faafd4 & 1) == 0) {
    DAT_00faafd4 = DAT_00faafd4 | 1;
    local_8 = 0;
    FUN_0044dfb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bccd10);
  }
  local_8 = 0xffffffff;
  FUN_0082ef00(&param_1);
  if (local_14 != DAT_00faafe0) {
    uVar1 = *(undefined4 *)(local_14 + 0x10);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  local_14 = param_2;
  local_18 = uVar1;
  FUN_007b6e80(&local_18);
  ExceptionList = local_10;
  return;
}

