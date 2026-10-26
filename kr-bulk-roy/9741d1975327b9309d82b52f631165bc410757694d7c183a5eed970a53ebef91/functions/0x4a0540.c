
void FUN_004a0540(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int in_EDX;
  
  *(undefined4 *)(in_EDX + 0x2c) = 1;
  *(undefined4 *)(in_EDX + 0x30) = 1;
  *(undefined4 *)(in_EDX + 0x34) = 1;
  *(undefined4 *)(in_EDX + 0x38) = 1;
  *(undefined4 *)(in_EDX + 0x3c) = 1;
  piVar4 = (int *)**(int **)(in_EDX + 0x14);
  if (piVar4 != *(int **)(in_EDX + 0x14)) {
    do {
      *(undefined1 *)piVar4[4] = 1;
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
    } while (piVar4 != *(int **)(in_EDX + 0x14));
  }
  return;
}

