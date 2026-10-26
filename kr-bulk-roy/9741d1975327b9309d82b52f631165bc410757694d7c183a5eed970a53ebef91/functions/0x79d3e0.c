
void FUN_0079d3e0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar4 = (int *)**(int **)(unaff_EDI + 0x14);
  if (piVar4 != *(int **)(unaff_EDI + 0x14)) {
    do {
      if (*(undefined4 **)(piVar4[10] + 0x54) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(piVar4[10] + 0x54))(1);
        *(undefined4 *)(piVar4[10] + 0x54) = 0;
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
  FUN_007a10e0(*(undefined4 *)(*(int *)(unaff_EDI + 0x14) + 4));
  *(int *)(*(int *)(unaff_EDI + 0x14) + 4) = *(int *)(unaff_EDI + 0x14);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x14);
  *(int *)(*(int *)(unaff_EDI + 0x14) + 8) = *(int *)(unaff_EDI + 0x14);
  *(undefined4 *)(unaff_EDI + 0x18) = 0;
  return;
}

