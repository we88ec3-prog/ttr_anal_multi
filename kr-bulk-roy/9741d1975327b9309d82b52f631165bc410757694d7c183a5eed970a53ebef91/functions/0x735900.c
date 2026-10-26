
void FUN_00735900(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(param_1 + 0x10);
  if (piVar4 != *(int **)(param_1 + 0x10)) {
    do {
      (**(code **)(**(int **)(param_1 + 8) + 0x2c))(piVar4[3]);
      if (*(char *)((int)piVar4 + 0x61) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x61) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x61);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x61);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x61);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x61);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(param_1 + 0x10));
  }
  piVar4 = *(int **)(*(int *)(param_1 + 0x10) + 4);
  cVar1 = *(char *)((int)piVar4 + 0x61);
  while (cVar1 == '\0') {
    FUN_007361f0(piVar4[2]);
    piVar2 = (int *)*piVar4;
    FUN_0089120c(piVar4);
    piVar4 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x61);
  }
  *(int *)(*(int *)(param_1 + 0x10) + 4) = *(int *)(param_1 + 0x10);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(int *)(*(int *)(param_1 + 0x10) + 8) = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_00734a00();
  FUN_00736480(param_1 + 0x24);
  return;
}

