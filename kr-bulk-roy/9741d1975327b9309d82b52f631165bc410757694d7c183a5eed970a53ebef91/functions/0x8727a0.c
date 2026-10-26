
void FUN_008727a0(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x188);
  for (piVar2 = *(int **)(in_ECX + 0x184); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    *(undefined4 *)(*piVar2 + 0x168) = *param_1;
  }
  return;
}

