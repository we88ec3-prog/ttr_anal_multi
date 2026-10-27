
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d1a70(int param_1)

{
  uint uVar1;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab2e;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  if (param_1 < 3) {
    _DAT_00fb902c = &DAT_00fb8834 + param_1 * 0x280;
    _DAT_00fb9030 = param_1;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    DAT_00fb91e9 = (byte)param_1;
    if (DAT_00fb91eb < (byte)param_1) {
      DAT_00fb91e9 = DAT_00fb91eb;
    }
    if (DAT_00fb91e9 < DAT_00fb91ea) {
      DAT_00fb91e9 = DAT_00fb91ea;
    }
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
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

