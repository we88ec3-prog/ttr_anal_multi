
undefined4 * FUN_005ddcb0(void)

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
  puVar2 = _malloc(0x2d8);
  local_8 = 0;
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_005dccd0(uVar1);
    *puVar2 = FUI::CItemSlotInven::vftable;
    puVar3 = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}

