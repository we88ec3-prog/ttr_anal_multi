
void FUN_0082e0c0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  
  uVar5 = FUN_0057ef20();
  FUN_0082f200(param_1 + 0x24,uVar5);
  if (DAT_00fba91c == -1) {
    piVar2 = *(int **)(param_1 + 0x28);
    piVar6 = (int *)*piVar2;
    if (piVar6 != piVar2) {
      DAT_00fba91c = 1;
      do {
        *(undefined4 *)(piVar6[4] + 8) = 0;
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
      } while (piVar6 != piVar2);
    }
  }
  if (0x40 < *(uint *)(param_1 + 0x2c)) {
    FUN_0082e170();
  }
  return;
}

