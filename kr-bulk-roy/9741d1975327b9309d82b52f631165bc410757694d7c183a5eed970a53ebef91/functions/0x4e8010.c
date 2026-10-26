
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004e8010(void)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0093b16f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fbad18 = CGuildMgr::vftable;
  DAT_00fc0bc4 = 0;
  DAT_00fc0bc8 = 0;
  _DAT_00fc0bcc = 0;
  DAT_00fc0bd4 = 0;
  DAT_00fc0bd8 = 0;
  DAT_00fc0bdc = 0;
  DAT_00fc0be0 = 0;
  _DAT_00fc0be4 = 0;
  DAT_00fc0be8 = 0;
  _DAT_00fc0bec = 0;
  DAT_00fc0bf0 = 0;
  _DAT_00fc0bf4 = 0;
  _DAT_00fc0bf8 = 0;
  DAT_00fc0bfc = 0;
  _DAT_00fc0c00 = 0;
  _DAT_00fc0c08 = 1;
  DAT_00fc0c20 = 7;
  _DAT_00fc0c1c = 0;
  DAT_00fc0c0c._0_2_ = 0;
  _DAT_00fc0c28 = 0;
  _DAT_00fc0c2c = 0;
  _DAT_00fc0c30 = 0;
  _DAT_00fc0c34 = 0;
  _DAT_00fc0c38 = 0;
  DAT_00fc0c3c = 0;
  DAT_00fc0c40 = 0;
  _DAT_00fc0c44 = 0;
  local_8 = 4;
  uStack_7 = 0;
  DAT_00fc0c4c = 0;
  _DAT_00fc0c5c = 0;
  DAT_00fc0c58 = FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fc0c58 = DAT_00fc0c58;
  *(int *)(DAT_00fc0c58 + 4) = DAT_00fc0c58;
  *(int *)(DAT_00fc0c58 + 8) = DAT_00fc0c58;
  *(undefined1 *)(DAT_00fc0c58 + 0x18) = 1;
  *(undefined1 *)(DAT_00fc0c58 + 0x19) = 1;
  _local_8 = CONCAT31(uStack_7,5);
  _DAT_00fc0c64 = 0;
  uVar1 = FUN_004e82e0();
  FUN_004ec030(uVar1);
  ExceptionList = local_10;
  return &DAT_00fbad18;
}

