
void FUN_0071a2b0(void)

{
  undefined4 uVar1;
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_EDI;
  
  for (; in_ECX != unaff_EDI; in_ECX = in_ECX + 2) {
    if (in_EAX != (undefined4 *)0x0) {
      uVar1 = in_ECX[1];
      *in_EAX = *in_ECX;
      in_EAX[1] = uVar1;
    }
    in_EAX = in_EAX + 2;
  }
  return;
}

