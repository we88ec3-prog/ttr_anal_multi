
undefined4 FUN_0083fd10(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int in_EAX;
  int *piVar5;
  
  piVar2 = *(int **)(in_EAX + 4);
  piVar5 = (int *)*piVar2;
  if (piVar5 != piVar2) {
    do {
      if (piVar5[10] == *param_1) {
        *param_2 = piVar5 + 3;
        return 1;
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
    } while (piVar5 != piVar2);
  }
  return 0;
}

