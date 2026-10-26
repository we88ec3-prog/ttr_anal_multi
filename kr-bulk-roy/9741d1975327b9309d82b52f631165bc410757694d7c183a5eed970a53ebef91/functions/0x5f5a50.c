
void FUN_005f5a50(void)

{
  int in_EAX;
  int unaff_ESI;
  
  FUN_00404f50();
  *(undefined1 *)(in_EAX + 200) = *(undefined1 *)(unaff_ESI + 200);
  *(undefined4 *)(in_EAX + 0xcc) = *(undefined4 *)(unaff_ESI + 0xcc);
  *(undefined4 *)(in_EAX + 0xd0) = *(undefined4 *)(unaff_ESI + 0xd0);
  *(undefined4 *)(in_EAX + 0xd4) = *(undefined4 *)(unaff_ESI + 0xd4);
  *(undefined4 *)(in_EAX + 0xd8) = *(undefined4 *)(unaff_ESI + 0xd8);
  return;
}

