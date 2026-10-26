
void FUN_004c66c0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fd9268 + 4) + 0x29);
  piVar3 = *(int **)(DAT_00fd9268 + 4);
  while (cVar1 == '\0') {
    FUN_004c6810(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x29);
  }
  *(int *)(DAT_00fd9268 + 4) = DAT_00fd9268;
  *(int *)DAT_00fd9268 = DAT_00fd9268;
  *(int *)(DAT_00fd9268 + 8) = DAT_00fd9268;
  DAT_00fd926c = 0;
  return;
}

