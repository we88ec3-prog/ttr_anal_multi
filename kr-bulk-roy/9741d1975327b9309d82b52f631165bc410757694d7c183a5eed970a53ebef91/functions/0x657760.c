
void FUN_00657760(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  int in_ECX;
  
  *in_EAX = *(undefined4 *)(in_ECX + 0x25c);
  in_EAX[1] = *(undefined4 *)(in_ECX + 0x260);
  uVar1 = *(undefined4 *)(in_ECX + 0x268);
  in_EAX[2] = *(undefined4 *)(in_ECX + 0x264);
  in_EAX[3] = uVar1;
  return;
}

