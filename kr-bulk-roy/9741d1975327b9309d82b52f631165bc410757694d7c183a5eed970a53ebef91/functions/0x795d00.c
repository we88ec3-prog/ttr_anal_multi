
void FUN_00795d00(void)

{
  int iVar1;
  int *unaff_ESI;
  int iVar2;
  
  iVar1 = (**(code **)(*unaff_ESI + 0x18))();
  if ((iVar1 < 3) && ((unaff_ESI[3] != 3 || (unaff_ESI[4] != 3)))) {
    FUN_00795170();
    return;
  }
  if ((unaff_ESI[3] == 3) && (unaff_ESI[4] == 3)) {
    iVar2 = 0;
    if (0 < iVar1) {
      do {
        FUN_007957a0();
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1);
      return;
    }
  }
  else {
    iVar2 = 1;
    if (1 < iVar1 + -1) {
      do {
        FUN_007957a0();
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar1 + -1);
    }
    FUN_00795310();
    FUN_00795540();
  }
  return;
}

