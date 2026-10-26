
int FUN_0073f8e0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  char cVar8;
  int iVar9;
  int *piVar10;
  uint uVar11;
  
  piVar10 = (int *)**(int **)(param_1 + 4);
  if (piVar10 != *(int **)(param_1 + 4)) {
    do {
      if (piVar10[3] != 0) {
        iVar1 = piVar10[4];
        iVar2 = *param_2;
        iVar3 = *(int *)(iVar1 + 8);
        if (*(int *)(iVar2 + 8) == *(int *)(iVar3 + 8)) {
          uVar4 = *(uint *)(iVar3 + 0x1c);
          uVar5 = *(uint *)(iVar2 + 0x1c);
          uVar11 = uVar5;
          if (uVar4 <= uVar5) {
            uVar11 = uVar4;
          }
          iVar9 = FUN_00407e70(uVar11);
          if ((((((iVar9 == 0) && (uVar4 <= uVar5)) && (uVar5 == uVar4)) &&
               ((cVar8 = FUN_006ddb50(), cVar8 != '\0' &&
                (*(int *)(iVar2 + 0x48) == *(int *)(iVar3 + 0x48))))) &&
              ((*(int *)(iVar2 + 0x4c) == *(int *)(iVar3 + 0x4c) &&
               ((*(int *)(iVar2 + 0x50) == *(int *)(iVar3 + 0x50) &&
                (param_2[1] == *(int *)(iVar1 + 0xc))))))) &&
             (((int)(char)param_2[2] == *(int *)(iVar1 + 0x10) &&
              (param_2[3] == *(int *)(iVar1 + 0x14))))) {
            return iVar1;
          }
        }
      }
      if (*(char *)((int)piVar10 + 0x15) == '\0') {
        piVar6 = (int *)piVar10[2];
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          cVar8 = *(char *)(*piVar6 + 0x15);
          piVar10 = piVar6;
          piVar6 = (int *)*piVar6;
          while (cVar8 == '\0') {
            cVar8 = *(char *)(*piVar6 + 0x15);
            piVar10 = piVar6;
            piVar6 = (int *)*piVar6;
          }
        }
        else {
          cVar8 = *(char *)(piVar10[1] + 0x15);
          piVar7 = (int *)piVar10[1];
          piVar6 = piVar10;
          while ((piVar10 = piVar7, cVar8 == '\0' && (piVar6 == (int *)piVar10[2]))) {
            cVar8 = *(char *)(piVar10[1] + 0x15);
            piVar7 = (int *)piVar10[1];
            piVar6 = piVar10;
          }
        }
      }
    } while (piVar10 != *(int **)(param_1 + 4));
  }
  return 0;
}

