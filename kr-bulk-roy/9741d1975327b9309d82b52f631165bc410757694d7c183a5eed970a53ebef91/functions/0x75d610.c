
int FUN_0075d610(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int unaff_EDI;
  
  piVar5 = (int *)**(int **)(unaff_EDI + 4);
  iVar4 = 0;
  if (piVar5 != *(int **)(unaff_EDI + 4)) {
    do {
      iVar6 = piVar5[4];
      if ((*(uint *)(iVar6 + 0x28) >> 8 & 1) != 0) {
        if (*(int *)(unaff_EDI + 0x10) == 0) {
          iVar6 = (*(int *)(iVar6 + 0x10) + *(int *)(unaff_EDI + 0x14)) - *(int *)(iVar6 + 8);
        }
        else {
          if (*(int *)(unaff_EDI + 0x10) != 1) goto LAB_0075d651;
          iVar6 = (*(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0xc)) + *(int *)(unaff_EDI + 0x14);
        }
        iVar4 = iVar4 + iVar6;
      }
LAB_0075d651:
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
    } while (piVar5 != *(int **)(unaff_EDI + 4));
  }
  return iVar4;
}

