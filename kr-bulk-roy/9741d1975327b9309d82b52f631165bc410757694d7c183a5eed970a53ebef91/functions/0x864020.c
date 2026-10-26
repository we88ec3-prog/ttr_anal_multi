
void FUN_00864020(void)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  
  if (unaff_ESI[8] != 0) {
    FUN_0089120c(unaff_ESI[8]);
  }
  unaff_ESI[8] = 0;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  if (unaff_ESI[4] != 0) {
    FUN_0089120c(unaff_ESI[4]);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  iVar2 = *unaff_ESI;
  if (iVar2 != 0) {
    iVar1 = unaff_ESI[1];
    for (; iVar2 != iVar1; iVar2 = iVar2 + 0x9c) {
      FUN_0085a2f0(iVar2);
    }
    FUN_0089120c(*unaff_ESI);
  }
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  return;
}

