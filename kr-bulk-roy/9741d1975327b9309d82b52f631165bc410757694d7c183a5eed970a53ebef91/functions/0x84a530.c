
/* WARNING: Removing unreachable block (ram,0x0084a607) */
/* WARNING: Removing unreachable block (ram,0x0084a617) */
/* WARNING: Removing unreachable block (ram,0x0084a620) */
/* WARNING: Removing unreachable block (ram,0x0084a623) */
/* WARNING: Removing unreachable block (ram,0x0084a613) */
/* WARNING: Removing unreachable block (ram,0x0084a631) */
/* WARNING: Removing unreachable block (ram,0x0084a641) */
/* WARNING: Removing unreachable block (ram,0x0084a64c) */
/* WARNING: Removing unreachable block (ram,0x0084a648) */
/* WARNING: Removing unreachable block (ram,0x0084a63c) */
/* WARNING: Removing unreachable block (ram,0x0084a64f) */

void FUN_0084a530(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  if (*(char *)((int)param_3 + 0x2d) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00717a50();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    if (*(char *)(param_3[2] + 0x2d) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar5 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      cVar1 = *(char *)(*piVar6 + 0x2d);
      piVar2 = (int *)*piVar6;
      piVar4 = piVar6;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x2d);
        piVar4 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar4;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      cVar1 = *(char *)(piVar6[2] + 0x2d);
      piVar4 = (int *)piVar6[2];
      piVar2 = piVar6;
      while (piVar3 = piVar4, cVar1 == '\0') {
        piVar4 = (int *)piVar3[2];
        cVar1 = *(char *)((int)piVar4 + 0x2d);
        piVar2 = piVar3;
      }
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar2;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar5;
    }
  }
  if ((char)param_3[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar4 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar4;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar4[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar4 + 0xb) = 0;
            FUN_00840530(param_1);
            piVar5 = (int *)piVar4[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) != '\x01') || (*(char *)(piVar5[2] + 0x2c) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_00736fb0(param_1);
                piVar5 = (int *)piVar4[2];
              }
              *(char *)(piVar5 + 0xb) = (char)piVar4[0xb];
              *(undefined1 *)(piVar4 + 0xb) = 1;
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              FUN_00840530(param_1);
              break;
            }
LAB_0084a727:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar4 + 0xb) = 0;
            FUN_00736fb0(param_1);
            piVar5 = (int *)*piVar4;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) == '\x01') && (*(char *)(*piVar5 + 0x2c) == '\x01'))
            goto LAB_0084a727;
            if (*(char *)(*piVar5 + 0x2c) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_00840530(param_1);
              piVar5 = (int *)*piVar4;
            }
            *(char *)(piVar5 + 0xb) = (char)piVar4[0xb];
            *(undefined1 *)(piVar4 + 0xb) = 1;
            *(undefined1 *)(*piVar5 + 0x2c) = 1;
            FUN_00736fb0(param_1);
            break;
          }
        }
        piVar5 = (int *)piVar4[1];
        piVar6 = piVar4;
      } while (piVar4 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if (0xf < (uint)param_3[8]) {
    FUN_0089120c(param_3[3]);
  }
  param_3[8] = 0xf;
  param_3[7] = 0;
  *(undefined1 *)(param_3 + 3) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

