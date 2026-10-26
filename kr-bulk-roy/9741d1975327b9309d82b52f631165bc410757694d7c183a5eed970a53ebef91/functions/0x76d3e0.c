
int * FUN_0076d3e0(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x110);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0075b310(uVar1);
    piVar2[0x40] = 0;
    *piVar2 = (int)FoxUI::FXUIWindowFrameMS::vftable;
    piVar2[0x41] = 0;
    piVar2[0x42] = 0;
    piVar2[0x43] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_0075a980();
  piVar2[0x40] = *(int *)(in_ECX + 0x100);
  piVar2[0x41] = *(int *)(in_ECX + 0x104);
  piVar2[0x42] = *(int *)(in_ECX + 0x108);
  piVar2[0x43] = *(int *)(in_ECX + 0x10c);
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

