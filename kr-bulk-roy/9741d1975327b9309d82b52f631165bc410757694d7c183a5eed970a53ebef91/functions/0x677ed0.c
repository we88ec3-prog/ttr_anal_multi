
void FUN_00677ed0(void)

{
  int *piVar1;
  int *in_EAX;
  int *piVar2;
  int *unaff_EDI;
  
  if (unaff_EDI != in_EAX) {
    piVar1 = (int *)*unaff_EDI;
    piVar2 = (int *)*piVar1;
    *piVar1 = (int)piVar1;
    *(int *)(*unaff_EDI + 4) = *unaff_EDI;
    unaff_EDI[1] = 0;
    if (piVar2 != (int *)*unaff_EDI) {
      do {
        piVar1 = (int *)*piVar2;
        FUN_0089120c(piVar2);
        piVar2 = piVar1;
      } while (piVar1 != (int *)*unaff_EDI);
    }
    if (in_EAX[1] != 0) {
      FUN_00677f30(*(undefined4 *)*unaff_EDI,*(undefined4 *)*in_EAX,(undefined4 *)*in_EAX);
    }
  }
  return;
}

