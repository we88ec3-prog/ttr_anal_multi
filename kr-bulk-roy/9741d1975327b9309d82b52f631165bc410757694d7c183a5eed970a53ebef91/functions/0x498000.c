
byte FUN_00498000(void)

{
  byte bVar1;
  byte in_AL;
  int in_EDX;
  
  if (*(byte *)(in_EDX + 0xb) < in_AL) {
    in_AL = *(byte *)(in_EDX + 0xb);
  }
  bVar1 = *(byte *)(in_EDX + 10);
  if (in_AL < bVar1) {
    *(byte *)(in_EDX + 9) = bVar1;
    return bVar1;
  }
  *(byte *)(in_EDX + 9) = in_AL;
  return in_AL;
}

