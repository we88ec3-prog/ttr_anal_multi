
void FUN_00756590(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009158e0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIWindow::vftable;
  local_8 = 1;
  FUN_00757640(in_ECX + 0x28);
  if (7 < (uint)in_ECX[0x26]) {
    FUN_0089120c(in_ECX[0x21],uVar1);
  }
  in_ECX[0x26] = 7;
  in_ECX[0x25] = 0;
  *(undefined2 *)(in_ECX + 0x21) = 0;
  local_8 = 0xffffffff;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

