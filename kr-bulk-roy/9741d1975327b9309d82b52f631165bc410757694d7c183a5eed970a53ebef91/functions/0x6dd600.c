
void FUN_006dd600(void)

{
  int in_EAX;
  undefined4 in_XMM0_Da;
  undefined4 in_XMM2_Da;
  
  if (*(char *)(in_EAX + 0x2c) == '\0') {
    *(undefined4 *)(in_EAX + 0x30) = in_XMM0_Da;
    *(undefined4 *)(in_EAX + 0x34) = 0;
    *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x48) = in_XMM2_Da;
    *(undefined4 *)(in_EAX + 0x4c) = 0;
    *(undefined4 *)(in_EAX + 0x50) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 100) = 0;
    *(float *)(in_EAX + 0x60) = *(float *)(in_EAX + 0x48) - *(float *)(in_EAX + 0x30);
    *(float *)(in_EAX + 0x68) = *(float *)(in_EAX + 0x50) - *(float *)(in_EAX + 0x38);
    *(float *)(in_EAX + 0x18) = *(float *)(in_EAX + 0x60) * 0.03 + *(float *)(in_EAX + 0x18);
  }
  return;
}

