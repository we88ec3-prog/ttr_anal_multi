
int * FUN_00419e90(void)

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
  puStack_c = &LAB_0092a910;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar3 = _malloc(0x250);
  local_8 = 0;
  piVar4 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    FUN_00754880(uVar2);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar3 = (int)FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(piVar3 + 0x57);
    *(undefined1 *)(piVar3 + 0x56) = 1;
    *piVar3 = (int)FUI::CPartyMatchingLocaleComboBoxItem::vftable;
    piVar4 = piVar3;
  }
  local_8 = 0xffffffff;
  (**(code **)(*piVar4 + 0x30))();
  FUN_00405370();
  *(undefined1 *)(piVar4 + 0x56) = *(undefined1 *)(in_ECX + 0x158);
  FUN_00405420(in_ECX + 0x15c);
  piVar4[0x92] = *(int *)(in_ECX + 0x248);
  pcVar1 = *(code **)(*piVar4 + 0x34);
  piVar4[0x93] = *(int *)(in_ECX + 0x24c);
  (*pcVar1)();
  ExceptionList = local_10;
  return piVar4;
}

