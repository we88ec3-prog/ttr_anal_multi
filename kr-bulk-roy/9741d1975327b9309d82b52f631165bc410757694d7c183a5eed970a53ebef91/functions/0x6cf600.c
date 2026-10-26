
void FUN_006cf600(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = (int *)*DAT_00fc172c;
  piVar5 = DAT_00fc172c;
  if (piVar6 != DAT_00fc172c) {
    do {
      iVar2 = piVar6[10];
      if (iVar2 != 0) {
        FUN_006cce00(iVar2);
        FUN_0089120c(iVar2);
        piVar5 = DAT_00fc172c;
      }
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
    } while (piVar6 != piVar5);
  }
  FUN_007b7d40(piVar5[1]);
  DAT_00fc172c[1] = (int)DAT_00fc172c;
  *DAT_00fc172c = (int)DAT_00fc172c;
  DAT_00fc172c[2] = (int)DAT_00fc172c;
  DAT_00fc1730 = 0;
  return;
}

