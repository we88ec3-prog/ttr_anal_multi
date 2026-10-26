
bool FUN_0083a570(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x36c);
  piVar2 = *(int **)(in_ECX + 0x368);
  if (piVar2 != piVar1) {
    do {
      if (*piVar2 == *param_1) break;
      piVar2 = piVar2 + 1;
    } while (piVar2 != piVar1);
  }
  return piVar1 != piVar2;
}

