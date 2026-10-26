
void FUN_0055e7f0(void)

{
  int *in_EAX;
  float local_c;
  float local_8;
  
  if (((int *)*in_EAX != (int *)0x0) && (1 < in_EAX[4])) {
    local_c = (float)in_EAX[1] * 0.03125 + 2.0;
    local_8 = (float)in_EAX[2] * 0.03125 + 2.0;
    (**(code **)(*(int *)*in_EAX + 0x24))
              (0xffffffe0,0xffffffe0,0,&local_c,0,0,(uint)*(byte *)(in_EAX + 4) << 0x18 | 0xffffff);
  }
  return;
}

