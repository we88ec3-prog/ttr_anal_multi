
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0055e680(void)

{
  undefined4 uVar1;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944ebe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fe2748 = 0x400;
  _DAT_00fe274c = 0x300;
  _DAT_00fe2750 = 0;
  _DAT_00fe2754 = 0;
  _DAT_00fe2758 = 0;
  _DAT_00fe275c = 0;
  _DAT_00fe2760 = 0;
  if ((DAT_00fdf3d4 & 1) == 0) {
    DAT_00fdf3d4 = DAT_00fdf3d4 | 1;
    local_8 = 0;
    FUN_006f4380(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6d0);
  }
  local_8 = 0xffffffff;
  uVar1 = FUN_0055e850(local_14,&DAT_00fdf3c8);
  uVar1 = FUN_0055e930(uVar1);
  FUN_0055e9d0(uVar1);
  ExceptionList = local_10;
  return &DAT_00fe2744;
}

