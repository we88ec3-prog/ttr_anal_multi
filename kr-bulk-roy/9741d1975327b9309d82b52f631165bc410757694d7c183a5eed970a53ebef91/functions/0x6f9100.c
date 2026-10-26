
int FUN_006f9100(void)

{
  int in_EAX;
  int iVar1;
  uint *in_EDX;
  
  switch(in_EDX[2]) {
  case 1:
    return ((1 << (*(byte *)(in_EAX + 7) & 0x1f)) - 1U & *in_EDX) * 0x20 + *(int *)(in_EAX + 0x10);
  default:
    return (*in_EDX % ((1 << (*(byte *)(in_EAX + 7) & 0x1f)) - 1U | 1)) * 0x20 +
           *(int *)(in_EAX + 0x10);
  case 3:
    iVar1 = FUN_006f90c0(*(undefined8 *)in_EDX);
    return iVar1;
  case 4:
    return ((1 << (*(byte *)(in_EAX + 7) & 0x1f)) - 1U & *(uint *)(*in_EDX + 8)) * 0x20 +
           *(int *)(in_EAX + 0x10);
  }
}

