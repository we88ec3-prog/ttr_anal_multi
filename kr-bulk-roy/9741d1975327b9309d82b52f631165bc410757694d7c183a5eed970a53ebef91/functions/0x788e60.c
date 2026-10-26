
void FUN_00788e60(void)

{
  int in_EAX;
  undefined4 *in_ECX;
  undefined4 local_18;
  
  for (; in_EAX != 0; in_EAX = in_EAX + -1) {
    if (in_ECX != (undefined4 *)0x0) {
      FUN_007852a0();
      in_ECX[0x14] = local_18;
      in_ECX[0x15] = 0;
      in_ECX[0x16] = 0;
      *in_ECX = gbTCBRotKey::vftable;
      in_ECX[0x17] = 0;
    }
    in_ECX = in_ECX + 0x18;
  }
  return;
}

