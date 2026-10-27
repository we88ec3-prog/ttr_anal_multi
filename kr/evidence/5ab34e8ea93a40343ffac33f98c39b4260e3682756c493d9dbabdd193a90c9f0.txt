
undefined4 * FUN_0040f060(void)

{
  uint uVar1;
  int *unaff_FS_OFFSET;
  undefined1 auStack_18 [4];
  int local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009461ee;
  local_14 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)auStack_18;
  *unaff_FS_OFFSET = (int)&local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar1);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  *unaff_FS_OFFSET = local_14;
  return &DAT_00fab130;
}

