
void FUN_008e61e0(void)

{
  int in_EAX;
  int *in_ECX;
  int in_EDX;
  
  if (in_EDX == 1) {
    *in_ECX = *(int *)(in_EAX + 4);
    return;
  }
  if (in_EDX == 2) {
    *in_ECX = *(int *)(in_EAX + 4) + *(int *)(in_EAX + 0xc);
    in_ECX[1] = *(int *)(in_EAX + 8) + *(int *)(in_EAX + 0xc);
    return;
  }
  if (in_EDX == 3) {
    *in_ECX = *(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 0xc) +
              *(int *)(in_EAX + 0x1c);
    in_ECX[1] = *(int *)(in_EAX + 8) + *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x1c) +
                *(int *)(in_EAX + 0x18);
    in_ECX[2] = *(int *)(in_EAX + 0x10) + *(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 0x1c) +
                *(int *)(in_EAX + 0x18);
    return;
  }
  *in_ECX = *(int *)(in_EAX + 4) + *(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x14) +
            *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x3c) + *(int *)(in_EAX + 0x1c) +
            *(int *)(in_EAX + 0x2c) + *(int *)(in_EAX + 0x24);
  in_ECX[1] = *(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x28) + *(int *)(in_EAX + 0x38) +
              *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x3c) + *(int *)(in_EAX + 0x1c) +
              *(int *)(in_EAX + 0x2c) + *(int *)(in_EAX + 0x18);
  in_ECX[2] = *(int *)(in_EAX + 0x10) + *(int *)(in_EAX + 0x38) + *(int *)(in_EAX + 0x34) +
              *(int *)(in_EAX + 0x30) + *(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 0x3c) +
              *(int *)(in_EAX + 0x1c) + *(int *)(in_EAX + 0x18);
  in_ECX[3] = *(int *)(in_EAX + 0x20) + *(int *)(in_EAX + 0x28) + *(int *)(in_EAX + 0x38) +
              *(int *)(in_EAX + 0x34) + *(int *)(in_EAX + 0x30) + *(int *)(in_EAX + 0x3c) +
              *(int *)(in_EAX + 0x2c) + *(int *)(in_EAX + 0x24);
  return;
}

