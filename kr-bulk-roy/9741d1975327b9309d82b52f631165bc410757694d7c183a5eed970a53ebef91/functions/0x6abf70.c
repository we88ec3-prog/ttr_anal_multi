
int * FUN_006abf70(void)

{
  uint uVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a910;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x254);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00754880(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar2 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(piVar2 + 0x57);
    *(undefined1 *)(piVar2 + 0x56) = 1;
    *piVar2 = (int)FUI::CGuildRankingListItem::vftable;
    piVar2[0x92] = 0;
    piVar2[0x93] = 0;
    piVar2[0x94] = 0;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar2 + 0x30))();
  FUN_006ac080(piVar2);
  (**(code **)(*piVar2 + 0x34))();
  ExceptionList = local_10;
  return piVar2;
}

