
void FUN_00404ed0(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00404de0(unaff_ESI);
  *(undefined4 *)(in_EAX + 0x80) = *(undefined4 *)(unaff_ESI + 0x80);
  *(undefined4 *)(in_EAX + 0x84) = *(undefined4 *)(unaff_ESI + 0x84);
  *(undefined4 *)(in_EAX + 0x88) = *(undefined4 *)(unaff_ESI + 0x88);
  *(undefined4 *)(in_EAX + 0x8c) = *(undefined4 *)(unaff_ESI + 0x8c);
  *(undefined4 *)(in_EAX + 0x90) = *(undefined4 *)(unaff_ESI + 0x90);
  *(undefined4 *)(in_EAX + 0x94) = *(undefined4 *)(unaff_ESI + 0x94);
  *(undefined4 *)(in_EAX + 0x98) = *(undefined4 *)(unaff_ESI + 0x98);
  *(undefined4 *)(in_EAX + 0x9c) = *(undefined4 *)(unaff_ESI + 0x9c);
  *(undefined4 *)(in_EAX + 0xa0) = *(undefined4 *)(unaff_ESI + 0xa0);
  return;
}

