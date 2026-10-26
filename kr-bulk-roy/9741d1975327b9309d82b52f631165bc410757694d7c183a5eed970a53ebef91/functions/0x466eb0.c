
void FUN_00466eb0(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00404f50();
  *(undefined1 *)(in_EAX + 200) = *(undefined1 *)(unaff_ESI + 200);
  *(undefined1 *)(in_EAX + 0xc9) = *(undefined1 *)(unaff_ESI + 0xc9);
  *(undefined1 *)(in_EAX + 0xca) = *(undefined1 *)(unaff_ESI + 0xca);
  *(undefined4 *)(in_EAX + 0xcc) = *(undefined4 *)(unaff_ESI + 0xcc);
  FUN_004026e0(unaff_ESI + 0xd0,0,0xffffffff);
  *(undefined4 *)(in_EAX + 0xec) = *(undefined4 *)(unaff_ESI + 0xec);
  *(undefined4 *)(in_EAX + 0xf0) = *(undefined4 *)(unaff_ESI + 0xf0);
  *(undefined4 *)(in_EAX + 0xf4) = *(undefined4 *)(unaff_ESI + 0xf4);
  *(undefined4 *)(in_EAX + 0xf8) = *(undefined4 *)(unaff_ESI + 0xf8);
  *(undefined4 *)(in_EAX + 0xfc) = *(undefined4 *)(unaff_ESI + 0xfc);
  *(undefined4 *)(in_EAX + 0x100) = *(undefined4 *)(unaff_ESI + 0x100);
  *(undefined4 *)(in_EAX + 0x104) = *(undefined4 *)(unaff_ESI + 0x104);
  return;
}

