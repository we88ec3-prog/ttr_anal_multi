
void FUN_00754980(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009192f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIControlTextContent::vftable;
  local_8 = 0;
  if (7 < (uint)in_ECX[0x50]) {
    FUN_0089120c(in_ECX[0x4b],uVar1);
  }
  in_ECX[0x50] = 7;
  in_ECX[0x4f] = 0;
  *(undefined2 *)(in_ECX + 0x4b) = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00757640(in_ECX + 0x3a);
  if (7 < (uint)in_ECX[0x38]) {
    FUN_0089120c(in_ECX[0x33],uVar1);
  }
  in_ECX[0x38] = 7;
  in_ECX[0x37] = 0;
  *(undefined2 *)(in_ECX + 0x33) = 0;
  *in_ECX = FoxUI::FXUIControl::vftable;
  local_8 = 2;
  FUN_00744370();
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIRDTarget::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

