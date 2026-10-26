
void FUN_0082aa20(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fc16f0 + 4) + 0x1d);
  piVar3 = *(int **)(DAT_00fc16f0 + 4);
  while (cVar1 == '\0') {
    FUN_0082ab00(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  *(int *)(DAT_00fc16f0 + 4) = DAT_00fc16f0;
  *(int *)DAT_00fc16f0 = DAT_00fc16f0;
  *(int *)(DAT_00fc16f0 + 8) = DAT_00fc16f0;
  DAT_00fc16f4 = 0;
  return;
}

