
/* WARNING: Removing unreachable block (ram,0x004ccbab) */
/* WARNING: Removing unreachable block (ram,0x004ccbbb) */
/* WARNING: Removing unreachable block (ram,0x004ccbc7) */
/* WARNING: Removing unreachable block (ram,0x004ccbca) */
/* WARNING: Removing unreachable block (ram,0x004ccbb7) */
/* WARNING: Removing unreachable block (ram,0x004ccbd8) */
/* WARNING: Removing unreachable block (ram,0x004ccbe8) */
/* WARNING: Removing unreachable block (ram,0x004ccbf3) */
/* WARNING: Removing unreachable block (ram,0x004ccbef) */
/* WARNING: Removing unreachable block (ram,0x004ccbe3) */
/* WARNING: Removing unreachable block (ram,0x004ccbf6) */

void FUN_004ccad0(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0xa1) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_004ccf20();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0xa1) == '\0') {
    if (*(char *)(param_3[2] + 0xa1) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0xa1) == '\0') {
    piVar6[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar5 == param_3) {
    *piVar5 = (int)piVar6;
  }
  else {
    piVar5[2] = (int)piVar6;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  if ((int *)*puVar1 == param_3) {
    piVar3 = piVar5;
    if (*(char *)((int)piVar6 + 0xa1) == '\0') {
      piVar3 = (int *)FUN_004ccf00();
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0xa1) == '\0') {
      uVar4 = FUN_004ccee0();
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[0x28] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x28] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x28] == '\0') {
            *(undefined1 *)(piVar5 + 0x28) = 1;
            *(undefined1 *)(piVar3 + 0x28) = 0;
            FUN_004cce20(param_1);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0xa1) == '\0') {
            if ((*(char *)(*piVar5 + 0xa0) != '\x01') || (*(char *)(piVar5[2] + 0xa0) != '\x01')) {
              if (*(char *)(piVar5[2] + 0xa0) == '\x01') {
                *(undefined1 *)(*piVar5 + 0xa0) = 1;
                *(undefined1 *)(piVar5 + 0x28) = 0;
                FUN_004cce80(param_1);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0x28) = (char)piVar3[0x28];
              *(undefined1 *)(piVar3 + 0x28) = 1;
              *(undefined1 *)(piVar5[2] + 0xa0) = 1;
              FUN_004cce20(param_1);
              break;
            }
LAB_004ccd26:
            *(undefined1 *)(piVar5 + 0x28) = 0;
          }
        }
        else {
          if ((char)piVar5[0x28] == '\0') {
            *(undefined1 *)(piVar5 + 0x28) = 1;
            *(undefined1 *)(piVar3 + 0x28) = 0;
            FUN_004cce80(param_1);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0xa1) == '\0') {
            if ((*(char *)(piVar5[2] + 0xa0) == '\x01') && (*(char *)(*piVar5 + 0xa0) == '\x01'))
            goto LAB_004ccd26;
            if (*(char *)(*piVar5 + 0xa0) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0xa0) = 1;
              *(undefined1 *)(piVar5 + 0x28) = 0;
              FUN_004cce20(param_1);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0x28) = (char)piVar3[0x28];
            *(undefined1 *)(piVar3 + 0x28) = 1;
            *(undefined1 *)(*piVar5 + 0xa0) = 1;
            FUN_004cce80(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x28) = 1;
  }
  FUN_004ccf90();
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

