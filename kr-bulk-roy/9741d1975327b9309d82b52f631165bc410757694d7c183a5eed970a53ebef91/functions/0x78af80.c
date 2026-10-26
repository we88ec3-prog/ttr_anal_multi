
void FUN_0078af80(void)

{
  undefined4 *in_EAX;
  int in_ECX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = gbKey<float>::vftable;
    in_EAX[1] = *(undefined4 *)(in_ECX + 4);
    in_EAX[2] = *(undefined4 *)(in_ECX + 8);
    in_EAX[3] = *(undefined4 *)(in_ECX + 0xc);
    *in_EAX = gbTCBKey<float>::vftable;
    in_EAX[4] = *(undefined4 *)(in_ECX + 0x10);
    in_EAX[5] = *(undefined4 *)(in_ECX + 0x14);
    in_EAX[6] = *(undefined4 *)(in_ECX + 0x18);
    in_EAX[7] = *(undefined4 *)(in_ECX + 0x1c);
    in_EAX[8] = *(undefined4 *)(in_ECX + 0x20);
    in_EAX[9] = *(undefined4 *)(in_ECX + 0x24);
    in_EAX[10] = *(undefined4 *)(in_ECX + 0x28);
  }
  return;
}

