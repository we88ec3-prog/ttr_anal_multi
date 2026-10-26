
void FUN_00645660(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  puStack_c = &LAB_0091a160;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00760b80(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  piVar2 = _malloc(0x194);
  local_8 = 0;
  piVar3 = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    FUN_00744320(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
    *piVar2 = (int)FoxUI::FXUIButtonResizeLT::vftable;
    piVar3 = piVar2;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3e] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(0,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 2;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeMT::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3f] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(1,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 4;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,5);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeRT::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x40] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(2,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 6;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,7);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeLM::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x41] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(3,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 8;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,9);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeRM::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x42] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(4,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 10;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xb);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeLB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x43] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(5,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 0xc;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeMB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x44] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(6,0x41c3,param_3,param_4,param_5,param_6);
  piVar3 = _malloc(0x194);
  local_8 = 0xe;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xf);
    *piVar3 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar3 + 0x2a);
    *(undefined1 *)(piVar3 + 0x29) = 1;
    *piVar3 = (int)FoxUI::FXUIButtonResizeRB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x45] = (int)piVar3;
  (**(code **)(*piVar3 + 0x38))(7,0x41c3,param_3,param_4,param_5,param_6);
  *(undefined1 *)(in_ECX[0x3e] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x3f] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x40] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x41] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x42] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x43] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x44] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x45] + 0xa4) = 0;
  (**(code **)(*in_ECX + 0x128))();
  ExceptionList = local_10;
  return;
}

