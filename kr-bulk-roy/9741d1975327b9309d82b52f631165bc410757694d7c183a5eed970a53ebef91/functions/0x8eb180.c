
void FUN_008eb180(void)

{
  int iVar1;
  int in_EAX;
  short *in_ECX;
  int in_EDX;
  int unaff_EDI;
  
  *(short *)(in_EAX + 8) = in_ECX[1] - (short)in_EDX;
  *(short *)(in_EAX + 10) = *in_ECX - (short)unaff_EDI;
  iVar1 = in_EDX * 8;
  *(int *)(in_EAX + 0xc) = *(int *)(in_ECX + 10) + iVar1;
  *(int *)(in_EAX + 0x10) = *(int *)(in_ECX + 2) + iVar1;
  *(int *)(in_EAX + 0x14) = *(int *)(in_ECX + 0xc) + iVar1;
  *(int *)(in_EAX + 0x18) = *(int *)(in_ECX + 4) + in_EDX;
  *(int *)(in_EAX + 0x1c) = *(int *)(in_ECX + 6) + unaff_EDI * 2;
  *(short *)(in_EAX + 0x20) = (short)in_EDX;
  return;
}

