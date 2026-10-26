
void FUN_0058adb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint in_stack_00000020;
  undefined4 *local_50;
  undefined1 local_4c [56];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092ad20;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = uVar1;
  FUN_00757200(local_4c);
  local_8._0_1_ = 1;
  FUN_00757f20(uVar1);
  puVar2 = (undefined4 *)FUN_00891268(0x54);
  local_50 = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4251;
    puVar2[5] = param_1;
    puVar2[6] = param_2;
    local_8._0_1_ = 3;
    *puVar2 = FoxUI::FXUIEventI2S1::vftable;
    FUN_00757200(puVar2 + 7);
    local_8._0_1_ = 4;
    FUN_00405300(puVar2 + 7);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8._0_1_ = 5;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8._0_1_ = 1;
  local_50 = puVar2;
  FUN_00804260(&local_50);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00757640(local_4c);
  if (7 < in_stack_00000020) {
    FUN_0089120c(param_3);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

