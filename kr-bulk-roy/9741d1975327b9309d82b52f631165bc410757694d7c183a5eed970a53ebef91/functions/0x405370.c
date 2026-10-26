
void FUN_00405370(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00404f50();
  *(undefined1 *)(in_EAX + 200) = *(undefined1 *)(unaff_ESI + 200);
  FUN_004026e0(unaff_ESI + 0xcc,0,0xffffffff);
  FUN_00405300(in_EAX + 0xe8);
  *(undefined4 *)(in_EAX + 0x120) = *(undefined4 *)(unaff_ESI + 0x120);
  *(undefined4 *)(in_EAX + 0x124) = *(undefined4 *)(unaff_ESI + 0x124);
  *(undefined4 *)(in_EAX + 0x128) = *(undefined4 *)(unaff_ESI + 0x128);
  FUN_004026e0(unaff_ESI + 300,0,0xffffffff);
  *(undefined4 *)(in_EAX + 0x148) = *(undefined4 *)(unaff_ESI + 0x148);
  *(undefined4 *)(in_EAX + 0x14c) = *(undefined4 *)(unaff_ESI + 0x14c);
  *(undefined4 *)(in_EAX + 0x150) = *(undefined4 *)(unaff_ESI + 0x150);
  *(undefined4 *)(in_EAX + 0x154) = *(undefined4 *)(unaff_ESI + 0x154);
  return;
}

