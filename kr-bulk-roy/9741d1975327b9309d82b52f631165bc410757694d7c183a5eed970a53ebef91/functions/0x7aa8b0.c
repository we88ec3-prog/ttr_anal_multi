
void FUN_007aa8b0(void)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    piVar2 = in_EAX + 7;
    do {
      if (*piVar2 != 0) {
        FUN_0089120c(*piVar2);
      }
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      if (0xf < (uint)piVar2[-2]) {
        FUN_0089120c(piVar2[-7]);
      }
      piVar2[-2] = 0xf;
      piVar2[-3] = 0;
      *(undefined1 *)(piVar2 + -7) = 0;
      piVar1 = piVar2 + 4;
      piVar2 = piVar2 + 0xb;
    } while (piVar1 != unaff_EDI);
  }
  return;
}

