
void FUN_0044bab0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = (int *)*DAT_00fb9398;
  if (piVar4 != DAT_00fb9398) {
    do {
      FUN_0089120c(piVar4[4]);
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
    } while (piVar4 != DAT_00fb9398);
  }
  cVar1 = *(char *)(DAT_00fb9398[1] + 0x15);
  piVar4 = (int *)DAT_00fb9398[1];
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar4[2]);
    piVar2 = (int *)*piVar4;
    FUN_0089120c(piVar4);
    piVar4 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x15);
  }
  DAT_00fb9398[1] = (int)DAT_00fb9398;
  *DAT_00fb9398 = (int)DAT_00fb9398;
  DAT_00fb9398[2] = (int)DAT_00fb9398;
  DAT_00fb939c = 0;
  return;
}

