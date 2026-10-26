
int * FUN_0076a040(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0xdc);
  local_8 = 0;
  piVar4 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    FUN_0075af30(uVar2);
    piVar3[0x33] = 0;
    piVar3[0x34] = 0;
    piVar3[0x35] = 0;
    piVar3[0x36] = 0;
    *piVar3 = (int)FoxUI::FXUIWindowClientBtnYes::vftable;
    piVar4 = piVar3;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar4 + 0x30))();
  FUN_00404f50();
  *(undefined1 *)(piVar4 + 0x32) = *(undefined1 *)(in_ECX + 200);
  piVar4[0x33] = *(int *)(in_ECX + 0xcc);
  piVar4[0x34] = *(int *)(in_ECX + 0xd0);
  piVar4[0x35] = *(int *)(in_ECX + 0xd4);
  pcVar1 = *(code **)(*piVar4 + 0x34);
  piVar4[0x36] = *(int *)(in_ECX + 0xd8);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar4;
}

