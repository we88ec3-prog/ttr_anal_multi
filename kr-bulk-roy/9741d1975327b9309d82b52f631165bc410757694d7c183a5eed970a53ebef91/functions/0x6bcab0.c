
undefined4 FUN_006bcab0(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 == 0x2afa) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43e5;
      FUN_004072a0();
      ExceptionList = local_14;
      return 1;
    }
    FUN_004072a0();
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f9392c != 1) {
      if (param_1 == 0x2af9) {
        (**(code **)(*in_ECX + 0xd4))();
        ExceptionList = local_14;
        return 1;
      }
      ExceptionList = local_14;
      return 0;
    }
  }
  ExceptionList = local_14;
  return 1;
}

