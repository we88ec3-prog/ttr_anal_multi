
void FUN_007ee0d0(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[7] = 0;
  in_EAX[9] = 0;
  in_EAX[8] = 0x41f00000;
  in_EAX[0xf] = 0xf;
  in_EAX[0xe] = 0;
  *(undefined1 *)(in_EAX + 10) = 0;
  in_EAX[0x12] = 0x42c80000;
  return;
}

