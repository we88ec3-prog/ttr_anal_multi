
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006f4380(void)

{
  DAT_00fdf3c8 = FUN_006f74b0();
  if (DAT_00fdf3c8 != 0) {
    *(code **)(*(int *)(DAT_00fdf3c8 + 0x10) + 0x58) = FUN_006f71a0;
  }
  _DAT_00fdf3cc = 0;
  DAT_00fdf3d0 = 1;
  FUN_006f7660();
  FUN_006f55b0(FUN_006f4420,0);
  FUN_006f5790();
  FUN_006f55b0(FUN_006f48a0,0);
  FUN_006f5790();
  return &DAT_00fdf3c8;
}

