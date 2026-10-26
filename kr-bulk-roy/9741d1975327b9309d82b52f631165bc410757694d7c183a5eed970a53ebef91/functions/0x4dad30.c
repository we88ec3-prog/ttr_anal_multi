
void FUN_004dad30(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  int *piVar6;
  int in_EAX;
  int *piVar7;
  
  piVar2 = *(int **)(in_EAX + 0x14);
  piVar7 = (int *)*piVar2;
  bVar5 = false;
  if (piVar7 != piVar2) {
    do {
      iVar3 = piVar7[4];
      if (((*(int *)(iVar3 + 0xc) != 0) && (*(int *)(iVar3 + 8) < param_1)) &&
         (*(int *)(iVar3 + 4) == 0)) {
        bVar5 = true;
        *(undefined4 *)(iVar3 + 0xc) = 0;
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar4 = (int *)piVar7[2];
        if (*(char *)((int)piVar4 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0x15);
          piVar7 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0x15);
            piVar7 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar6 = (int *)piVar7[1];
          piVar4 = piVar7;
          while ((piVar7 = piVar6, cVar1 == '\0' && (piVar4 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar6 = (int *)piVar7[1];
            piVar4 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar2);
    if (bVar5) {
      param_1 = CONCAT22(0xb1,(undefined2)param_1);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
      }
    }
  }
  return;
}

