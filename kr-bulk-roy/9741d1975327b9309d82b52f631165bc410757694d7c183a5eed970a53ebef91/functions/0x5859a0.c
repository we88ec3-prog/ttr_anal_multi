
int * FUN_005859a0(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0xf4);
  local_8 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_007564e0(uVar2);
    piVar3[0x3b] = 0;
    *(undefined1 *)(piVar3 + 0x3c) = 0;
    *piVar3 = (int)FUI::CMsgBoxWait::vftable;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00406fe0();
  piVar3[0x3b] = *(int *)(in_ECX + 0xec);
  pcVar1 = *(code **)(*piVar3 + 0x34);
  *(undefined1 *)(piVar3 + 0x3c) = *(undefined1 *)(in_ECX + 0xf0);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar3;
}

