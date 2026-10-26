
undefined * FUN_004a0950(void)

{
  undefined4 uVar1;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944ebe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8 = 0;
    FUN_006f4380(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  local_8 = 0xffffffff;
  uVar1 = FUN_004a14d0(local_14,&DAT_00fdf3c8);
  uVar1 = FUN_004a15b0(uVar1);
  uVar1 = FUN_004a1650(uVar1);
  uVar1 = FUN_004a16f0(uVar1);
  uVar1 = FUN_004a1790(uVar1);
  uVar1 = FUN_004a1830(uVar1);
  uVar1 = FUN_004a18d0(uVar1);
  uVar1 = FUN_004a1970(uVar1);
  uVar1 = FUN_004a1a10(uVar1);
  uVar1 = FUN_004a1ab0(uVar1);
  uVar1 = FUN_004a1b50(uVar1);
  uVar1 = FUN_004a1bf0(uVar1);
  uVar1 = FUN_004a1c90(uVar1);
  uVar1 = FUN_004a1d30(uVar1);
  FUN_004a1dd0(uVar1);
  ExceptionList = local_10;
  return &DAT_00fe7224;
}

