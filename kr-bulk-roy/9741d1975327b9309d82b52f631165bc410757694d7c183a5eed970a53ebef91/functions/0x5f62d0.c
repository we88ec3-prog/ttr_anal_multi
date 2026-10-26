
void FUN_005f62d0(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  in_EAX[3] = 0;
  in_EAX[4] = 0xffffffff;
  *in_EAX = FoxUI::FXUIEventI1P1::vftable;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  return;
}

