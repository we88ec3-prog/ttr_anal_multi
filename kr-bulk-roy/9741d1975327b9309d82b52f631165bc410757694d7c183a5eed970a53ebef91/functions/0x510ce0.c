
int * FUN_00510ce0(int param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int *piVar3;
  
  iVar1 = (*(int *)(unaff_ESI + 0xc) - *(int *)(unaff_ESI + 8)) / 0x34;
  piVar3 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = *(int **)(unaff_ESI + 8);
    do {
      if (*piVar2 == param_1) {
        piVar3 = piVar2;
      }
      piVar2 = piVar2 + 0xd;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return piVar3;
}

