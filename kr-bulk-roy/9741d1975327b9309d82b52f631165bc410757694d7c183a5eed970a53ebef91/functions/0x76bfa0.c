
void FUN_0076bfa0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009133bc;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::
            FXUIListContainerContent<FoxUI::FXUIListContainer<FoxUI::FXUIListBoxContent,FoxUI::FXUIScrollbar,FoxUI::FXUIContentButton>,FoxUI::FXUIContentButton>
            ::vftable;
  piVar1 = in_ECX + 0x2a;
  local_8 = 2;
  FUN_0076c3b0(piVar1,uVar3);
  piVar2 = in_ECX + 0x2e;
  FUN_0076c3b0(piVar2);
  if (*piVar2 != 0) {
    FUN_0089120c(*piVar2);
  }
  *piVar2 = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 3;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

