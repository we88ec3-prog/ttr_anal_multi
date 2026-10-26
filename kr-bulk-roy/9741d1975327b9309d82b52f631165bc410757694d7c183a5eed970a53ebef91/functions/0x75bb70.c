
void FUN_0075bb70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  puStack_c = &LAB_0091cc60;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  piVar2 = _malloc(0xa8);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_00744320();
    *piVar2 = (int)FoxUI::FXUIPicture::vftable;
    *(undefined1 *)(piVar2 + 0x29) = 0;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  in_ECX[0x32] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(0,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x158);
  local_8 = 1;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00754880();
    *piVar3 = (int)FoxUI::FXUIStatic::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x33] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(1,0x41c3,param_3,param_4,param_5,param_6);
  ExceptionList = local_10;
  return;
}

