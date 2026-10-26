
int * FUN_0076b980(void)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0xe8);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_0076bf20(uVar1);
    *piVar2 = (int)FoxUI::FXUIListBoxContent::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_0076ba60();
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

