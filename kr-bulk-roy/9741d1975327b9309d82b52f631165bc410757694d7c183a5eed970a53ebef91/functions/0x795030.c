
void FUN_00795030(void)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  
  iVar1 = (**(code **)(*unaff_ESI + 0x18))();
  if ((iVar1 < 3) && ((unaff_ESI[3] != 3 || (unaff_ESI[4] != 3)))) {
    FUN_007948f0();
    return;
  }
  if ((unaff_ESI[3] == 3) && (unaff_ESI[4] == 3)) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        FUN_00794c40();
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
      return;
    }
  }
  else {
    iVar2 = 1;
    if (1 < iVar1 + -1) {
      do {
        FUN_00794c40();
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1 + -1);
    }
    FUN_00794a10();
    FUN_00794b10();
  }
  return;
}

