
void FUN_007f1050(void)

{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0;
  in_EAX[10] = 0;
  in_EAX[2] = 0;
  in_EAX[0xb] = 0;
  in_EAX[3] = 0;
  in_EAX[0xc] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0x3f800000;
  in_EAX[8] = 0x3f800000;
  in_EAX[9] = 0x3f800000;
  in_EAX[0xe] = 0;
  *in_EAX = IS3D::CItemBaseNodeParticle::vftable;
  in_EAX[0x15] = 0xf;
  in_EAX[0x14] = 0;
  *(undefined1 *)(in_EAX + 0x10) = 0;
  in_EAX[0x1c] = 0xf;
  in_EAX[0x1b] = 0;
  *(undefined1 *)(in_EAX + 0x17) = 0;
  return;
}

