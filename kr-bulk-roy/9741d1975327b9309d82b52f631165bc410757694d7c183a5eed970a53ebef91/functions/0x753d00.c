
void FUN_00753d00(undefined1 param_1,undefined4 param_2)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  in_EAX[1] = 0xffffffff;
  in_EAX[2] = 0xffffffff;
  *(undefined1 *)(in_EAX + 5) = param_1;
  in_EAX[3] = 0;
  in_EAX[4] = 0xf4324;
  *in_EAX = FoxUI::FXUIEventB1I2::vftable;
  in_EAX[6] = in_EDX;
  in_EAX[7] = param_2;
  return;
}

