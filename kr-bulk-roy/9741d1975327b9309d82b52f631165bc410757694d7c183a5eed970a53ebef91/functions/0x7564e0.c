
void FUN_007564e0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009158e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007451f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *in_ECX = FoxUI::FXUIWindow::vftable;
  in_ECX[0x26] = 7;
  in_ECX[0x25] = 0;
  *(undefined2 *)(in_ECX + 0x21) = 0;
  local_8 = 1;
  FUN_00757200(in_ECX + 0x28);
  in_ECX[0x39] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x36] = 0;
  *(undefined1 *)((int)in_ECX + 0xea) = 1;
  *(undefined2 *)(in_ECX + 0x3a) = 1;
  in_ECX[0x20] = 0;
  ExceptionList = local_10;
  return;
}

