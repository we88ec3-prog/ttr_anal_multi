
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dd5d0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)*(int **)(DAT_00fab0e0 + 4) + 0x21);
  piVar3 = *(int **)(DAT_00fab0e0 + 4);
  while (cVar1 == '\0') {
    FUN_008575b0(piVar3[2]);
    piVar2 = (int *)*piVar3;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  *(int *)(DAT_00fab0e0 + 4) = DAT_00fab0e0;
  *(int *)DAT_00fab0e0 = DAT_00fab0e0;
  *(int *)(DAT_00fab0e0 + 8) = DAT_00fab0e0;
  _DAT_00fab0e4 = 0;
  return;
}

