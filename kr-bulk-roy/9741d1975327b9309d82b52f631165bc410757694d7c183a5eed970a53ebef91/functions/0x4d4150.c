
undefined4 FUN_004d4150(void)

{
  short sVar1;
  short *psVar2;
  short *in_EDX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x5c) = 1;
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    *(short *)(((unaff_ESI + 0xc) - (int)in_EDX) + (int)psVar2) = sVar1;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  *(uint *)(unaff_ESI + 4) = (uint)*(byte *)(in_EDX + 0x17);
  *(uint *)(unaff_ESI + 0xd4) = (uint)*(byte *)((int)in_EDX + 0x2f);
  *(uint *)(unaff_ESI + 0xdc) = (uint)*(byte *)(in_EDX + 0x18);
  *(undefined4 *)(unaff_ESI + 0x50) = *(undefined4 *)((int)in_EDX + 0x31);
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(in_EDX + 0x15);
  return 1;
}

