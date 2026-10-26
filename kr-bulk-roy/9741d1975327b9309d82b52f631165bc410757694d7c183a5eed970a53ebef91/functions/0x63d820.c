
int * FUN_0063d820(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a910;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar2 = _malloc(0x248);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_00754880(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar2 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(piVar2 + 0x57);
    *(undefined1 *)(piVar2 + 0x56) = 1;
    *piVar2 = (int)FUI::CMSGBlackItem::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar3 + 0x30))();
  FUN_00405370();
  *(undefined1 *)(piVar3 + 0x56) = *(undefined1 *)(in_ECX + 0x158);
  FUN_00405420(in_ECX + 0x15c);
  (**(code **)(*piVar3 + 0x34))();
  ExceptionList = local_10;
  return piVar3;
}

