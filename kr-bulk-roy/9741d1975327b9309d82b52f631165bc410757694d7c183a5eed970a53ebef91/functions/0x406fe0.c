
void FUN_00406fe0(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00404de0(unaff_ESI);
  *(undefined4 *)(in_EAX + 0x80) = *(undefined4 *)(unaff_ESI + 0x80);
  FUN_004026e0(unaff_ESI + 0x84,0,0xffffffff);
  FUN_00405300(in_EAX + 0xa0);
  *(undefined4 *)(in_EAX + 0xd8) = *(undefined4 *)(unaff_ESI + 0xd8);
  *(undefined4 *)(in_EAX + 0xdc) = *(undefined4 *)(unaff_ESI + 0xdc);
  *(undefined4 *)(in_EAX + 0xe0) = *(undefined4 *)(unaff_ESI + 0xe0);
  *(undefined4 *)(in_EAX + 0xe4) = *(undefined4 *)(unaff_ESI + 0xe4);
  *(undefined1 *)(in_EAX + 0xe8) = *(undefined1 *)(unaff_ESI + 0xe8);
  *(undefined1 *)(in_EAX + 0xe9) = *(undefined1 *)(unaff_ESI + 0xe9);
  *(undefined1 *)(in_EAX + 0xea) = *(undefined1 *)(unaff_ESI + 0xea);
  return;
}

