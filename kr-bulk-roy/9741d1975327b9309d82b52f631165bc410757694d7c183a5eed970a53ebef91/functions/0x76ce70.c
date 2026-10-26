
void FUN_0076ce70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
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
  piVar2 = _malloc(0xbc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    *piVar2 = (int)FoxUI::FXUIWindowClientCanvas::vftable;
    piVar2[0x2e] = 0;
    piVar2[0x2d] = 0;
    piVar2[0x2c] = 0;
    piVar2[0x2b] = 0;
    piVar2[0x29] = 0;
    piVar2[0x2a] = 0;
  }
  local_8 = 0xffffffff;
  in_ECX[0x35] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(0,0x1c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0xe0);
  local_8 = 1;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0075da10();
    *piVar2 = (int)FoxUI::FXUIWindowClientScrollBar::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x34] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(1,0x1c3,0,0,0x14,0);
  (**(code **)(*(int *)in_ECX[0x34] + 0xb4))(2);
  ExceptionList = local_10;
  return;
}

