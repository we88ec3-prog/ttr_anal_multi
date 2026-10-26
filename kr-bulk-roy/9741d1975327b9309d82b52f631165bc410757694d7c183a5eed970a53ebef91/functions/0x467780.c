
int * FUN_00467780(void)

{
  uint uVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x25c);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_004685c0(piVar2);
    *piVar2 = (int)FUI::CNewServerListItem::vftable;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))(uVar1);
  FUN_00467440(piVar2);
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

