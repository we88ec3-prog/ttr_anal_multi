
void FUN_006b5670(void)

{
  int iVar1;
  int in_EAX;
  int unaff_ESI;
  
  if ((-1 < in_EAX) && (in_EAX < 3)) {
    if (in_EAX + 1 < 9) {
      if (in_EAX < 9) {
        do {
          iVar1 = in_EAX + 1;
          if (iVar1 == 9) {
            *(undefined1 *)(unaff_ESI + 0x1d8 + in_EAX) = 0;
          }
          else {
            *(undefined1 *)(unaff_ESI + 0x1d8 + in_EAX) =
                 *(undefined1 *)(in_EAX + 0x1d9 + unaff_ESI);
          }
          in_EAX = iVar1;
        } while (iVar1 < 9);
        FUN_006b4bb0(unaff_ESI);
        FUN_006b4f80(unaff_ESI);
        return;
      }
    }
    else {
      *(undefined1 *)(in_EAX + 0x1d8 + unaff_ESI) = 0;
    }
  }
  FUN_006b4bb0(unaff_ESI);
  FUN_006b4f80(unaff_ESI);
  return;
}

