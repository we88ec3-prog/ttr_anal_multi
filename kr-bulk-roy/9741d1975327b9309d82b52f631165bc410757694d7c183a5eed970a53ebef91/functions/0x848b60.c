
void FUN_00848b60(void)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    piVar2 = in_EAX + 0x15;
    do {
      if (*piVar2 != 0) {
        FUN_0089120c(*piVar2);
      }
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      if (0xf < (uint)piVar2[-0x10]) {
        FUN_0089120c(piVar2[-0x15]);
      }
      piVar2[-0x10] = 0xf;
      piVar2[-0x11] = 0;
      *(undefined1 *)(piVar2 + -0x15) = 0;
      piVar1 = piVar2 + 4;
      piVar2 = piVar2 + 0x19;
    } while (piVar1 != unaff_EDI);
  }
  return;
}

