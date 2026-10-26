
void FUN_0072cb40(void)

{
  int in_EAX;
  int iVar1;
  
  FUN_0072c4e0();
  FUN_0072c4e0();
  FUN_0072c2e0(in_EAX + 0xb30);
  iVar1 = 0x12;
  do {
    if (*(short *)(in_EAX + 0xa7e + (uint)(byte)(&DAT_00c081cc)[iVar1] * 4) != 0) {
LAB_0072cbfb:
      *(int *)(in_EAX + 0x16a8) = *(int *)(in_EAX + 0x16a8) + iVar1 * 3 + 0x11;
      return;
    }
    if (*(short *)(in_EAX + 0xa7e + (uint)(byte)(&UNK_00c081cb)[iVar1] * 4) != 0) {
      *(int *)(in_EAX + 0x16a8) = *(int *)(in_EAX + 0x16a8) + (iVar1 + -1) * 3 + 0x11;
      return;
    }
    if (*(short *)(in_EAX + 0xa7e + (uint)(byte)(&UNK_00c081ca)[iVar1] * 4) != 0) {
      *(int *)(in_EAX + 0x16a8) = *(int *)(in_EAX + 0x16a8) + (iVar1 + -2) * 3 + 0x11;
      return;
    }
    if (*(short *)(in_EAX + 0xa7e + (uint)(byte)(&UNK_00c081c9)[iVar1] * 4) != 0) {
      iVar1 = iVar1 + -3;
      goto LAB_0072cbfb;
    }
    iVar1 = iVar1 + -4;
    if (iVar1 < 3) {
      *(int *)(in_EAX + 0x16a8) = *(int *)(in_EAX + 0x16a8) + iVar1 * 3 + 0x11;
      return;
    }
  } while( true );
}

