
undefined4 * FUN_0068afa0(void)

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
  puVar2 = _malloc(0xec);
  local_8 = 0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0076be30(uVar1);
    *puVar2 = FUI::CBuffListBox::vftable;
    puVar2[0x37] = 0;
    puVar2[0x38] = 0;
    puVar2[0x39] = 0;
    puVar2[0x3a] = 0xffffffff;
    ExceptionList = local_10;
    return puVar2;
  }
  ExceptionList = local_10;
  return (undefined4 *)0x0;
}

