
void FUN_00760770(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919180;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  piVar2 = _malloc(0xd8);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0075fed0(piVar2);
    *piVar2 = (int)FoxUI::FXUITabBoxNavigator::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x36] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(1,0x41c3,0,0,param_5 - param_3,0x14);
  piVar2 = _malloc(0xa4);
  local_8 = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    *piVar2 = (int)FoxUI::FXUITabBoxContent::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x37] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(0,0x41c3,0,0x14,param_5 - param_3,param_6 - param_4);
  ExceptionList = local_10;
  return;
}

