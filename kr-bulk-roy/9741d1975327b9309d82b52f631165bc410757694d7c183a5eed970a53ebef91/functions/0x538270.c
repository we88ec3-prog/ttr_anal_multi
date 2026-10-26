
void FUN_00538270(int *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  if (param_2 != 0) {
    piVar4 = *(int **)*param_1;
    uVar2 = *(int *)(param_2 + 0x20) - *(int *)(param_2 + 0x1c) >> 4;
    if (piVar4 != (int *)*param_1) {
      do {
        uVar3 = 0;
        if (uVar2 != 0) {
          iVar6 = 0;
          do {
            cVar1 = FUN_00538140(piVar4[2],*(int *)(param_2 + 0x1c) + iVar6);
            if (cVar1 != '\0') goto LAB_00538318;
            uVar3 = uVar3 + 1;
            iVar6 = iVar6 + 0x10;
          } while (uVar3 < uVar2);
        }
        if (uVar2 == 0) {
LAB_00538318:
          piVar5 = (int *)*piVar4;
        }
        else {
          piVar5 = (int *)*piVar4;
          if (piVar4 != (int *)*param_1) {
            *(int **)piVar4[1] = piVar5;
            *(int *)(*piVar4 + 4) = piVar4[1];
            FUN_0089120c(piVar4);
            param_1[1] = param_1[1] + -1;
          }
        }
        piVar4 = piVar5;
      } while (piVar5 != (int *)*param_1);
    }
  }
  return;
}

