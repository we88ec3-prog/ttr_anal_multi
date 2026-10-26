
void FUN_007fcb60(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)*DAT_00fe3348;
  piVar4 = DAT_00fe3348;
  if (piVar5 != DAT_00fe3348) {
    do {
      if (piVar5[10] != 0) {
        FUN_0089120c(piVar5[10]);
        piVar5[10] = 0;
        piVar4 = DAT_00fe3348;
      }
      if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x2d);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != piVar4);
  }
  return;
}

