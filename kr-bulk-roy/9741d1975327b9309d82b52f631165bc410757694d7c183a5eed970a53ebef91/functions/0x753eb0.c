
void FUN_00753eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  in_EAX[5] = param_1;
  in_EAX[6] = in_EDX;
  in_EAX[8] = param_2;
  in_EAX[3] = 0;
  in_EAX[4] = 0xf4310;
  *in_EAX = FoxUI::FXUIEventI4P2::vftable;
  in_EAX[7] = 1;
  in_EAX[9] = param_3;
  in_EAX[10] = param_4;
  return;
}

