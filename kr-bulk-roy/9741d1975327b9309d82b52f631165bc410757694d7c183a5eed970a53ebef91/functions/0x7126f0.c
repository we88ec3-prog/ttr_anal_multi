
void FUN_007126f0(void)

{
  int *in_EAX;
  int unaff_ESI;
  
  if (in_EAX[4] == in_EAX[5]) {
    FUN_007122a0();
    return;
  }
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) {
      return;
    }
    if ((int)(uint)*(byte *)(unaff_ESI + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      return;
    }
  }
  FUN_00712630();
  return;
}

