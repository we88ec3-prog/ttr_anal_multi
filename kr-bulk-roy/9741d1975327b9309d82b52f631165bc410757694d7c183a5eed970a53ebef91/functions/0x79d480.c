
void FUN_0079d480(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)**(int **)(unaff_EDI + 0x14);
  if (piVar4 != *(int **)(unaff_EDI + 0x14)) {
    do {
      if (*(int *)(piVar4[10] + 0x54) != 0) {
        FUN_007c4de0();
      }
      if (*(char *)((int)piVar4 + 0x31) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x31) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x31);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x31);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x31);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x31);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(unaff_EDI + 0x14));
  }
  FUN_007d2170();
  *(undefined4 *)(unaff_EDI + 0x24) = 1;
  return;
}

