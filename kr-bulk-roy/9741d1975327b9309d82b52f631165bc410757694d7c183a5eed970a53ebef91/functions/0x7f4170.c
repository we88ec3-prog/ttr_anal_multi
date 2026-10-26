
void FUN_007f4170(void)

{
  undefined4 *in_EAX;
  
  *in_EAX = IS3D::CSkyBox::vftable;
  in_EAX[1] = 0;
  in_EAX[0xcd] = 0xf;
  in_EAX[0xcc] = 0;
  *(undefined1 *)(in_EAX + 200) = 0;
  in_EAX[0xd0] = 0x437a0000;
  in_EAX[0xcf] = 0;
  in_EAX[0xd1] = 0;
  *(undefined1 *)(in_EAX + 0xd3) = 0;
  in_EAX[0xd4] = 0xff7f7f7f;
  in_EAX[0xd2] = 0xc1c80000;
  in_EAX[0xd5] = 1;
  in_EAX[0xc2] = 0;
  in_EAX[0xc3] = 0;
  in_EAX[0xc4] = 0;
  in_EAX[0xc5] = 0;
  in_EAX[0xc6] = 0;
  in_EAX[199] = 0;
  return;
}

