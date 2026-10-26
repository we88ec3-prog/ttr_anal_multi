
void FUN_008d3e70(void)

{
  uint in_EAX;
  int iVar1;
  short *unaff_ESI;
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  byte local_8;
  
  if ((in_EAX & 0xffffff00) == 0) {
    FUN_008bacd0();
    return;
  }
  iVar1 = FUN_008bacd0();
  if (iVar1 == 0) {
    *unaff_ESI = local_c - 0x80;
    unaff_ESI[1] = local_b - 0x80;
    unaff_ESI[2] = local_a - 0x80;
    unaff_ESI[3] = local_9 - 0x80;
    unaff_ESI[4] = local_8 - 0x80;
    unaff_ESI[5] = 0;
  }
  return;
}

