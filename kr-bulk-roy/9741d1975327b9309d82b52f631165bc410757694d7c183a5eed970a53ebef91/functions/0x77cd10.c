
void FUN_0077cd10(undefined4 param_1)

{
  undefined4 *in_EAX;
  
  DAT_00fba828 = DAT_00fba828 + 1;
  in_EAX[1] = DAT_00fba828;
  in_EAX[2] = param_1;
  *in_EAX = FoxUI::FXUIBackgroundTexture::vftable;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  *(undefined1 *)(in_EAX + 6) = 0;
  return;
}

