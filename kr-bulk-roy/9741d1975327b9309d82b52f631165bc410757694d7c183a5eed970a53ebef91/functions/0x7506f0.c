
void FUN_007506f0(void)

{
  int *in_EAX;
  
  for (; (in_EAX != (int *)0x0 &&
         ((**(code **)(*in_EAX + 0x15c))(), (*(byte *)(in_EAX + 10) & 1) != 0));
      in_EAX = (int *)in_EAX[0x18]) {
  }
  return;
}

