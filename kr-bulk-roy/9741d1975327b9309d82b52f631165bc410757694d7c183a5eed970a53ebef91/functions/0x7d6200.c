
void FUN_007d6200(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  
  piVar4 = (int *)**(int **)(in_EAX + 0x38);
  if (piVar4 != *(int **)(in_EAX + 0x38)) {
    do {
      if ((undefined4 *)piVar4[4] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar4[4])(1);
        piVar4[4] = 0;
      }
      if (*(char *)((int)piVar4 + 0x15) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x15);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x15);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(in_EAX + 0x38));
  }
  piVar4 = *(int **)(*(int *)(in_EAX + 0x38) + 4);
  cVar1 = *(char *)((int)piVar4 + 0x15);
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar4[2]);
    piVar2 = (int *)*piVar4;
    FUN_0089120c(piVar4);
    piVar4 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  *(int *)(*(int *)(in_EAX + 0x38) + 4) = *(int *)(in_EAX + 0x38);
  *(undefined4 *)*(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0x38);
  *(int *)(*(int *)(in_EAX + 0x38) + 8) = *(int *)(in_EAX + 0x38);
  *(undefined4 *)(in_EAX + 0x3c) = 0;
  return;
}

