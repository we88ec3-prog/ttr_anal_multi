
/* WARNING: Removing unreachable block (ram,0x007e8c10) */
/* WARNING: Removing unreachable block (ram,0x007e8c20) */
/* WARNING: Removing unreachable block (ram,0x007e8c29) */
/* WARNING: Removing unreachable block (ram,0x007e8c2c) */
/* WARNING: Removing unreachable block (ram,0x007e8c1c) */
/* WARNING: Removing unreachable block (ram,0x007e8c3a) */
/* WARNING: Removing unreachable block (ram,0x007e8c4a) */
/* WARNING: Removing unreachable block (ram,0x007e8c55) */
/* WARNING: Removing unreachable block (ram,0x007e8c51) */
/* WARNING: Removing unreachable block (ram,0x007e8c45) */
/* WARNING: Removing unreachable block (ram,0x007e8c58) */

void FUN_007e8b50(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  
  if (*(char *)((int)param_3 + 0x59) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_007aa730();
  piVar6 = (int *)*param_3;
  if (*(char *)((int)piVar6 + 0x59) == '\0') {
    if (*(char *)(param_3[2] + 0x59) == '\0') {
      piVar6 = (int *)param_3[2];
    }
  }
  else {
    piVar6 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar6 + 0x59) == '\0') {
    piVar6[1] = (int)piVar7;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar6;
  }
  else if ((int *)*piVar7 == param_3) {
    *piVar7 = (int)piVar6;
  }
  else {
    piVar7[2] = (int)piVar6;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar5 = piVar7;
    if (*(char *)((int)piVar6 + 0x59) == '\0') {
      cVar1 = *(char *)(*piVar6 + 0x59);
      piVar2 = (int *)*piVar6;
      piVar5 = piVar6;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x59);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar6 + 0x59) == '\0') {
      uVar4 = FUN_007e8e70();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar7;
    }
  }
  if ((char)param_3[0x16] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        if ((char)piVar6[0x16] != '\x01') break;
        piVar5 = (int *)*piVar7;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar7[2];
          if ((char)piVar5[0x16] == '\0') {
            *(undefined1 *)(piVar5 + 0x16) = 1;
            *(undefined1 *)(piVar7 + 0x16) = 0;
            FUN_007e8e10(param_1);
            piVar5 = (int *)piVar7[2];
          }
          if (*(char *)((int)piVar5 + 0x59) == '\0') {
            if ((*(char *)(*piVar5 + 0x58) != '\x01') || (*(char *)(piVar5[2] + 0x58) != '\x01')) {
              if (*(char *)(piVar5[2] + 0x58) == '\x01') {
                *(undefined1 *)(*piVar5 + 0x58) = 1;
                *(undefined1 *)(piVar5 + 0x16) = 0;
                FUN_007aa6d0(param_1);
                piVar5 = (int *)piVar7[2];
              }
              *(char *)(piVar5 + 0x16) = (char)piVar7[0x16];
              *(undefined1 *)(piVar7 + 0x16) = 1;
              *(undefined1 *)(piVar5[2] + 0x58) = 1;
              FUN_007e8e10(param_1);
              break;
            }
LAB_007e8d3c:
            *(undefined1 *)(piVar5 + 0x16) = 0;
          }
        }
        else {
          if ((char)piVar5[0x16] == '\0') {
            *(undefined1 *)(piVar5 + 0x16) = 1;
            *(undefined1 *)(piVar7 + 0x16) = 0;
            FUN_007aa6d0(param_1);
            piVar5 = (int *)*piVar7;
          }
          if (*(char *)((int)piVar5 + 0x59) == '\0') {
            if ((*(char *)(piVar5[2] + 0x58) == '\x01') && (*(char *)(*piVar5 + 0x58) == '\x01'))
            goto LAB_007e8d3c;
            if (*(char *)(*piVar5 + 0x58) == '\x01') {
              *(undefined1 *)(piVar5[2] + 0x58) = 1;
              *(undefined1 *)(piVar5 + 0x16) = 0;
              FUN_007e8e10(param_1);
              piVar5 = (int *)*piVar7;
            }
            *(char *)(piVar5 + 0x16) = (char)piVar7[0x16];
            *(undefined1 *)(piVar7 + 0x16) = 1;
            *(undefined1 *)(*piVar5 + 0x58) = 1;
            FUN_007aa6d0(param_1);
            break;
          }
        }
        bVar8 = piVar7 != *(int **)(*(int *)(param_1 + 4) + 4);
        piVar6 = piVar7;
        piVar7 = (int *)piVar7[1];
      } while (bVar8);
    }
    *(undefined1 *)(piVar6 + 0x16) = 1;
  }
  if (param_3[0x12] != 0) {
    FUN_0089120c(param_3[0x12]);
  }
  param_3[0x12] = 0;
  param_3[0x13] = 0;
  param_3[0x14] = 0;
  if (0xf < (uint)param_3[0x10]) {
    FUN_0089120c(param_3[0xb]);
  }
  param_3[0x10] = 0xf;
  param_3[0xf] = 0;
  *(undefined1 *)(param_3 + 0xb) = 0;
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

