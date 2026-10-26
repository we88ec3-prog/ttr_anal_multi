
void FUN_007e5430(void)

{
  float fVar1;
  int in_EAX;
  
  fVar1 = (float)*(int *)(in_EAX + 0x150) * *(float *)(in_EAX + 0x160);
  *(float *)(in_EAX + 0x158) = fVar1;
  *(float *)(in_EAX + 0x15c) = (float)*(int *)(in_EAX + 0x154) * *(float *)(in_EAX + 0x164);
  **(float **)(in_EAX + 0x180) = 1.0 / fVar1;
  *(float *)(*(int *)(in_EAX + 0x180) + 0x10) = -1.0 / *(float *)(in_EAX + 0x15c);
  *(undefined4 *)(*(int *)(in_EAX + 0x180) + 0x20) = 0x3f800000;
  return;
}

