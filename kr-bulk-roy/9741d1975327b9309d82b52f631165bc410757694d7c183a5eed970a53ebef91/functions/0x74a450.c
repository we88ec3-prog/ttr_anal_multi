
void FUN_0074a450(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  uint uVar1;
  int *piVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009193d0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  in_ECX[0x36] = param_5 - param_3;
  in_ECX[0x38] = param_5 - param_3;
  in_ECX[0x37] = param_6 - param_4;
  in_ECX[0x39] = param_6 - param_4;
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
    *piVar2 = (int)FoxUI::FXUIButtonResizeLT::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3c] = (int)piVar2;
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
    *piVar2 = (int)FoxUI::FXUIButtonResizeMT::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3d] = (int)piVar2;
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
    *piVar2 = (int)FoxUI::FXUIButtonResizeRT::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3e] = (int)piVar2;
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
    *piVar2 = (int)FoxUI::FXUIButtonResizeLM::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x3f] = (int)piVar2;
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
    *piVar2 = (int)FoxUI::FXUIButtonResizeRM::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x40] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(4,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 10;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xb);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
    *piVar2 = (int)FoxUI::FXUIButtonResizeLB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x41] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(5,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 0xc;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xd);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
    *piVar2 = (int)FoxUI::FXUIButtonResizeMB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x42] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(6,0x41c3,param_3,param_4,param_5,param_6);
  piVar2 = _malloc(0x194);
  local_8 = 0xe;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00744320();
    local_8 = CONCAT31(local_8._1_3_,0xf);
    *piVar2 = (int)FoxUI::FXUIButton::vftable;
    FUN_0077b520(piVar2 + 0x2a);
    *(undefined1 *)(piVar2 + 0x29) = 1;
    *piVar2 = (int)FoxUI::FXUIButtonResizeRB::vftable;
  }
  local_8 = 0xffffffff;
  in_ECX[0x43] = (int)piVar2;
  (**(code **)(*piVar2 + 0x38))(7,0x41c3,param_3,param_4,param_5,param_6);
  *(undefined1 *)(in_ECX[0x3c] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x3d] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x3e] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x3f] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x40] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x41] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x42] + 0xa4) = 0;
  *(undefined1 *)(in_ECX[0x43] + 0xa4) = 0;
  (**(code **)(*in_ECX + 0x128))();
  ExceptionList = local_10;
  return;
}

