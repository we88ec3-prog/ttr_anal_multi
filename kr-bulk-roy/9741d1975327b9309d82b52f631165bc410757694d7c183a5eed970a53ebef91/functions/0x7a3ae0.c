
void FUN_007a3ae0(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  
  for (; in_ECX != unaff_ESI; in_ECX = in_ECX + 2) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = 0;
      in_EAX[1] = 0;
      if (in_EAX != in_ECX) {
        uVar1 = in_EAX[1];
        in_EAX[1] = in_ECX[1];
        in_ECX[1] = uVar1;
        uVar1 = *in_EAX;
        *in_EAX = *in_ECX;
        *in_ECX = uVar1;
      }
    }
    in_EAX = in_EAX + 2;
  }
  return;
}

