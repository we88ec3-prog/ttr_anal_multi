
/* WARNING: Removing unreachable block (ram,0x0083f88b) */
/* WARNING: Removing unreachable block (ram,0x0083f89b) */
/* WARNING: Removing unreachable block (ram,0x0083f8a7) */
/* WARNING: Removing unreachable block (ram,0x0083f8aa) */
/* WARNING: Removing unreachable block (ram,0x0083f897) */
/* WARNING: Removing unreachable block (ram,0x0083f8b8) */
/* WARNING: Removing unreachable block (ram,0x0083f8c8) */
/* WARNING: Removing unreachable block (ram,0x0083f8d3) */
/* WARNING: Removing unreachable block (ram,0x0083f8cf) */
/* WARNING: Removing unreachable block (ram,0x0083f8c3) */
/* WARNING: Removing unreachable block (ram,0x0083f8d6) */

void FUN_0083f7b0(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0x89) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00628740();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x89) == '\0') {
    if (*(char *)(param_3[2] + 0x89) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x89) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x89) == '\0') {
      piVar3 = (int *)FUN_00628720();
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x89) == '\0') {
      uVar4 = FUN_00628700();
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[0x22] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x22] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x22] == '\0') {
            *(undefined1 *)(piVar5 + 0x22) = 1;
            *(undefined1 *)(piVar3 + 0x22) = 0;
            FUN_0083fab0(param_1);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x89) == '\0') {
            if ((*(char *)(*piVar5 + 0x88) != '\x01') || (*(char *)(piVar5[2] + 0x88) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x88) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x88) = 1;
                *(undefined1 *)(piVar5 + 0x22) = 0;
                FUN_0083fb10(param_1);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0x22) = (char)piVar3[0x22];
              *(undefined1 *)(piVar3 + 0x22) = 1;
              *(undefined1 *)(piVar5[2] + 0x88) = 1;
              FUN_0083fab0(param_1);
              break;
            }
LAB_0083fa06:
            *(undefined1 *)(piVar5 + 0x22) = 0;
          }
        }
        else {
          if ((char)piVar5[0x22] == '\0') {
            *(undefined1 *)(piVar5 + 0x22) = 1;
            *(undefined1 *)(piVar3 + 0x22) = 0;
            FUN_0083fb10(param_1);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x89) == '\0') {
            if ((*(char *)(piVar5[2] + 0x88) == '\x01') && (*(char *)(*piVar5 + 0x88) == '\x01'))
            goto LAB_0083fa06;
            if (*(char *)(*piVar5 + 0x88) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x88) = 1;
              *(undefined1 *)(piVar5 + 0x22) = 0;
              FUN_0083fab0(param_1);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0x22) = (char)piVar3[0x22];
            *(undefined1 *)(piVar3 + 0x22) = 1;
            *(undefined1 *)(*piVar5 + 0x88) = 1;
            FUN_0083fb10(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x22) = 1;
  }
  FUN_00839400();
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

