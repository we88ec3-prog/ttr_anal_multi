
void FUN_007cd8a0(void)

{
  int iVar1;
  undefined4 *in_EAX;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3c) = *in_EAX;
  *(undefined4 *)(in_ECX + 0x40) = in_EAX[1];
  *(undefined4 *)(in_ECX + 0x44) = in_EAX[2];
  iVar1 = *(int *)(in_ECX + 0x20);
  *(undefined4 *)(iVar1 + 0x68) = *in_EAX;
  *(undefined4 *)(iVar1 + 0x6c) = in_EAX[1];
  *(undefined4 *)(iVar1 + 0x70) = in_EAX[2];
  *(undefined4 *)(iVar1 + 0xc0) = 0;
  return;
}

