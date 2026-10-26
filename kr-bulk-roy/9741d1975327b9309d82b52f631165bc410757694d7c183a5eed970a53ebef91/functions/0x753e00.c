
void FUN_00753e00(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  in_EAX[4] = param_1;
  in_EAX[3] = 0;
  *in_EAX = FoxUI::FXUIEventI2::vftable;
  in_EAX[5] = in_EDX;
  in_EAX[6] = param_2;
  return;
}

