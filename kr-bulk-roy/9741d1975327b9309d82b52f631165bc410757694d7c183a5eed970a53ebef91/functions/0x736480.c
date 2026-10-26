
void FUN_00736480(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)**(int **)(param_1 + 4);
  if (piVar5 != *(int **)(param_1 + 4)) {
    do {
      iVar2 = piVar5[3];
      if (iVar2 != 0) {
        if (7 < *(uint *)(iVar2 + 0x18)) {
          FUN_0089120c(*(undefined4 *)(iVar2 + 4));
        }
        *(undefined4 *)(iVar2 + 0x18) = 7;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined2 *)(iVar2 + 4) = 0;
        FUN_0089120c(iVar2);
      }
      if (*(char *)((int)piVar5 + 0x11) == '\0') {
        piVar3 = (int *)piVar5[2];
        if (*(char *)((int)piVar3 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x11);
          piVar5 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x11);
            piVar5 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x11);
          piVar4 = (int *)piVar5[1];
          piVar3 = piVar5;
          while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x11);
            piVar4 = (int *)piVar5[1];
            piVar3 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(param_1 + 4));
  }
  piVar5 = *(int **)(*(int *)(param_1 + 4) + 4);
  cVar1 = *(char *)((int)piVar5 + 0x11);
  while (cVar1 == '\0') {
    FUN_00852020(piVar5[2]);
    piVar3 = (int *)*piVar5;
    FUN_0089120c(piVar5);
    piVar5 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x11);
  }
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

