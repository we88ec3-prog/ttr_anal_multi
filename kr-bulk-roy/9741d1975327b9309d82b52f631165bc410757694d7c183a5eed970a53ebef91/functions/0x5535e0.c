
int FUN_005535e0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  piVar7 = (int *)(in_EAX + 4);
  iVar5 = 4;
  do {
    iVar4 = iVar5;
    piVar6 = *(int **)*piVar7;
    if (piVar6 != (int *)*piVar7) {
      do {
        (**(code **)(*(int *)piVar6[4] + 0xc))();
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          piVar2 = (int *)piVar6[2];
          if (*(char *)((int)piVar2 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar2 + 0x15);
              piVar6 = piVar2;
              piVar2 = (int *)*piVar2;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar3 = (int *)piVar6[1];
            piVar2 = piVar6;
            while ((piVar6 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x15);
              piVar3 = (int *)piVar6[1];
              piVar2 = piVar6;
            }
          }
        }
      } while (piVar6 != (int *)*piVar7);
    }
    piVar7 = piVar7 + 4;
    iVar5 = iVar4 + -1;
  } while (iVar5 != 0);
  return iVar4;
}

