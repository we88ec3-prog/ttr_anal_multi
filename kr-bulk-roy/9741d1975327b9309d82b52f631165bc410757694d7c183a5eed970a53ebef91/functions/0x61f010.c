
void FUN_0061f010(void)

{
  int iVar1;
  int unaff_EDI;
  
  if ((*(int *)(*(int *)(unaff_EDI + 0xf4) + 0xcc) != 0) &&
     (*(int *)(*(int *)(unaff_EDI + 0xf4) + 0xd8) != 0)) {
    iVar1 = FUN_005f55a0();
    if (iVar1 != -1) {
      if (iVar1 == 0) {
        FUN_006221d0();
        return;
      }
      if (iVar1 == 1) {
        FUN_00622950();
        return;
      }
      if (iVar1 == 2) {
        FUN_00624da0();
      }
    }
  }
  return;
}

