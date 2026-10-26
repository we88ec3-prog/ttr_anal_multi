
undefined4 * FUN_00468180(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911d18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = _malloc(0x25c);
  local_8 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004685c0(puVar1);
    *puVar1 = FUI::CCncServerListItem::vftable;
    puVar2 = puVar1;
  }
  ExceptionList = local_10;
  return puVar2;
}

