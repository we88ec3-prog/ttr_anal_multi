
void FUN_005164b0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fe3014 + 4) + 0x19);
  piVar3 = *(int **)(DAT_00fe3014 + 4);
  while (cVar1 == '\0') {
    FUN_004ed5d0(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x19);
  }
  *(int *)(DAT_00fe3014 + 4) = DAT_00fe3014;
  *(int *)DAT_00fe3014 = DAT_00fe3014;
  *(int *)(DAT_00fe3014 + 8) = DAT_00fe3014;
  DAT_00fe3018 = 0;
  return;
}

