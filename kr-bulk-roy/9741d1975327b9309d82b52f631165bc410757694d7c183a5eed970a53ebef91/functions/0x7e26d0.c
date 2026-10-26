
void FUN_007e26d0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *unaff_EDI;
  
  if (*unaff_EDI == 0) {
    piVar4 = *(int **)unaff_EDI[3];
    if (piVar4 != (int *)unaff_EDI[3]) {
      do {
        (**(code **)(**(int **)(piVar4[10] + 4) + 0xc))();
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
      } while (piVar4 != (int *)unaff_EDI[3]);
    }
    *unaff_EDI = 1;
  }
  return;
}

