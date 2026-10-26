
/* WARNING: Removing unreachable block (ram,0x005c9189) */
/* WARNING: Removing unreachable block (ram,0x005c9199) */
/* WARNING: Removing unreachable block (ram,0x005c91a2) */
/* WARNING: Removing unreachable block (ram,0x005c91a5) */
/* WARNING: Removing unreachable block (ram,0x005c9195) */
/* WARNING: Removing unreachable block (ram,0x005c91b3) */
/* WARNING: Removing unreachable block (ram,0x005c91c3) */
/* WARNING: Removing unreachable block (ram,0x005c91ce) */
/* WARNING: Removing unreachable block (ram,0x005c91ca) */
/* WARNING: Removing unreachable block (ram,0x005c91be) */
/* WARNING: Removing unreachable block (ram,0x005c91d1) */

void FUN_005c90a0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009127f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(char *)((int)param_3 + 0x71) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00527e20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x71) == '\0') {
    if (*(char *)(param_3[2] + 0x71) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x71) == '\0') {
    piVar8[1] = (int)piVar7;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar8;
  }
  else if ((int *)*piVar7 == param_3) {
    *piVar7 = (int)piVar8;
  }
  else {
    piVar7[2] = (int)piVar8;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar6 = piVar7;
    if (*(char *)((int)piVar8 + 0x71) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x71);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x71);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x71) == '\0') {
      uVar5 = FUN_00574920();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[0x1c] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[0x1c] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[0x1c] == '\0') {
            *(undefined1 *)(piVar7 + 0x1c) = 1;
            *(undefined1 *)(piVar6 + 0x1c) = 0;
            FUN_005c9730(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x71) == '\0') {
            if ((*(char *)(*piVar7 + 0x70) != '\x01') || (*(char *)(piVar7[2] + 0x70) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x70) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x70) = 1;
                *(undefined1 *)(piVar7 + 0x1c) = 0;
                FUN_00527dc0(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 0x1c) = (char)piVar6[0x1c];
              *(undefined1 *)(piVar6 + 0x1c) = 1;
              *(undefined1 *)(piVar7[2] + 0x70) = 1;
              FUN_005c9730(param_1);
              break;
            }
LAB_005c92a7:
            *(undefined1 *)(piVar7 + 0x1c) = 0;
          }
        }
        else {
          if ((char)piVar7[0x1c] == '\0') {
            *(undefined1 *)(piVar7 + 0x1c) = 1;
            *(undefined1 *)(piVar6 + 0x1c) = 0;
            FUN_00527dc0(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x71) == '\0') {
            if ((*(char *)(piVar7[2] + 0x70) == '\x01') && (*(char *)(*piVar7 + 0x70) == '\x01'))
            goto LAB_005c92a7;
            if (*(char *)(*piVar7 + 0x70) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x70) = 1;
              *(undefined1 *)(piVar7 + 0x1c) = 0;
              FUN_005c9730(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 0x1c) = (char)piVar6[0x1c];
            *(undefined1 *)(piVar6 + 0x1c) = 1;
            *(undefined1 *)(*piVar7 + 0x70) = 1;
            FUN_00527dc0(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 0x1c) = 1;
  }
  local_8 = 0;
  FUN_005c8c10(param_3 + 10);
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
  ExceptionList = local_10;
  return;
}

