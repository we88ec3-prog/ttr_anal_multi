
void FUN_00735280(int param_1,undefined4 *param_2,short *param_3,int param_4,int param_5)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = (int *)**(int **)(param_1 + 0x28);
  if (piVar7 != *(int **)(param_1 + 0x28)) {
    do {
      if ((*(int *)piVar7[3] == param_4) && (((int *)piVar7[3])[8] == param_5)) {
        psVar5 = param_3;
        do {
          sVar2 = *psVar5;
          psVar5 = psVar5 + 1;
        } while (sVar2 != 0);
        iVar6 = FUN_0044df20(0,param_3,(int)psVar5 - (int)(param_3 + 1) >> 1);
        if (iVar6 == 0) {
          *param_2 = piVar7;
          return;
        }
      }
      if (*(char *)((int)piVar7 + 0x11) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x11);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x11);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x11);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x11);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != *(int **)(param_1 + 0x28));
  }
  *param_2 = *(undefined4 *)(param_1 + 0x28);
  return;
}

