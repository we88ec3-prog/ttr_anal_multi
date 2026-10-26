
int * FUN_005dc0f0(void)

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
  piVar3 = _malloc(0x2a0);
  local_8 = 0;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_005d6dd0(uVar2);
    *piVar3 = (int)FUI::CItemSlotCashShopContract::vftable;
    *(undefined2 *)(piVar3 + 0xa6) = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00408e60(piVar3);
  pcVar1 = *(code **)(*piVar3 + 0x34);
  *(undefined2 *)(piVar3 + 0xa6) = *(undefined2 *)(in_ECX + 0x298);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar3;
}

