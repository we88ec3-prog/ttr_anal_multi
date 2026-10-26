
void FUN_005d5990(void)

{
  int in_EAX;
  int in_ECX;
  
  FUN_00404f50();
  *(undefined4 *)(in_ECX + 200) = *(undefined4 *)(in_EAX + 200);
  *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(in_EAX + 0xcc);
  *(undefined4 *)(in_ECX + 0xd0) = *(undefined4 *)(in_EAX + 0xd0);
  *(undefined1 *)(in_ECX + 0xd4) = *(undefined1 *)(in_EAX + 0xd4);
  *(undefined4 *)(in_ECX + 0xd8) = *(undefined4 *)(in_EAX + 0xd8);
  FUN_004026e0(in_EAX + 0xdc,0,0xffffffff);
  return;
}

