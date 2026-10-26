
int * FUN_007798f0(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x114);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_007799a0(uVar1);
    *piVar2 = (int)FoxUI::FXUIBackground3Y::vftable;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x34))();
  FUN_00779620(in_ECX);
  (**(code **)(*piVar2 + 0x38))();
  ExceptionList = local_10;
  return piVar2;
}

