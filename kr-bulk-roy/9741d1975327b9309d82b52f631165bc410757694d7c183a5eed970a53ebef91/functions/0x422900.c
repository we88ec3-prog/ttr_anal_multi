
void FUN_00422900(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  
  for (; in_ECX != unaff_ESI; in_ECX = (undefined4 *)((int)in_ECX + 5)) {
    if (in_EAX != (undefined4 *)0x0) {
      *in_EAX = *in_ECX;
      *(undefined1 *)(in_EAX + 1) = *(undefined1 *)(in_ECX + 1);
    }
    in_EAX = (undefined4 *)((int)in_EAX + 5);
  }
  return;
}

