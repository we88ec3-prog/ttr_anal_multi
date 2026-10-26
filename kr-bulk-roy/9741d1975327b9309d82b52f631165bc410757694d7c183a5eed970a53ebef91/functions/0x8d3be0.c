
void FUN_008d3be0(void)

{
  int in_EAX;
  uint uVar1;
  byte *in_EDX;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    uVar1 = *in_EDX >> 1 & 0x55 | (*in_EDX & 0x55) * 2;
    uVar1 = uVar1 >> 2 & 0x33 | (uVar1 & 0x33) * 4;
    *in_EDX = (byte)(uVar1 >> 4) | (char)uVar1 << 4;
    in_EDX = in_EDX + 1;
  }
  return;
}

