
int * FUN_005d9690(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092b538;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x2a8);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_005d6dd0(uVar1);
    *piVar2 = (int)FUI::CItemSlotShopStoneMerge::vftable;
    piVar2[0xa6] = -1;
    piVar2[0xa7] = 0;
    piVar2[0xa8] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_00408e60(piVar2);
  piVar2[0xa6] = *(int *)(in_ECX + 0x298);
  piVar2[0xa7] = *(int *)(in_ECX + 0x29c);
  piVar2[0xa8] = *(int *)(in_ECX + 0x2a0);
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

