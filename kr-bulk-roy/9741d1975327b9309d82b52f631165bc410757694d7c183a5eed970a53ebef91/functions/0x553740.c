
void FUN_00553740(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *piVar7;
  undefined1 local_c [4];
  int local_8;
  
  piVar7 = (int *)(in_EAX + 4);
  local_8 = 4;
  do {
    piVar6 = *(int **)*piVar7;
    if (piVar6 != (int *)*piVar7) {
      do {
        iVar4 = (**(code **)(*(int *)piVar6[4] + 0x28))();
        if (iVar4 == 0) {
          (**(code **)(*(int *)piVar6[4] + 0x10))();
          if ((undefined4 *)piVar6[4] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)piVar6[4])(1);
            piVar6[4] = 0;
          }
          puVar5 = (undefined4 *)FUN_007b6890(piVar7 + -1,local_c,piVar6);
          piVar6 = (int *)*puVar5;
        }
        else if (*(char *)((int)piVar6 + 0x15) == '\0') {
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
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return;
}

