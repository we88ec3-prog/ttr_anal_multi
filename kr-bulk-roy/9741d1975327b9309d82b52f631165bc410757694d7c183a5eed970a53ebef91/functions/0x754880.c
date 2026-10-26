
void FUN_00754880(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919330;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00744320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  in_ECX[0x2c] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x31] = 0;
  *in_ECX = FoxUI::FXUIControlTextContent::vftable;
  in_ECX[0x38] = 7;
  in_ECX[0x37] = 0;
  *(undefined2 *)(in_ECX + 0x33) = 0;
  local_8 = 1;
  FUN_00757200(in_ECX + 0x3a);
  in_ECX[0x50] = 7;
  in_ECX[0x4f] = 0;
  *(undefined2 *)(in_ECX + 0x4b) = 0;
  in_ECX[0x52] = 0xffffffff;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = 0xffffffff;
  *(undefined1 *)(in_ECX + 0x32) = 1;
  in_ECX[0x48] = 5;
  in_ECX[0x49] = 2;
  ExceptionList = local_10;
  return;
}

