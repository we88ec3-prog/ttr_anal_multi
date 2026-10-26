
void FUN_005539a0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  
  if (*(int *)(in_EAX + 0x5c) != 0) {
    iVar5 = 3;
    puVar7 = (undefined4 *)(in_EAX + 0x34);
    do {
      piVar6 = (int *)*puVar7;
      if (piVar6 != (int *)*piVar6) {
        do {
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            piVar4 = (int *)*piVar6;
            if (*(char *)((int)piVar4 + 0x15) == '\0') {
              cVar1 = *(char *)(piVar4[2] + 0x15);
              piVar3 = (int *)piVar4[2];
              while (cVar1 == '\0') {
                cVar1 = *(char *)(piVar3[2] + 0x15);
                piVar4 = piVar3;
                piVar3 = (int *)piVar3[2];
              }
            }
            else {
              cVar1 = *(char *)(piVar6[1] + 0x15);
              piVar3 = (int *)piVar6[1];
              piVar4 = piVar6;
              while ((piVar2 = piVar3, cVar1 == '\0' && (piVar4 == (int *)*piVar2))) {
                cVar1 = *(char *)(piVar2[1] + 0x15);
                piVar3 = (int *)piVar2[1];
                piVar4 = piVar2;
              }
              if (*(char *)((int)piVar4 + 0x15) == '\0') {
                piVar4 = piVar2;
              }
            }
          }
          else {
            piVar4 = (int *)piVar6[2];
          }
          if (*(int *)(piVar4[4] + 0x40) == param_1) {
            if (*(char *)((int)piVar6 + 0x15) == '\0') {
              piVar4 = (int *)*piVar6;
              if (*(char *)((int)piVar4 + 0x15) == '\0') {
                cVar1 = *(char *)(piVar4[2] + 0x15);
                piVar3 = (int *)piVar4[2];
                while (cVar1 == '\0') {
                  cVar1 = *(char *)(piVar3[2] + 0x15);
                  piVar4 = piVar3;
                  piVar3 = (int *)piVar3[2];
                }
              }
              else {
                cVar1 = *(char *)(piVar6[1] + 0x15);
                piVar3 = (int *)piVar6[1];
                piVar4 = piVar6;
                while ((piVar2 = piVar3, cVar1 == '\0' && (piVar4 == (int *)*piVar2))) {
                  cVar1 = *(char *)(piVar2[1] + 0x15);
                  piVar3 = (int *)piVar2[1];
                  piVar4 = piVar2;
                }
                if (*(char *)((int)piVar4 + 0x15) == '\0') {
                  piVar4 = piVar2;
                }
              }
            }
            else {
              piVar4 = (int *)piVar6[2];
            }
            (**(code **)(*(int *)piVar4[4] + 0x18))();
          }
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            piVar4 = (int *)*piVar6;
            if (*(char *)((int)piVar4 + 0x15) == '\0') {
              cVar1 = *(char *)(piVar4[2] + 0x15);
              piVar3 = (int *)piVar4[2];
              while (piVar6 = piVar4, cVar1 == '\0') {
                cVar1 = *(char *)(piVar3[2] + 0x15);
                piVar4 = piVar3;
                piVar3 = (int *)piVar3[2];
              }
            }
            else {
              cVar1 = *(char *)(piVar6[1] + 0x15);
              piVar4 = (int *)piVar6[1];
              while ((piVar3 = piVar4, cVar1 == '\0' && (piVar6 == (int *)*piVar3))) {
                cVar1 = *(char *)(piVar3[1] + 0x15);
                piVar4 = (int *)piVar3[1];
                piVar6 = piVar3;
              }
              if (*(char *)((int)piVar6 + 0x15) == '\0') {
                piVar6 = piVar3;
              }
            }
          }
          else {
            piVar6 = (int *)piVar6[2];
          }
        } while (piVar6 != *(int **)*puVar7);
      }
      puVar7 = puVar7 + -4;
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  return;
}

