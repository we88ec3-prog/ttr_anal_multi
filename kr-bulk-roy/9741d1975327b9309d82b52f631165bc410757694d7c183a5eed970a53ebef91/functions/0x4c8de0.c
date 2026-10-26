
undefined4 FUN_004c8de0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  if ((*(int *)(unaff_ESI + 0x15c) != 0) && (*(int *)(unaff_ESI + 0x370) != 0)) {
    iVar1 = FUN_007a7800(unaff_EDI);
    if (iVar1 != 0) {
      return 1;
    }
    piVar2 = (int *)FUN_007a7800(unaff_EDI);
    if ((piVar2 != (int *)0x0) && (iVar1 = (**(code **)(*piVar2 + 4))(), iVar1 == 1)) {
      return 1;
    }
  }
  return 0;
}

