
void FUN_006c96a0(void)

{
  code *pcVar1;
  float fVar2;
  int *in_EAX;
  
  in_EAX[0x44] = in_EAX[0x44] + 1;
  fVar2 = ((float)in_EAX[0x44] / (float)in_EAX[0x45]) * 35.0;
  in_EAX[0x46] = (int)fVar2;
  pcVar1 = *(code **)(*(int *)in_EAX[0x3e] + 0x128);
  ((int *)in_EAX[0x3e])[0x34] = (int)fVar2;
  (*pcVar1)();
  (**(code **)(*(int *)in_EAX[0x3e] + 200))();
  if (1.0 <= (float)in_EAX[0x46]) {
    if ((*(uint *)(in_EAX[0x40] + 0x28) >> 9 & 1) != 0) {
      FUN_006c93e0();
      (**(code **)(*in_EAX + 0xd4))();
      return;
    }
    FUN_006c9460(in_EAX);
    (**(code **)(*in_EAX + 0xd4))();
  }
  return;
}

