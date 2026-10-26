
void FUN_00849e30(void)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != 0) {
    fVar1 = (float)*(int *)(unaff_ESI + 0x84);
    if (*(int *)(unaff_ESI + 0x84) < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    fVar2 = (float)*(int *)(unaff_ESI + 0x88);
    if (*(int *)(unaff_ESI + 0x88) < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    (**(code **)(*unaff_EDI + 0x38))
              (*(undefined4 *)(unaff_ESI + 0x74),fVar1 / fVar2,*(undefined4 *)(unaff_ESI + 0x78),
               *(undefined4 *)(unaff_ESI + 0x7c));
    unaff_EDI[0x33] = unaff_ESI;
  }
  return;
}

