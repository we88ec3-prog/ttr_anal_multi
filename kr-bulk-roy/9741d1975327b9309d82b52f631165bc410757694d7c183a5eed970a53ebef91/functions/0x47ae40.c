
undefined4 * FUN_0047ae40(void)

{
  uint uVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b70e;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  if ((DAT_00fc0e40 & 1) == 0) {
    DAT_00fc0e40 = DAT_00fc0e40 | 1;
    local_8 = 0;
    FUN_00540770(uVar1);
    _atexit((_func_4879 *)&LAB_00bcdb60);
  }
  *unaff_FS_OFFSET = local_10;
  return &DAT_00fc0e48;
}

