
undefined4 FUN_004b2570(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b27c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00fba7a4 + 4) = 1;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  if (DAT_00fb73e8 == 0) {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 1;
      FUN_006d0750();
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    DAT_00fb8830 = DAT_00fb8830 & 0xfffffffe;
  }
  ExceptionList = local_10;
  return 0;
}

