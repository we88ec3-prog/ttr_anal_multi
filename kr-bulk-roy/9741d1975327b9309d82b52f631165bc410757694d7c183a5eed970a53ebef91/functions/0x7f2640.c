
void FUN_007f2640(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  int in_ECX;
  
  in_EAX[1] = param_2;
  in_EAX[2] = in_ECX;
  *in_EAX = IS3D::CParticle::vftable;
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[3] = uVar1;
  in_EAX[5] = 1;
  in_EAX[4] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  in_EAX[10] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xe] = 0x3f800000;
  in_EAX[0x1f] = 0;
  in_EAX[0x20] = *(undefined4 *)(in_ECX + 0x38);
  in_EAX[0x21] = *(undefined4 *)(in_ECX + 0x3c);
  in_EAX[0x22] = 0;
  in_EAX[0x24] = 0x3f800000;
  in_EAX[0x23] = param_1;
  in_EAX[0x25] = 0;
  in_EAX[0x37] = 0;
  in_EAX[0x26] = 0;
  in_EAX[0x36] = 0;
  in_EAX[0x27] = 0;
  in_EAX[0x35] = 0;
  in_EAX[0x34] = 0;
  in_EAX[0x32] = 0;
  in_EAX[0x31] = 0;
  in_EAX[0x30] = 0;
  in_EAX[0x2f] = 0;
  in_EAX[0x2d] = 0;
  in_EAX[0x2c] = 0;
  in_EAX[0x2b] = 0;
  in_EAX[0x2a] = 0;
  in_EAX[0x38] = 0x3f800000;
  in_EAX[0x33] = 0x3f800000;
  in_EAX[0x2e] = 0x3f800000;
  in_EAX[0x29] = 0x3f800000;
  return;
}

