
void FUN_0064efa0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091632c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CMiniMapChartPanelRTT::vftable;
  local_8 = 4;
  _eh_vector_destructor_iterator_(in_ECX + 0x44,0x10,0x23,FUN_005f5d10);
  local_8._0_1_ = 3;
  in_ECX[0x3e] = FoxUI::FXUIImageSetItemRef::vftable;
  if (in_ECX[0x3f] != 0) {
    piVar2 = *(int **)(in_ECX[0x3f] + 8);
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))(uVar3);
      }
    }
    in_ECX[0x3f] = 0;
  }
  local_8._0_1_ = 2;
  _eh_vector_destructor_iterator_(in_ECX + 0x36,8,4,FUN_00776620);
  local_8._0_1_ = 1;
  _eh_vector_destructor_iterator_(in_ECX + 0x2e,8,4,FUN_00776620);
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x2c] = FoxUI::FXUIImageSetItemRef::vftable;
  if (in_ECX[0x2d] != 0) {
    piVar2 = *(int **)(in_ECX[0x2d] + 8);
    if (piVar2 != (int *)0x0) {
      piVar1 = piVar2 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar2 + 0x28))();
      }
    }
    in_ECX[0x2d] = 0;
  }
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 5;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

