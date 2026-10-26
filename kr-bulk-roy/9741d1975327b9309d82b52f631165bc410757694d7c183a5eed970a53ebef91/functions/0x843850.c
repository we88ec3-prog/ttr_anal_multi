
void FUN_00843850(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  int in_EDX;
  int *unaff_ESI;
  
  piVar4 = (int *)**(int **)(param_1 + 0x94 + in_EAX * 0x10);
  if (0 < in_EDX) {
    do {
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
      in_EDX = in_EDX + -1;
    } while (in_EDX != 0);
    *unaff_ESI = piVar4[3];
    return;
  }
  *unaff_ESI = piVar4[3];
  return;
}

