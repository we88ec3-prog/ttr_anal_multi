
void FUN_00712250(void)

{
  uint *puVar1;
  int *in_EAX;
  int *in_EDX;
  
  if (*in_EAX == 0xd) {
    *in_EAX = 0xc;
    in_EAX[2] = *(uint *)(*(int *)(*in_EDX + 0xc) + in_EAX[2] * 4) >> 6 & 0xff;
    return;
  }
  if (*in_EAX == 0xe) {
    puVar1 = (uint *)(*(int *)(*in_EDX + 0xc) + in_EAX[2] * 4);
    *puVar1 = *puVar1 & 0x7fffff | 0x1000000;
    *in_EAX = 0xb;
  }
  return;
}

