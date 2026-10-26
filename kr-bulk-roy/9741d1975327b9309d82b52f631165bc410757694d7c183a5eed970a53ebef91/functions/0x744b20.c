
void FUN_00744b20(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  in_EAX[3] = 0;
  in_EAX[4] = 0xffffffff;
  in_EAX[5] = 0;
  *in_EAX = FoxUI::FXUIEventI1S1::vftable;
  in_EAX[0xb] = 7;
  in_EAX[10] = 0;
  *(undefined2 *)(in_EAX + 6) = 0;
  return;
}

