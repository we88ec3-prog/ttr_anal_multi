
void FUN_0049fa50(int *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  piVar8 = *(int **)param_1[8];
  if (piVar8 != (int *)param_1[8]) {
    do {
      iVar6 = piVar8[2];
      if ((*(int *)(iVar6 + 0x24) < 1) &&
         ((*(int *)(iVar6 + 8) == 0 ||
          (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
        *(undefined4 *)(piVar8[2] + 0xc) = 1;
        piVar7 = (int *)*piVar8;
        if (piVar8 != (int *)param_1[8]) {
          *(int **)piVar8[1] = piVar7;
          *(int *)(*piVar8 + 4) = piVar8[1];
          FUN_0089120c(piVar8);
          param_1[9] = param_1[9] + -1;
        }
      }
      else {
        piVar7 = (int *)*piVar8;
      }
      piVar8 = piVar7;
    } while (piVar7 != (int *)param_1[8]);
  }
  iVar6 = *param_1;
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x24) < 1)) &&
     ((*(int *)(iVar6 + 8) == 0 ||
      (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
    *(undefined4 *)(*param_1 + 0xc) = 1;
    *param_1 = 0;
  }
  iVar6 = param_1[1];
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x24) < 1)) &&
     ((*(int *)(iVar6 + 8) == 0 ||
      (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
    *(undefined4 *)(param_1[1] + 0xc) = 1;
    param_1[1] = 0;
  }
  iVar6 = param_1[2];
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x24) < 1)) &&
     ((*(int *)(iVar6 + 8) == 0 ||
      (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
    *(undefined4 *)(param_1[2] + 0xc) = 1;
    param_1[2] = 0;
  }
  iVar6 = param_1[3];
  if (((iVar6 != 0) && (*(int *)(iVar6 + 0x24) < 1)) &&
     ((*(int *)(iVar6 + 8) == 0 ||
      (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
    *(undefined4 *)(param_1[3] + 0xc) = 1;
    param_1[3] = 0;
  }
  piVar8 = *(int **)param_1[5];
  if (piVar8 != (int *)param_1[5]) {
    do {
      pcVar2 = (char *)piVar8[4];
      iVar6 = *(int *)(pcVar2 + 4);
      if (((iVar6 != 0) && (*(int *)(iVar6 + 0x24) < 1)) &&
         ((*(int *)(iVar6 + 8) == 0 ||
          (iVar6 = (**(code **)(**(int **)(iVar6 + 8) + 0x10))(), iVar6 == 0)))) {
        *(undefined4 *)(*(int *)(pcVar2 + 4) + 0xc) = 1;
        pcVar2[4] = '\0';
        pcVar2[5] = '\0';
        pcVar2[6] = '\0';
        pcVar2[7] = '\0';
      }
      if ((*pcVar2 != '\0') && (iVar6 = *(int *)(pcVar2 + 4), iVar6 != 0)) {
        if (*(int *)(iVar6 + 8) != 0) {
          (**(code **)(**(int **)(iVar6 + 8) + 0x1c))(0);
        }
        *pcVar2 = '\0';
      }
      if (*(char *)((int)piVar8 + 0x15) == '\0') {
        piVar7 = (int *)piVar8[2];
        if (*(char *)((int)piVar7 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar7 + 0x15);
          piVar8 = piVar7;
          piVar7 = (int *)*piVar7;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar7 + 0x15);
            piVar8 = piVar7;
            piVar7 = (int *)*piVar7;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x15);
          piVar5 = (int *)piVar8[1];
          piVar7 = piVar8;
          while ((piVar8 = piVar5, cVar1 == '\0' && (piVar7 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar5 = (int *)piVar8[1];
            piVar7 = piVar8;
          }
        }
      }
    } while (piVar8 != (int *)param_1[5]);
  }
  if ((param_1[0xb] != 0) && (iVar6 = *param_1, iVar6 != 0)) {
    if (*(int *)(iVar6 + 8) != 0) {
      (**(code **)(**(int **)(iVar6 + 8) + 0x1c))(0);
    }
    param_1[0xb] = 0;
  }
  if ((param_1[0xc] != 0) && (iVar6 = param_1[1], iVar6 != 0)) {
    if (*(int *)(iVar6 + 8) != 0) {
      (**(code **)(**(int **)(iVar6 + 8) + 0x1c))(0);
    }
    param_1[0xc] = 0;
  }
  if ((param_1[0xd] != 0) && (iVar6 = param_1[2], iVar6 != 0)) {
    if (*(int *)(iVar6 + 8) != 0) {
      (**(code **)(**(int **)(iVar6 + 8) + 0x1c))(0);
    }
    param_1[0xd] = 0;
  }
  if ((param_1[0xe] != 0) && (iVar6 = param_1[3], iVar6 != 0)) {
    if (*(int *)(iVar6 + 8) != 0) {
      (**(code **)(**(int **)(iVar6 + 8) + 0x1c))(0);
    }
    param_1[0xe] = 0;
  }
  if (param_1[0xf] != 0) {
    puVar3 = (undefined4 *)param_1[8];
    for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
      if (*(int *)(puVar4[2] + 8) != 0) {
        (**(code **)(**(int **)(puVar4[2] + 8) + 0x1c))(0);
      }
    }
    param_1[0xf] = 0;
  }
  return;
}

