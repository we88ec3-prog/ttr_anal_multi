
void FUN_00783e60(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fe31f0 + 4) + 0x15);
  piVar3 = *(int **)(DAT_00fe31f0 + 4);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  *(int *)(DAT_00fe31f0 + 4) = DAT_00fe31f0;
  *(int *)DAT_00fe31f0 = DAT_00fe31f0;
  *(int *)(DAT_00fe31f0 + 8) = DAT_00fe31f0;
  DAT_00fe31f4 = 0;
  return;
}

