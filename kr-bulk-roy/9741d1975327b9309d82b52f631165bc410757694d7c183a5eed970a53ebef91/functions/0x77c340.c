
void FUN_0077c340(void)

{
  undefined4 *in_EAX;
  
  DAT_00fba828 = DAT_00fba828 + 1;
  in_EAX[1] = DAT_00fba828;
  in_EAX[8] = 7;
  in_EAX[7] = 0;
  *(undefined2 *)(in_EAX + 3) = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xb] = 0;
  in_EAX[10] = 0;
  in_EAX[2] = 0;
  *in_EAX = FoxUI::FXUIImageSetItemRect::vftable;
  return;
}

