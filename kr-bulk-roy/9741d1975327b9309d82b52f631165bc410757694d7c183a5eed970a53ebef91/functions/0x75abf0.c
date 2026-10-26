
void FUN_0075abf0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int *in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009158b0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(*in_ECX + 0x180))(uVar1);
  uVar2 = FUN_008fed10();
  piVar3 = _malloc(0x194);
  local_8 = 0;
  piVar4 = (int *)0x0;
  if (piVar3 != (int *)0x0) {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    piVar4 = piVar3;
  }
  local_8 = 0xffffffff;
  in_ECX[0x40] = (int)piVar4;
  (**(code **)(*piVar4 + 0x38))(0,0x41c3,uVar2,0,param_5 - param_3,0x14);
  (**(code **)(*(int *)in_ECX[0x40] + 0xb4))(0xce);
  ExceptionList = local_10;
  return;
}

