
void FUN_008d3c20(void)

{
  undefined1 uVar1;
  undefined1 *in_EAX;
  uint in_ECX;
  uint uVar2;
  
  if (1 < in_ECX) {
    uVar2 = in_ECX >> 1;
    do {
      uVar1 = *in_EAX;
      *in_EAX = in_EAX[1];
      in_EAX[1] = uVar1;
      in_EAX = in_EAX + 2;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}

