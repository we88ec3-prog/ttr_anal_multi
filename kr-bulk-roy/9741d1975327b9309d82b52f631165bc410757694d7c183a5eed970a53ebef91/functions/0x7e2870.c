
void FUN_007e2870(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)**(int **)(unaff_EDI + 0xc);
  if (piVar4 != *(int **)(unaff_EDI + 0xc)) {
    do {
      if (*(undefined4 **)(piVar4[10] + 4) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(piVar4[10] + 4))(1);
        *(undefined4 *)(piVar4[10] + 4) = 0;
      }
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
    } while (piVar4 != *(int **)(unaff_EDI + 0xc));
  }
  FUN_007b7d40(*(undefined4 *)(*(int *)(unaff_EDI + 0xc) + 4));
  *(int *)(*(int *)(unaff_EDI + 0xc) + 4) = *(int *)(unaff_EDI + 0xc);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(unaff_EDI + 0xc);
  *(int *)(*(int *)(unaff_EDI + 0xc) + 8) = *(int *)(unaff_EDI + 0xc);
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  return;
}

