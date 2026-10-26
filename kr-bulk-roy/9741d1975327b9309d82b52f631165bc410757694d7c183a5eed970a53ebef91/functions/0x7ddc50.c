
void FUN_007ddc50(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)**(int **)(unaff_EDI + 0x30);
  if (piVar4 != *(int **)(unaff_EDI + 0x30)) {
    do {
      if (piVar4[10] != 0) {
        FUN_0089120c(piVar4[10]);
        piVar4[10] = 0;
      }
      if (*(char *)((int)piVar4 + 0x2d) == '\0') {
        piVar2 = (int *)piVar4[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar4 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar4 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar4[1] + 0x2d);
          piVar3 = (int *)piVar4[1];
          piVar2 = piVar4;
          while ((piVar4 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar4[2]))) {
            cVar1 = *(char *)(piVar4[1] + 0x2d);
            piVar3 = (int *)piVar4[1];
            piVar2 = piVar4;
          }
        }
      }
    } while (piVar4 != *(int **)(unaff_EDI + 0x30));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(unaff_EDI + 0x30) + 4));
  *(int *)(*(int *)(unaff_EDI + 0x30) + 4) = *(int *)(unaff_EDI + 0x30);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 0x30) = *(undefined4 *)(unaff_EDI + 0x30);
  *(int *)(*(int *)(unaff_EDI + 0x30) + 8) = *(int *)(unaff_EDI + 0x30);
  *(undefined4 *)(unaff_EDI + 0x34) = 0;
  return;
}

