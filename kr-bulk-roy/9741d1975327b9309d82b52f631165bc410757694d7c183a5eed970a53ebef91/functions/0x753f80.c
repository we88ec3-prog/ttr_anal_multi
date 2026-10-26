
void FUN_00753f80(undefined4 param_1)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  in_EAX[3] = 0;
  in_EAX[4] = 0xf4388;
  *in_EAX = FoxUI::FXUIEventD2::vftable;
  in_EAX[5] = param_1;
  in_EAX[6] = in_EDX;
  return;
}

