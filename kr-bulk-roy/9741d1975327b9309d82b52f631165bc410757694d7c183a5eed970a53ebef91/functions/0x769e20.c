
undefined4 * FUN_00769e20(void)

{
  uint uVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0xe0);
  local_8 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0075af30(uVar1);
    puVar2[0x33] = 0;
    puVar2[0x34] = 0;
    puVar2[0x35] = 0;
    *puVar2 = FoxUI::FXUIWindowClientBtnOkCancel::vftable;
    puVar2[0x36] = 0;
    puVar2[0x37] = 0;
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

