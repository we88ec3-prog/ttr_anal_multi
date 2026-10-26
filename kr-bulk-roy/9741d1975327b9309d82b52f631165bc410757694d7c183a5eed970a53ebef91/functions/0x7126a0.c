
int FUN_007126a0(void)

{
  int *in_EAX;
  int unaff_ESI;
  
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) {
      return in_EAX[2];
    }
    if ((int)(uint)*(byte *)(unaff_ESI + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      return in_EAX[2];
    }
  }
  FUN_00712630();
  return in_EAX[2];
}

