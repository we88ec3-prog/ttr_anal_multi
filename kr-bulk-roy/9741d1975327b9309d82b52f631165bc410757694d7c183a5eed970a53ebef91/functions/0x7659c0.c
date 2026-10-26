
void FUN_007659c0(void)

{
  undefined4 *in_ECX;
  
  FUN_00769170();
  *in_ECX = FoxUI::FXUITextBox::vftable;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x49] = 0x3fa66666;
  in_ECX[0x50] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x55] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x51] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4e] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x43] = 0;
  *(undefined1 *)(in_ECX + 0x4b) = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x4c] = 0;
  *(undefined1 *)(in_ECX + 0x52) = 0;
  *(undefined1 *)(in_ECX + 0x48) = 0;
  *(undefined1 *)(in_ECX + 0x42) = 1;
  return;
}

