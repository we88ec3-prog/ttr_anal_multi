
void FUN_007cf7b0(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  
  piVar6 = (int *)**(int **)(param_1 + 0x14);
  if (piVar6 != *(int **)(param_1 + 0x14)) {
    do {
      puVar2 = (undefined4 *)piVar6[10];
      uVar5 = 0;
      if ((int)(puVar2[4] - puVar2[3]) >> 2 != 0) {
        do {
          (**(code **)(**(int **)(puVar2[3] + uVar5 * 4) + 0x18))();
          uVar5 = uVar5 + 1;
        } while (uVar5 < (uint)((int)(puVar2[4] - puVar2[3]) >> 2));
      }
      *puVar2 = 1;
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x2d);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x2d);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x2d);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x30) = 1;
  return;
}

