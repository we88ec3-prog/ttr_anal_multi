
void FUN_0053f580(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)*DAT_00fe188c;
  piVar4 = DAT_00fe188c;
  if (piVar5 != DAT_00fe188c) {
    do {
      piVar2 = (int *)piVar5[4];
      if (piVar2 != (int *)0x0) {
        if (*piVar2 != 0) {
          FUN_0089120c(*piVar2);
        }
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar2[2] = 0;
        FUN_0089120c(piVar2);
        piVar4 = DAT_00fe188c;
      }
      if (*(char *)((int)piVar5 + 0x15) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x15);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != piVar4);
  }
  FUN_0053f480();
  return;
}

