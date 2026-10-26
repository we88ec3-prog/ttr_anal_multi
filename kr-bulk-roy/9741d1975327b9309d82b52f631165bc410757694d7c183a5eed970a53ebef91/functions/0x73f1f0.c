
/* WARNING: Removing unreachable block (ram,0x0073f2cb) */
/* WARNING: Removing unreachable block (ram,0x0073f2db) */
/* WARNING: Removing unreachable block (ram,0x0073f2e7) */
/* WARNING: Removing unreachable block (ram,0x0073f2ea) */
/* WARNING: Removing unreachable block (ram,0x0073f2d7) */
/* WARNING: Removing unreachable block (ram,0x0073f2f8) */
/* WARNING: Removing unreachable block (ram,0x0073f308) */
/* WARNING: Removing unreachable block (ram,0x0073f313) */
/* WARNING: Removing unreachable block (ram,0x0073f30f) */
/* WARNING: Removing unreachable block (ram,0x0073f303) */
/* WARNING: Removing unreachable block (ram,0x0073f316) */

void FUN_0073f1f0(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0x9d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0073f690();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x9d) == '\0') {
    if (*(char *)(param_3[2] + 0x9d) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x9d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x9d) == '\0') {
      piVar3 = (int *)FUN_0073f670();
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(param_1 + 4);
  if (*(int **)(iVar2 + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x9d) == '\0') {
      uVar4 = FUN_0073f650();
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_3[0x27] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0x27] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0x27] == '\0') {
            *(undefined1 *)(piVar5 + 0x27) = 1;
            *(undefined1 *)(piVar3 + 0x27) = 0;
            FUN_0073f590(param_1);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x9d) == '\0') {
            if ((*(char *)(*piVar5 + 0x9c) != '\x01') || (*(char *)(piVar5[2] + 0x9c) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x9c) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x9c) = 1;
                *(undefined1 *)(piVar5 + 0x27) = 0;
                FUN_0073f5f0(param_1);
                piVar5 = (int *)piVar3[2];
              }
              *(char *)(piVar5 + 0x27) = (char)piVar3[0x27];
              *(undefined1 *)(piVar3 + 0x27) = 1;
              *(undefined1 *)(piVar5[2] + 0x9c) = 1;
              FUN_0073f590(param_1);
              break;
            }
LAB_0073f446:
            *(undefined1 *)(piVar5 + 0x27) = 0;
          }
        }
        else {
          if ((char)piVar5[0x27] == '\0') {
            *(undefined1 *)(piVar5 + 0x27) = 1;
            *(undefined1 *)(piVar3 + 0x27) = 0;
            FUN_0073f5f0(param_1);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x9d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x9c) == '\x01') && (*(char *)(*piVar5 + 0x9c) == '\x01'))
            goto LAB_0073f446;
            if (*(char *)(*piVar5 + 0x9c) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x9c) = 1;
              *(undefined1 *)(piVar5 + 0x27) = 0;
              FUN_0073f590(param_1);
              piVar5 = (int *)*piVar3;
            }
            *(char *)(piVar5 + 0x27) = (char)piVar3[0x27];
            *(undefined1 *)(piVar3 + 0x27) = 1;
            *(undefined1 *)(*piVar5 + 0x9c) = 1;
            FUN_0073f5f0(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0x27) = 1;
  }
  FUN_0073e5e0();
  if (7 < (uint)param_3[8]) {
    FUN_0089120c(param_3[3]);
  }
  param_3[8] = 7;
  param_3[7] = 0;
  *(undefined2 *)(param_3 + 3) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

