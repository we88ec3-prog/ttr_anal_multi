
undefined4 * FUN_0075f4f0(void)

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
  puVar1 = _malloc(0xd8);
  local_8 = 0;
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0075fed0(puVar1);
    *puVar1 = FoxUI::FXUITabBoxNavigator::vftable;
    puVar2 = puVar1;
  }
  ExceptionList = local_10;
  return puVar2;
}

