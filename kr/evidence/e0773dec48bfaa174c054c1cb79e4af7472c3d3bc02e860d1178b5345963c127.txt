
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006d0750(void)

{
  uint uVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009228e5;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  DAT_00fb8830 = 0;
  _eh_vector_constructor_iterator_
            (&DAT_00fb8834,0x280,3,(_func_void_void_ptr *)&LAB_006d08c0,
             (_func_void_void_ptr *)&LAB_006d08e0);
  _DAT_00fb902c = 0;
  _DAT_00fb9030 = 0;
  DAT_00fb9034 = 0;
  DAT_00fb903c = 0;
  _DAT_00fb9040 = 0;
  _DAT_00fb9044 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  FUN_006d08f0(uVar1);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8._0_1_ = 2;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_8._0_1_ = 1;
  }
  if (DAT_00fb91e9 == '\x02') {
    FUN_006d0d10();
  }
  FUN_006d1a70(2);
  _DAT_00fb8fb4 = 0;
  _DAT_00fb8fb8 = 0;
  _DAT_00fb8fbc = 0;
  _DAT_00fb8fc0 = 0;
  _DAT_00fb8fc4 = 0;
  _DAT_00fb8fc8 = 0;
  _DAT_00fb8fcc = 0;
  _DAT_00fb8fd0 = 0;
  _DAT_00fb8fd4 = 0;
  _DAT_00fb8fd8 = 0;
  _DAT_00fb8fdc = 0;
  _DAT_00fb8fe0 = 0;
  _DAT_00fb8fe4 = 0;
  _DAT_00fb8fe8 = 0;
  _DAT_00fb8fec = 0;
  _DAT_00fb8ff0 = 0;
  _DAT_00fb8ff4 = 0;
  _DAT_00fb8ff8 = 0;
  _DAT_00fb8ffc = 0;
  _DAT_00fb9000 = 0;
  _DAT_00fb9004 = 0;
  _DAT_00fb9008 = 0;
  _DAT_00fb900c = 0;
  _DAT_00fb9010 = 0;
  _DAT_00fb9014 = 0;
  _DAT_00fb9018 = 0;
  _DAT_00fb901c = 0;
  _DAT_00fb9020 = 0;
  _DAT_00fb9024 = 0;
  _DAT_00fb9028 = 0;
  *unaff_FS_OFFSET = local_10;
  return &DAT_00fb8830;
}

