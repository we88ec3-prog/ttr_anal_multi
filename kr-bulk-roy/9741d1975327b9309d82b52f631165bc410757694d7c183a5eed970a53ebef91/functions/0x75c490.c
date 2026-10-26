
undefined4 * FUN_0075c490(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0xdc);
  local_8 = 0;
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0075d240(uVar1);
    *puVar2 = FoxUI::FXUIComboBoxList::vftable;
    puVar3 = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}

