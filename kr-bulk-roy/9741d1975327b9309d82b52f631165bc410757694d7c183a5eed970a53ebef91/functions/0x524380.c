
void FUN_00524380(void)

{
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  undefined1 *unaff_ESI;
  
  for (; in_ECX != unaff_ESI; in_ECX = in_ECX + 2) {
    if (in_EAX != (undefined1 *)0x0) {
      *in_EAX = *in_ECX;
      in_EAX[1] = in_ECX[1];
    }
    in_EAX = in_EAX + 2;
  }
  return;
}

