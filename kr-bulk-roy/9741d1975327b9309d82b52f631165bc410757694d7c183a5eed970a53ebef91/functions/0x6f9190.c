
int FUN_006f9190(undefined4 param_1)

{
  int iVar1;
  double *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_ESI + 1) == 0) {
    return -1;
  }
  if ((((*(int *)(unaff_ESI + 1) == 3) &&
       (iVar1 = (int)ROUND(*unaff_ESI), *unaff_ESI == (double)iVar1)) && (0 < iVar1)) &&
     (iVar1 <= *(int *)(unaff_EDI + 0x1c))) {
    return iVar1 + -1;
  }
  iVar1 = FUN_006f9100();
  while( true ) {
    if (*(int *)(iVar1 + 0x18) == *(int *)(unaff_ESI + 1)) {
      switch(*(int *)(iVar1 + 0x18)) {
      case 0:
        goto switchD_006f91fa_caseD_0;
      default:
        if (*(int *)(iVar1 + 0x10) == *(int *)unaff_ESI) goto switchD_006f91fa_caseD_0;
        break;
      case 3:
        if (*unaff_ESI == *(double *)(iVar1 + 0x10)) goto switchD_006f91fa_caseD_0;
      }
    }
    if (((*(int *)(iVar1 + 0x18) == 0xb) && (3 < *(int *)(unaff_ESI + 1))) &&
       (*(int *)(iVar1 + 0x10) == *(int *)unaff_ESI)) break;
    iVar1 = *(int *)(iVar1 + 0x1c);
    if (iVar1 == 0) {
      FUN_006f8b60(param_1,"invalid key to \'next\'");
      return 0;
    }
  }
switchD_006f91fa_caseD_0:
  return (iVar1 - *(int *)(unaff_EDI + 0x10) >> 5) + *(int *)(unaff_EDI + 0x1c);
}

