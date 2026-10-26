
void FUN_006dd510(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_EAX + 0x1c);
  *(undefined4 *)(in_EAX + 0x34) = *(undefined4 *)(in_EAX + 0x20);
  *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0x24);
  *(undefined4 *)(in_EAX + 0x48) = param_1;
  *(undefined4 *)(in_EAX + 0x4c) = param_2;
  *(undefined4 *)(in_EAX + 0x50) = param_3;
  *(float *)(in_EAX + 0x60) = *(float *)(in_EAX + 0x48) - *(float *)(in_EAX + 0x30);
  *(float *)(in_EAX + 100) = *(float *)(in_EAX + 0x4c) - *(float *)(in_EAX + 0x34);
  *(float *)(in_EAX + 0x68) = *(float *)(in_EAX + 0x50) - *(float *)(in_EAX + 0x38);
  *(undefined1 *)(in_EAX + 0x2c) = 1;
  *(undefined4 *)(in_EAX + 0x28) = 0;
  return;
}

