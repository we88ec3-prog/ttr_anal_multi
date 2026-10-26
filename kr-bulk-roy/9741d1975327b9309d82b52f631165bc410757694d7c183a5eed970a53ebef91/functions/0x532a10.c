
/* WARNING: Removing unreachable block (ram,0x00532ad0) */
/* WARNING: Removing unreachable block (ram,0x00532ae0) */
/* WARNING: Removing unreachable block (ram,0x00532ae9) */
/* WARNING: Removing unreachable block (ram,0x00532aec) */
/* WARNING: Removing unreachable block (ram,0x00532adc) */
/* WARNING: Removing unreachable block (ram,0x00532afa) */
/* WARNING: Removing unreachable block (ram,0x00532b0a) */
/* WARNING: Removing unreachable block (ram,0x00532b15) */
/* WARNING: Removing unreachable block (ram,0x00532b11) */
/* WARNING: Removing unreachable block (ram,0x00532b05) */
/* WARNING: Removing unreachable block (ram,0x00532b18) */

void FUN_00532a10(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_3 + 0x55) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0051b140();
  piVar7 = (int *)*param_3;
  if (*(char *)((int)piVar7 + 0x55) == '\0') {
    if (*(char *)(param_3[2] + 0x55) == '\0') {
      piVar7 = (int *)param_3[2];
    }
  }
  else {
    piVar7 = (int *)param_3[2];
  }
  piVar6 = (int *)param_3[1];
  if (*(char *)((int)piVar7 + 0x55) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar6 == param_3) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x55) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x55);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x55);
        piVar5 = piVar3;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar5;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 8) == param_3) {
    if (*(char *)((int)piVar7 + 0x55) == '\0') {
      uVar4 = FUN_00532d50();
      *(undefined4 *)(*(int *)(param_1 + 4) + 8) = uVar4;
    }
    else {
      *(int **)(*(int *)(param_1 + 4) + 8) = piVar6;
    }
  }
  if ((char)param_3[0x15] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0x15] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0x15] == '\0') {
            *(undefined1 *)(piVar6 + 0x15) = 1;
            *(undefined1 *)(piVar5 + 0x15) = 0;
            FUN_005c98b0(param_1);
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x55) == '\0') {
            if ((*(char *)(*piVar6 + 0x54) != '\x01') || (*(char *)(piVar6[2] + 0x54) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x54) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x54) = 1;
                *(undefined1 *)(piVar6 + 0x15) = 0;
                FUN_005c9910(param_1);
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0x15) = (char)piVar5[0x15];
              *(undefined1 *)(piVar5 + 0x15) = 1;
              *(undefined1 *)(piVar6[2] + 0x54) = 1;
              FUN_005c98b0(param_1);
              break;
            }
LAB_00532bfc:
            *(undefined1 *)(piVar6 + 0x15) = 0;
          }
        }
        else {
          if ((char)piVar6[0x15] == '\0') {
            *(undefined1 *)(piVar6 + 0x15) = 1;
            *(undefined1 *)(piVar5 + 0x15) = 0;
            FUN_005c9910(param_1);
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x55) == '\0') {
            if ((*(char *)(piVar6[2] + 0x54) == '\x01') && (*(char *)(*piVar6 + 0x54) == '\x01'))
            goto LAB_00532bfc;
            if (*(char *)(*piVar6 + 0x54) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x54) = 1;
              *(undefined1 *)(piVar6 + 0x15) = 0;
              FUN_005c98b0(param_1);
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0x15) = (char)piVar5[0x15];
            *(undefined1 *)(piVar5 + 0x15) = 1;
            *(undefined1 *)(*piVar6 + 0x54) = 1;
            FUN_005c9910(param_1);
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 0x15) = 1;
  }
  if (7 < (uint)param_3[0x13]) {
    FUN_0089120c(param_3[0xe]);
  }
  param_3[0x13] = 7;
  param_3[0x12] = 0;
  *(undefined2 *)(param_3 + 0xe) = 0;
  if (7 < (uint)param_3[9]) {
    FUN_0089120c(param_3[4]);
  }
  param_3[9] = 7;
  param_3[8] = 0;
  *(undefined2 *)(param_3 + 4) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

