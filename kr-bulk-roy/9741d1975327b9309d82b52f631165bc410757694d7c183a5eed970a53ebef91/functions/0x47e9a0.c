
void FUN_0047e9a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = (int *)*DAT_00fc0f6c;
  piVar5 = DAT_00fc0f6c;
  if (piVar6 != DAT_00fc0f6c) {
    do {
      iVar2 = piVar6[4];
      if (iVar2 != 0) {
        FUN_0047ea70(iVar2);
        FUN_0089120c(iVar2);
        piVar5 = DAT_00fc0f6c;
      }
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
    } while (piVar6 != piVar5);
  }
  cVar1 = *(char *)(piVar5[1] + 0x15);
  piVar6 = (int *)piVar5[1];
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar6[2]);
    piVar5 = (int *)*piVar6;
    FUN_0089120c(piVar6);
    cVar1 = *(char *)((int)piVar5 + 0x15);
    piVar6 = piVar5;
    piVar5 = DAT_00fc0f6c;
  }
  piVar5[1] = (int)piVar5;
  *DAT_00fc0f6c = (int)DAT_00fc0f6c;
  DAT_00fc0f6c[2] = (int)DAT_00fc0f6c;
  DAT_00fc0f70 = 0;
  return;
}

