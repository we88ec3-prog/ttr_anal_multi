
void FUN_00741600(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_004026e0(in_EAX,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(in_EAX + 0x1c);
  FUN_004026e0(in_EAX + 0x20,0,0xffffffff);
  FUN_004026e0(in_EAX + 0x3c,0,0xffffffff);
  FUN_004026e0(in_EAX + 0x58,0,0xffffffff);
  return;
}

