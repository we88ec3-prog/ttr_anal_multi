
int * FUN_005e04c0(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a6e8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0x2b0);
  local_8 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_005d6dd0(uVar2);
    piVar3[0xa7] = -1;
    *piVar3 = (int)FUI::CItemSlotMyInfo::vftable;
    piVar3[0xa8] = 0;
    piVar3[0xa9] = 0;
    *(undefined1 *)(piVar3 + 0xaa) = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00408e60(piVar3);
  piVar3[0xa6] = *(int *)(in_ECX + 0x298);
  piVar3[0xa7] = *(int *)(in_ECX + 0x29c);
  piVar3[0xa8] = *(int *)(in_ECX + 0x2a0);
  piVar3[0xa9] = *(int *)(in_ECX + 0x2a4);
  pcVar1 = *(code **)(*piVar3 + 0x34);
  *(undefined1 *)(piVar3 + 0xaa) = *(undefined1 *)(in_ECX + 0x2a8);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar3;
}

