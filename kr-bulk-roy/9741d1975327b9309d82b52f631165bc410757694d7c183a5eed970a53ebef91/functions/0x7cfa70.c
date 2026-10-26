
void FUN_007cfa70(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  
  if (0 < *(int *)(param_1 + 0x30)) {
    piVar4 = (int *)**(int **)(param_1 + 0x14);
    if (piVar4 != *(int **)(param_1 + 0x14)) {
      do {
        if (*(int *)piVar4[10] == 0) {
          FUN_007ee110();
        }
        if (*(char *)((int)piVar4 + 0x2d) == '\0') {
          piVar2 = (int *)piVar4[2];
          if (*(char *)((int)piVar2 + 0x2d) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x2d);
              piVar4 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar4[1] + 0x2d);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
            while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
              cVar1 = *(char *)(piVar4[1] + 0x2d);
              piVar3 = (int *)piVar4[1];
              piVar2 = piVar4;
            }
          }
        }
      } while (piVar4 != *(int **)(param_1 + 0x14));
    }
    if ((1 < *(int *)(param_1 + 0x30)) &&
       (piVar4 = (int *)**(int **)(param_1 + 0x14), piVar4 != *(int **)(param_1 + 0x14))) {
      do {
        piVar2 = (int *)piVar4[10];
        if (*piVar2 == 1) {
          uVar5 = 0;
          if (piVar2[4] - piVar2[3] >> 2 != 0) {
            do {
              (**(code **)(**(int **)(piVar2[3] + uVar5 * 4) + 0x14))();
              uVar5 = uVar5 + 1;
            } while (uVar5 < (uint)(piVar2[4] - piVar2[3] >> 2));
          }
          *piVar2 = 2;
        }
        if (*(char *)((int)piVar4 + 0x2d) == '\0') {
          piVar2 = (int *)piVar4[2];
          if (*(char *)((int)piVar2 + 0x2d) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x2d);
              piVar4 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar4[1] + 0x2d);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
            while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
              cVar1 = *(char *)(piVar4[1] + 0x2d);
              piVar3 = (int *)piVar4[1];
              piVar2 = piVar4;
            }
          }
        }
      } while (piVar4 != *(int **)(param_1 + 0x14));
    }
  }
  return;
}

