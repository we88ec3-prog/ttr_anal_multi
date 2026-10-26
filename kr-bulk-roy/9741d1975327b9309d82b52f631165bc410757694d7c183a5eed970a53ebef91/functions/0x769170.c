
void FUN_00769170(void)

{
  undefined4 *in_ECX;
  
  FUN_00744320();
  in_ECX[0x2c] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x31] = 0;
  *in_ECX = FoxUI::FXUIIMEControl::vftable;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 7;
  *(undefined2 *)(in_ECX + 0x34) = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3b] = 0xffffffff;
  in_ECX[0x40] = 0;
  *(undefined2 *)((int)in_ECX + 0xc9) = 1;
  in_ECX[0x3e] = 0xffffffff;
  in_ECX[0x41] = 0xffffffff;
  in_ECX[0x3f] = 0xff000000;
  *(undefined1 *)(in_ECX + 0x32) = 1;
  return;
}

