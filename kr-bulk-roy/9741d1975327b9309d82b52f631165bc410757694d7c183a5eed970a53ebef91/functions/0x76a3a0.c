
int * FUN_0076a3a0(void)

{
  uint uVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0xe0);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0075af30(uVar1);
    piVar2[0x33] = 0;
    piVar2[0x34] = 0;
    piVar2[0x35] = 0;
    *piVar2 = (int)FoxUI::FXUIWindowClientBtnYesNo::vftable;
    piVar2[0x36] = 0;
    piVar2[0x37] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_0076a4a0();
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

