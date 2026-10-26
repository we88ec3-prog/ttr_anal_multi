
void FUN_007cf670(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  piVar5 = (int *)**(int **)(param_1 + 0x14);
  if (piVar5 != *(int **)(param_1 + 0x14)) {
    do {
      puVar2 = (undefined4 *)piVar5[10];
      uVar6 = 0;
      if ((int)(puVar2[4] - puVar2[3]) >> 2 != 0) {
        do {
          (**(code **)(**(int **)(puVar2[3] + uVar6 * 4) + 0x10))();
          uVar6 = uVar6 + 1;
        } while (uVar6 < (uint)((int)(puVar2[4] - puVar2[3]) >> 2));
      }
      *puVar2 = 0;
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
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}

