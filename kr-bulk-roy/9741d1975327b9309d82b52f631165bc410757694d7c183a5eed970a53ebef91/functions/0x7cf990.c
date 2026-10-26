
void FUN_007cf990(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)**(int **)(param_1 + 0x14);
  if (piVar5 != *(int **)(param_1 + 0x14)) {
    do {
      FUN_007ee410();
      iVar2 = piVar5[10];
      if (iVar2 != 0) {
        if (0xf < *(uint *)(iVar2 + 0x3c)) {
          FUN_0089120c(*(undefined4 *)(iVar2 + 0x28));
        }
        *(undefined4 *)(iVar2 + 0x3c) = 0xf;
        *(undefined4 *)(iVar2 + 0x38) = 0;
        *(undefined1 *)(iVar2 + 0x28) = 0;
        if (*(int *)(iVar2 + 0xc) != 0) {
          FUN_0089120c(*(int *)(iVar2 + 0xc));
        }
        *(undefined4 *)(iVar2 + 0xc) = 0;
        *(undefined4 *)(iVar2 + 0x10) = 0;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        FUN_0089120c(iVar2);
        piVar5[10] = 0;
      }
      if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar3 = (int *)piVar5[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          piVar5 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            piVar5 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar4 = (int *)piVar5[1];
          piVar3 = piVar5;
          while ((piVar5 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar4 = (int *)piVar5[1];
            piVar3 = piVar5;
          }
        }
      }
    } while (piVar5 != *(int **)(param_1 + 0x14));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(param_1 + 0x14) + 4));
  *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);
  *(undefined4 *)*(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x14);
  *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

