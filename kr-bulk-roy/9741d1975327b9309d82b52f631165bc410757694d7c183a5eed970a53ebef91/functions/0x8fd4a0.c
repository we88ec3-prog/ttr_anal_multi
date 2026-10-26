
void FUN_008fd4a0(void)

{
  float *in_EAX;
  int in_EDX;
  
  *(float *)(in_EDX + 0x24) = *in_EAX;
  *(float *)(in_EDX + 0x28) = in_EAX[1];
  if (*(int *)(in_EDX + 0x2c) != 0) {
    FUN_00571dd0((int)*(float *)(in_EDX + 0x24),(int)*(float *)(in_EDX + 0x28));
  }
  return;
}

