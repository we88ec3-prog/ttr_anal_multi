
void FUN_0077b150(void)

{
  undefined4 *in_ECX;
  
  DAT_00fba828 = DAT_00fba828 + 1;
  in_ECX[1] = DAT_00fba828;
  *in_ECX = FoxUI::FXUIBackgroundSingle::vftable;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  in_ECX[3] = FoxUI::FXUIImageSetItemLink::vftable;
  in_ECX[9] = 0;
  in_ECX[10] = 7;
  *(undefined2 *)(in_ECX + 5) = 0;
  in_ECX[0x11] = 7;
  in_ECX[0x10] = 0;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  in_ECX[0x14] = 0;
  *(undefined2 *)(in_ECX + 0x13) = 0;
  return;
}

