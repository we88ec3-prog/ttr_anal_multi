
int FUN_004d4210(void)

{
  byte in_AL;
  int in_EDX;
  
  if (6 < in_AL) {
    return 0;
  }
  return in_EDX + 0x110 + (uint)in_AL * 0x1c;
}

