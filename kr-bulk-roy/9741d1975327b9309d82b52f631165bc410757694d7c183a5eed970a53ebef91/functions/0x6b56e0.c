
void FUN_006b56e0(void)

{
  uint uVar1;
  uint in_EAX;
  int in_ECX;
  int unaff_ESI;
  
  if ((in_ECX != -1) && ((int)in_EAX < 0)) {
    in_EAX = 0;
    while (*(char *)(unaff_ESI + 0x1d8 + in_EAX) != '\0') {
      in_EAX = in_EAX + 1;
      if (8 < (int)in_EAX) {
        return;
      }
    }
    if (in_EAX == 0xffffffff) {
      return;
    }
  }
  if (in_EAX < 3) {
    if (in_ECX < 0) {
      if (8 < (int)(in_EAX + 1)) {
        *(undefined1 *)(in_EAX + 0x1d8 + unaff_ESI) = 0;
        return;
      }
      if ((int)in_EAX < 9) {
        do {
          uVar1 = in_EAX + 1;
          if (uVar1 == 9) {
            *(undefined1 *)(unaff_ESI + 0x1d8 + in_EAX) = 0;
          }
          else {
            *(undefined1 *)(unaff_ESI + 0x1d8 + in_EAX) =
                 *(undefined1 *)(in_EAX + 0x1d9 + unaff_ESI);
          }
          in_EAX = uVar1;
        } while ((int)uVar1 < 9);
        return;
      }
    }
    else {
      *(char *)(in_EAX + 0x1d8 + unaff_ESI) = (char)in_ECX + '\x01';
    }
  }
  return;
}

