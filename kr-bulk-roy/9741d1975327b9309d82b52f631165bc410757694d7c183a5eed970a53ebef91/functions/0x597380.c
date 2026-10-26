
undefined4 FUN_00597380(int param_1)

{
  uint uVar1;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093f94a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_1 == 0x290d) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 1;
      FUN_00560170(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb73e8 == 0) {
      FUN_005974d0(in_ECX,0x290d);
    }
    else {
      if ((DAT_00fb73b8 & 1) == 0) {
        DAT_00fb73b8 = DAT_00fb73b8 | 1;
        local_8 = 2;
        FUN_00560170(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd110);
      }
      local_8 = 0xffffffff;
      FUN_00562320();
    }
    ExceptionList = local_10;
    return 1;
  }
  if (param_1 == 0x2af9) {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 0;
      FUN_00560170(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb73e8 != 0) {
      FUN_00422f40();
      FUN_00562320();
      ExceptionList = local_10;
      return 0;
    }
    FUN_005974d0(in_ECX,0x2af9);
  }
  ExceptionList = local_10;
  return 0;
}

