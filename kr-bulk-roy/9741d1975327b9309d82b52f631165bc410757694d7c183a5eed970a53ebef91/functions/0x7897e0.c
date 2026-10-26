
void FUN_007897e0(int param_1)

{
  undefined4 *in_EAX;
  int in_ECX;
  
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x60) {
    if (in_EAX != (undefined4 *)0x0) {
      FUN_007852a0();
      *in_EAX = gbTCBRotKey::vftable;
      in_EAX[0x14] = *(undefined4 *)(in_ECX + 0x50);
      in_EAX[0x15] = *(undefined4 *)(in_ECX + 0x54);
      in_EAX[0x16] = *(undefined4 *)(in_ECX + 0x58);
      in_EAX[0x17] = *(undefined4 *)(in_ECX + 0x5c);
    }
    in_EAX = in_EAX + 0x18;
  }
  return;
}

