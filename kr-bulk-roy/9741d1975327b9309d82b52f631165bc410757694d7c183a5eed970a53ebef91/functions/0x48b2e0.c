
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0048b2e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009223cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00fe37a0 = MD5ChecksumProvider::vftable;
  DAT_00fe37a4 = 0;
  _DAT_00fe37b0 = 0;
  DAT_00fe37ac = FUN_007b2620(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00fe37ac = DAT_00fe37ac;
  *(int *)(DAT_00fe37ac + 4) = DAT_00fe37ac;
  *(int *)(DAT_00fe37ac + 8) = DAT_00fe37ac;
  *(undefined1 *)(DAT_00fe37ac + 0x38) = 1;
  *(undefined1 *)(DAT_00fe37ac + 0x39) = 1;
  local_8 = 0;
  FUN_0048b730();
  ExceptionList = local_10;
  return &DAT_00fe37a0;
}

