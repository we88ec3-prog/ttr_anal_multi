
undefined4 FUN_004c9ed0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  
  piVar2 = *(int **)(in_ECX + 0x3f4);
  piVar6 = (int *)*piVar2;
  uVar5 = 0;
  if (piVar6 != piVar2) {
    while ((*(byte *)((int)piVar6 + 0x13) & 1) == 0) {
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
      if (piVar6 == piVar2) {
        return uVar5;
      }
    }
    uVar5 = 1;
  }
  return uVar5;
}

