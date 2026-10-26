
int * FUN_00769890(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0xd8);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_0075af30(uVar1);
    piVar2[0x33] = 0;
    piVar2[0x34] = 0;
    piVar2[0x35] = 0;
    *piVar2 = (int)FoxUI::FXUIWindowClientBtnWait::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00404f50();
  *(undefined1 *)(piVar3 + 0x32) = *(undefined1 *)(in_ECX + 200);
  piVar3[0x33] = *(int *)(in_ECX + 0xcc);
  piVar3[0x34] = *(int *)(in_ECX + 0xd0);
  piVar3[0x35] = *(int *)(in_ECX + 0xd4);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

