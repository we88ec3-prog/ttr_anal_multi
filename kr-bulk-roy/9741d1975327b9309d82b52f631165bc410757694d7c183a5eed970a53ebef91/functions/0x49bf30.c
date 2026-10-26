
void FUN_0049bf30(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_EDI;
  
  for (; in_EAX != unaff_EDI; in_EAX = in_EAX + 7) {
    if (7 < (uint)in_EAX[5]) {
      FUN_0089120c(*in_EAX);
    }
    in_EAX[5] = 7;
    in_EAX[4] = 0;
    *(undefined2 *)in_EAX = 0;
  }
  return;
}

