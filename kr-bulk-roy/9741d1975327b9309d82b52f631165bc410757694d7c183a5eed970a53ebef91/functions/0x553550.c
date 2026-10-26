
void FUN_00553550(undefined4 param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_EAX;
  int *piVar5;
  int *piVar6;
  
  uVar3 = param_2;
  *(undefined4 *)(in_EAX + 0x54) = param_1;
  *(int *)(in_EAX + 0x58) = param_2;
  piVar6 = (int *)(in_EAX + 4);
  param_2 = 4;
  do {
    piVar5 = *(int **)*piVar6;
    if (piVar5 != (int *)*piVar6) {
      do {
        (**(code **)(*(int *)piVar5[4] + 0x20))(param_1,uVar3);
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
            piVar4 = (int *)piVar5[1];
            piVar2 = piVar5;
            while ((piVar5 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
              cVar1 = *(char *)(piVar5[1] + 0x15);
              piVar4 = (int *)piVar5[1];
              piVar2 = piVar5;
            }
          }
        }
      } while (piVar5 != (int *)*piVar6);
    }
    piVar6 = piVar6 + 4;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  return;
}

