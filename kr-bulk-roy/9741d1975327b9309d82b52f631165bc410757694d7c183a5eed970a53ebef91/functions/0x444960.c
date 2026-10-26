
undefined4 * FUN_00444960(void)

{
  uint uVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009258be;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  *unaff_FS_OFFSET = local_10;
  return &DAT_00fb8830;
}

