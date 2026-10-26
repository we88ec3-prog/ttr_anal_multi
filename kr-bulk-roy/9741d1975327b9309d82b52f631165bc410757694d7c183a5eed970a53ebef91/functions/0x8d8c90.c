
void FUN_008d8c90(void)

{
  undefined4 *in_EAX;
  undefined4 in_EDX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[8] = 0;
  in_EAX[7] = in_EDX;
  *(undefined1 *)(in_EAX + 8) = 0;
  FUN_008b82d0();
  return;
}

