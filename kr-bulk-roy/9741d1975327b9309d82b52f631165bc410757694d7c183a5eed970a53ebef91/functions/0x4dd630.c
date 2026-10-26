
void FUN_004dd630(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  piVar6 = (int *)*DAT_00fab0e0;
  piVar5 = DAT_00fab0e0;
  if (piVar6 != DAT_00fab0e0) {
    do {
      iVar2 = piVar6[6];
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 0x54) != 0) {
          FUN_0089120c(*(int *)(iVar2 + 0x54));
          *(undefined4 *)(iVar2 + 0x54) = 0;
        }
        if (*(int *)(iVar2 + 0x44) != 0) {
          FUN_0089120c(*(int *)(iVar2 + 0x44));
        }
        *(undefined4 *)(iVar2 + 0x44) = 0;
        *(undefined4 *)(iVar2 + 0x48) = 0;
        *(undefined4 *)(iVar2 + 0x4c) = 0;
        if (*(int *)(iVar2 + 0x34) != 0) {
          FUN_0089120c(*(int *)(iVar2 + 0x34));
        }
        *(undefined4 *)(iVar2 + 0x34) = 0;
        *(undefined4 *)(iVar2 + 0x38) = 0;
        *(undefined4 *)(iVar2 + 0x3c) = 0;
        FUN_0089120c(iVar2);
        piVar5 = DAT_00fab0e0;
      }
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x21) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x21);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x21);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x21);
          piVar4 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x21);
            piVar4 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != piVar5);
  }
  FUN_004dd5d0();
  return;
}

