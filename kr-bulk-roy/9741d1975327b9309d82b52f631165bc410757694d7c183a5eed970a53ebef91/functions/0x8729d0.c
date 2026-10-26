
undefined4 FUN_008729d0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x188);
  piVar2 = *(int **)(in_ECX + 0x184);
  if (piVar2 != piVar1) {
    do {
      if (*piVar2 == param_1) break;
      piVar2 = piVar2 + 1;
    } while (piVar2 != piVar1);
    if (piVar2 != piVar1) {
      FUN_00872f20(in_ECX + 0x184,&param_1,piVar2);
      return 1;
    }
  }
  return 0;
}

