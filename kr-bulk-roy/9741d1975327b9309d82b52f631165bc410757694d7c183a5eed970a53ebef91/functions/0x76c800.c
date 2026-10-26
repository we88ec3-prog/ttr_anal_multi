
int * FUN_0076c800(void)

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
  piVar2 = _malloc(0xbc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320(uVar1);
    *piVar2 = (int)FoxUI::FXUIWindowClientCanvas::vftable;
    piVar2[0x2e] = 0;
    piVar2[0x2d] = 0;
    piVar2[0x2c] = 0;
    piVar2[0x2b] = 0;
    piVar2[0x29] = 0;
    piVar2[0x2a] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_0076c930();
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

