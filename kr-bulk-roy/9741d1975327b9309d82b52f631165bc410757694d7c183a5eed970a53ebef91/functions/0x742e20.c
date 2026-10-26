
void FUN_00742e20(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = CFTFace::vftable;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0xf;
  *(undefined1 *)(in_EAX + 3) = 0;
  in_EAX[0xf] = 0xf;
  in_EAX[0xe] = 0;
  *(undefined1 *)(in_EAX + 10) = 0;
  in_EAX[0x11] = 0;
  in_EAX[0x12] = 0;
  in_EAX[0x13] = 0;
  in_EAX[0x14] = 0;
  *(undefined1 *)(in_EAX + 0x15) = 0;
  in_EAX[0x16] = 0;
  in_EAX[0x17] = 0;
  in_EAX[0x18] = 0;
  return;
}

