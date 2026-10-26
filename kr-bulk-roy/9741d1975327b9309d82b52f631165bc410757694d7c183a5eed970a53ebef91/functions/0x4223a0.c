
undefined4 * FUN_004223a0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0xf0);
  local_8 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_007564e0(uVar1);
    *puVar2 = FoxUI::FXUIWindowSimple::vftable;
    puVar2[0x3b] = 0;
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

