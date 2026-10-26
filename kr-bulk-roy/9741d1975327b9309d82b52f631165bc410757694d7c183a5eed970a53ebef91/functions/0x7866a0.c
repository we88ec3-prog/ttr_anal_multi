
void FUN_007866a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_EAX;
  int in_EDX;
  
  puVar1 = in_EAX + 1;
  *in_EAX = gbKey<gbQuat>::vftable;
  *puVar1 = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0x3f800000;
  if (puVar1 != (undefined4 *)(in_EDX + 4)) {
    in_EAX[4] = *(undefined4 *)(in_EDX + 0x10);
    *puVar1 = *(undefined4 *)(in_EDX + 4);
    in_EAX[2] = *(undefined4 *)(in_EDX + 8);
    in_EAX[3] = *(undefined4 *)(in_EDX + 0xc);
  }
  in_EAX[5] = *(undefined4 *)(in_EDX + 0x14);
  in_EAX[6] = *(undefined4 *)(in_EDX + 0x18);
  *in_EAX = gbBezKey<gbQuat>::vftable;
  in_EAX[7] = *(undefined4 *)(in_EDX + 0x1c);
  in_EAX[8] = *(undefined4 *)(in_EDX + 0x20);
  in_EAX[9] = *(undefined4 *)(in_EDX + 0x24);
  in_EAX[10] = *(undefined4 *)(in_EDX + 0x28);
  in_EAX[0xb] = *(undefined4 *)(in_EDX + 0x2c);
  in_EAX[0xc] = *(undefined4 *)(in_EDX + 0x30);
  in_EAX[0xd] = *(undefined4 *)(in_EDX + 0x34);
  in_EAX[0xe] = *(undefined4 *)(in_EDX + 0x38);
  in_EAX[6] = 0;
  return;
}

