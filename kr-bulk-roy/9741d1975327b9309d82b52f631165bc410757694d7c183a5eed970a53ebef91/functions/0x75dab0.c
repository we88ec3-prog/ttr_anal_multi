
void FUN_0075dab0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009191f0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  piVar2 = _malloc(0x194);
  local_8 = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xa4) = piVar2;
  (**(code **)(*piVar2 + 0x38))(0,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 2;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xa8) = piVar2;
  (**(code **)(*piVar2 + 0x38))(1,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 4;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,5);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xac) = piVar2;
  (**(code **)(*piVar2 + 0x38))(2,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 6;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,7);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xb0) = piVar2;
  (**(code **)(*piVar2 + 0x38))(3,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 8;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,9);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
  }
  local_8 = 0xffffffff;
  *(int **)(in_ECX + 0xb4) = piVar2;
  (**(code **)(*piVar2 + 0x38))(4,0x41c3,param_3,param_4,param_5,param_6);
  *(undefined1 *)(*(int *)(in_ECX + 0xa4) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xa8) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xac) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xb0) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xb4) + 0xa4) = 0;
  ExceptionList = local_10;
  return;
}

