
void FUN_0064f260(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(in_ECX + 0xdc);
  iVar3 = 4;
  do {
    if (piVar4[-8] != 0) {
      piVar2 = *(int **)(piVar4[-8] + 8);
      if (piVar2 != (int *)0x0) {
        piVar1 = piVar2 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 0x28))();
        }
      }
      piVar4[-8] = 0;
    }
    if (*piVar4 != 0) {
      piVar2 = *(int **)(*piVar4 + 8);
      if (piVar2 != (int *)0x0) {
        piVar1 = piVar2 + 0x27;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)(*piVar2 + 0x28))();
        }
      }
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

