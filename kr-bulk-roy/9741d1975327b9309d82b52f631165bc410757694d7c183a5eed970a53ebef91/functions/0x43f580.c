
void FUN_0043f580(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  piVar3 = param_1;
  while (cVar1 == '\0') {
    FUN_0043f580(piVar3[2]);
    piVar2 = (int *)*piVar3;
    if (piVar3[4] != 0) {
      FUN_006ab960(param_1);
      FUN_0089120c(piVar3[4]);
    }
    piVar3[4] = 0;
    piVar3[5] = 0;
    piVar3[6] = 0;
    FUN_0089120c(piVar3);
    piVar3 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}

