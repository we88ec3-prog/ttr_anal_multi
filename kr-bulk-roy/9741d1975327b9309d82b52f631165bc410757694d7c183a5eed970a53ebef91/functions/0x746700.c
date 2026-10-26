
void FUN_00746700(int param_1)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 100);
  piVar2 = (int *)*piVar1;
  if (piVar2 != piVar1) {
    while (piVar2[2] != param_1) {
      piVar2 = (int *)*piVar2;
      if (piVar2 == piVar1) {
        return;
      }
    }
    FUN_00746c10();
    FUN_00746b80();
    *(undefined4 *)(piVar2[2] + 0x60) = 0;
    FUN_007486f0(0);
    if (*(int *)(in_ECX + 0x24) != 0) {
      FUN_00750190(piVar2[2]);
    }
    if (piVar2 != *(int **)(in_ECX + 100)) {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
      FUN_0089120c(piVar2);
      *(int *)(in_ECX + 0x68) = *(int *)(in_ECX + 0x68) + -1;
    }
  }
  return;
}

