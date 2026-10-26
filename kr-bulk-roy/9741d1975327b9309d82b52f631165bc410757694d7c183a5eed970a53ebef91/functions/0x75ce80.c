
void FUN_0075ce80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919048;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  piVar2 = _malloc(0xdc);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0075d240();
    *piVar2 = (int)FoxUI::FXUIComboBoxList::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x93] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))
            (0,0x40c3,0,in_ECX[5] - in_ECX[3],in_ECX[4] - in_ECX[2],(in_ECX[5] - in_ECX[3]) * 6);
  if ((char)in_ECX[0x92] == '\0') {
    uVar3 = 0x137;
  }
  else {
    uVar3 = 0x134;
  }
  (**(code **)(*(int *)in_ECX[0x93] + 0xb4))(uVar3);
  ExceptionList = local_10;
  return;
}

