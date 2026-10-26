
undefined4 * FUN_00779890(void)

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
  puVar2 = _malloc(0x114);
  local_8 = 0;
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_007799a0(uVar1);
    *puVar2 = FoxUI::FXUIBackground3Y::vftable;
    puVar3 = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}

