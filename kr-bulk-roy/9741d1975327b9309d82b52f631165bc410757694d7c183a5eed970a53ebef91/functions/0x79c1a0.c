
/* WARNING: Removing unreachable block (ram,0x0079c277) */
/* WARNING: Removing unreachable block (ram,0x0079c287) */
/* WARNING: Removing unreachable block (ram,0x0079c290) */
/* WARNING: Removing unreachable block (ram,0x0079c293) */
/* WARNING: Removing unreachable block (ram,0x0079c283) */
/* WARNING: Removing unreachable block (ram,0x0079c2a1) */
/* WARNING: Removing unreachable block (ram,0x0079c2b1) */
/* WARNING: Removing unreachable block (ram,0x0079c2bc) */
/* WARNING: Removing unreachable block (ram,0x0079c2b8) */
/* WARNING: Removing unreachable block (ram,0x0079c2ac) */
/* WARNING: Removing unreachable block (ram,0x0079c2bf) */

void FUN_0079c1a0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0x11) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0079c460();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
    if (*(char *)(param_3[2] + 0x11) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x11) == '\0') {
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
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar4 = piVar5;
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      cVar1 = *(char *)(*piVar6 + 0x11);
      piVar2 = (int *)*piVar6;
      piVar4 = piVar6;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x11);
        piVar4 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar4;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x11) == '\0') {
      cVar1 = *(char *)(piVar6[2] + 0x11);
      piVar4 = (int *)piVar6[2];
      piVar2 = piVar6;
      while (piVar3 = piVar4, cVar1 == '\0') {
        piVar4 = (int *)piVar3[2];
        cVar1 = *(char *)((int)piVar4 + 0x11);
        piVar2 = piVar3;
      }
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar2;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar5;
    }
  }
  if ((char)param_3[4] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar4 = piVar5;
        if ((char)piVar6[4] != '\x01') break;
        piVar5 = (int *)*piVar4;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar4[2];
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar4 + 4) = 0;
            FUN_007c09f0(param_1);
            piVar5 = (int *)piVar4[2];
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(*piVar5 + 0x10) != '\x01') || (*(char *)(piVar5[2] + 0x10) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x10) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x10) = 1;
                *(undefined1 *)(piVar5 + 4) = 0;
                FUN_007e0090(param_1);
                piVar5 = (int *)piVar4[2];
              }
              *(char *)(piVar5 + 4) = (char)piVar4[4];
              *(undefined1 *)(piVar4 + 4) = 1;
              *(undefined1 *)(piVar5[2] + 0x10) = 1;
              FUN_007c09f0(param_1);
              break;
            }
LAB_0079c397:
            *(undefined1 *)(piVar5 + 4) = 0;
          }
        }
        else {
          if ((char)piVar5[4] == '\0') {
            *(undefined1 *)(piVar5 + 4) = 1;
            *(undefined1 *)(piVar4 + 4) = 0;
            FUN_007e0090(param_1);
            piVar5 = (int *)*piVar4;
          }
          if (*(char *)((int)piVar5 + 0x11) == '\0') {
            if ((*(char *)(piVar5[2] + 0x10) == '\x01') && (*(char *)(*piVar5 + 0x10) == '\x01'))
            goto LAB_0079c397;
            if (*(char *)(*piVar5 + 0x10) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x10) = 1;
              *(undefined1 *)(piVar5 + 4) = 0;
              FUN_007c09f0(param_1);
              piVar5 = (int *)*piVar4;
            }
            *(char *)(piVar5 + 4) = (char)piVar4[4];
            *(undefined1 *)(piVar4 + 4) = 1;
            *(undefined1 *)(*piVar5 + 0x10) = 1;
            FUN_007e0090(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar4[1];
        piVar6 = piVar4;
      } while (piVar4 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 4) = 1;
  }
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

