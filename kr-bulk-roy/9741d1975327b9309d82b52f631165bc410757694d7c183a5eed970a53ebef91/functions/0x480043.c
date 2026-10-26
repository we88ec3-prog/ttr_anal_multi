
void FUN_00480043(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int unaff_EBP;
  int *unaff_ESI;
  
  piVar5 = *(int **)(unaff_EBP + 8);
  if ((piVar5 == (int *)*DAT_00fe1b38) && (*(int **)(unaff_EBP + 0xc) == DAT_00fe1b38)) {
    FUN_00480380();
    *unaff_ESI = *DAT_00fe1b38;
    return;
  }
  if (piVar5 != *(int **)(unaff_EBP + 0xc)) {
    do {
      if (*(char *)((int)piVar5 + 0x2d) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar4 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x2d);
            piVar2 = piVar4;
            piVar4 = (int *)*piVar4;
          }
          *(int **)(unaff_EBP + 8) = piVar2;
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x2d);
          piVar4 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar3 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar3[2]))) {
            *(int **)(unaff_EBP + 8) = piVar3;
            cVar1 = *(char *)(piVar3[1] + 0x2d);
            piVar4 = (int *)piVar3[1];
            piVar2 = piVar3;
          }
          *(int **)(unaff_EBP + 8) = piVar3;
        }
      }
      FUN_004800e0(unaff_EBP + -4,piVar5);
      piVar5 = *(int **)(unaff_EBP + 8);
    } while (piVar5 != *(int **)(unaff_EBP + 0xc));
  }
  *unaff_ESI = (int)piVar5;
  return;
}

