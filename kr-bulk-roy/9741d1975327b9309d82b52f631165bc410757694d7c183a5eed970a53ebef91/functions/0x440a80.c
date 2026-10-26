
void FUN_00440a80(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_EDI;
  
  for (; in_EAX != unaff_EDI; in_EAX = in_EAX + 7) {
    if (0xf < (uint)in_EAX[5]) {
      FUN_0089120c(*in_EAX);
    }
    in_EAX[5] = 0xf;
    in_EAX[4] = 0;
    *(undefined1 *)in_EAX = 0;
  }
  return;
}

