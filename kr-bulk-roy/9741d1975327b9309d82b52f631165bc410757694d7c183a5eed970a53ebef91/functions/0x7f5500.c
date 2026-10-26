
void FUN_007f5500(void)

{
  undefined4 *in_EAX;
  
  in_EAX[6] = 0xf;
  in_EAX[5] = 0;
  *(undefined1 *)(in_EAX + 1) = 0;
  in_EAX[0xb] = 0x3eb33333;
  in_EAX[8] = 0;
  in_EAX[0xe] = 0x3f800000;
  in_EAX[9] = 1;
  in_EAX[10] = 0;
  *in_EAX = IS3D::CFieldObjectCacheSimple::vftable;
  in_EAX[0xc] = 0;
  in_EAX[0xd] = 0;
  in_EAX[0xf] = 0;
  return;
}

