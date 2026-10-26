
undefined4 FUN_008b8520(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EBX;
  
  piVar1 = *(int **)(unaff_EBX + 0x28);
  if (piVar1 == (int *)0x0) {
    return 0x26;
  }
  piVar3 = piVar1 + *(int *)(unaff_EBX + 0x24) + -1;
  piVar4 = piVar3;
  while( true ) {
    if (piVar4 < piVar1) {
      while( true ) {
        if (piVar3 < piVar1) {
          return 0x26;
        }
        if (*(int *)(*piVar3 + 4) == 0x756e6963) break;
        piVar3 = piVar3 + -1;
      }
      *(int *)(unaff_EBX + 0x5c) = *piVar3;
      return 0;
    }
    iVar2 = *piVar4;
    if ((*(int *)(iVar2 + 4) == 0x756e6963) &&
       (((*(short *)(iVar2 + 8) == 3 && (*(short *)(iVar2 + 10) == 10)) ||
        ((*(short *)(iVar2 + 8) == 0 && (*(short *)(iVar2 + 10) == 4)))))) break;
    piVar4 = piVar4 + -1;
  }
  *(int *)(unaff_EBX + 0x5c) = iVar2;
  return 0;
}

