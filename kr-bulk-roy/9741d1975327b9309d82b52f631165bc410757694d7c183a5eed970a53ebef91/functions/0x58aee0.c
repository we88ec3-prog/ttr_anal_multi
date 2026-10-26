
void FUN_0058aee0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f8ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (undefined4 *)FUN_00891268(0x20,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    local_14[4] = param_1;
    local_14[6] = param_2;
    local_14[1] = 0xffffffff;
    local_14[2] = 0xffffffff;
    local_14[3] = 0;
    *local_14 = FoxUI::FXUIEventBI1::vftable;
    local_14[7] = param_3;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  FUN_00804260(&local_14);
  ExceptionList = local_10;
  return;
}

