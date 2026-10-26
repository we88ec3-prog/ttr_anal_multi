
void FUN_00472810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916400;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  piVar2 = _malloc(0xe8);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_00471830();
    *piVar2 = (int)FoxUI::FXUIComboBoxListContent::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  in_ECX[0x33] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(0,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0xe0);
  local_8 = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_0075da10();
    *piVar3 = (int)FoxUI::FXUIComboBoxListScrollBar::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x34] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(1,0x1c3,0,0,0x14,0);
  (**(code **)(*(int *)in_ECX[0x34] + 0xb4))(2);
  ExceptionList = local_10;
  return;
}

