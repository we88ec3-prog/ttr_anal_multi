
void FUN_005da9a0(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00408e60(unaff_ESI);
  *(undefined4 *)(unaff_ESI + 0x298) = *(undefined4 *)(in_EAX + 0x298);
  *(undefined4 *)(unaff_ESI + 0x2a0) = *(undefined4 *)(in_EAX + 0x2a0);
  *(undefined4 *)(unaff_ESI + 0x2a4) = *(undefined4 *)(in_EAX + 0x2a4);
  *(undefined4 *)(unaff_ESI + 0x2a8) = *(undefined4 *)(in_EAX + 0x2a8);
  *(undefined4 *)(unaff_ESI + 0x2ac) = *(undefined4 *)(in_EAX + 0x2ac);
  *(undefined4 *)(unaff_ESI + 0x2b0) = *(undefined4 *)(in_EAX + 0x2b0);
  *(undefined4 *)(unaff_ESI + 0x2b4) = *(undefined4 *)(in_EAX + 0x2b4);
  *(undefined4 *)(unaff_ESI + 0x2b8) = *(undefined4 *)(in_EAX + 0x2b8);
  *(undefined4 *)(unaff_ESI + 700) = *(undefined4 *)(in_EAX + 700);
  *(undefined4 *)(unaff_ESI + 0x2c0) = *(undefined4 *)(in_EAX + 0x2c0);
  *(undefined4 *)(unaff_ESI + 0x2c4) = *(undefined4 *)(in_EAX + 0x2c4);
  FUN_004026e0(in_EAX + 0x2c8,0,0xffffffff);
  return;
}

