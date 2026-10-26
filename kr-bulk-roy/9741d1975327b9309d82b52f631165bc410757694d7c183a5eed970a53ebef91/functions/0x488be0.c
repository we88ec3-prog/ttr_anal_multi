
void FUN_00488be0(void)

{
  int in_EAX;
  int unaff_EDI;
  
  FUN_00406fe0();
  *(undefined4 *)(unaff_EDI + 0xec) = *(undefined4 *)(in_EAX + 0xec);
  *(undefined4 *)(unaff_EDI + 0xf0) = *(undefined4 *)(in_EAX + 0xf0);
  *(undefined1 *)(unaff_EDI + 0xf4) = *(undefined1 *)(in_EAX + 0xf4);
  *(undefined1 *)(unaff_EDI + 0xf5) = *(undefined1 *)(in_EAX + 0xf5);
  *(undefined1 *)(unaff_EDI + 0xf6) = *(undefined1 *)(in_EAX + 0xf6);
  *(undefined1 *)(unaff_EDI + 0xf7) = *(undefined1 *)(in_EAX + 0xf7);
  return;
}

