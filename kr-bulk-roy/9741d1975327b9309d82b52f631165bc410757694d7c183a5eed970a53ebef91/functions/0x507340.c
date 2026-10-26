
undefined4 FUN_00507340(void)

{
  int iVar1;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[1];
  if (iVar1 != *unaff_EDI) {
    do {
      (**(code **)(**(int **)(iVar1 + -4) + 8))();
      iVar1 = iVar1 + -4;
    } while (iVar1 != *unaff_EDI);
  }
  iVar1 = unaff_EDI[5];
  if (iVar1 != unaff_EDI[4]) {
    do {
      (**(code **)(**(int **)(iVar1 + -4) + 8))();
      iVar1 = iVar1 + -4;
    } while (iVar1 != unaff_EDI[4]);
  }
  return 1;
}

