
/* WARNING: Removing unreachable block (ram,0x005339c9) */
/* WARNING: Removing unreachable block (ram,0x005339d9) */
/* WARNING: Removing unreachable block (ram,0x005339e2) */
/* WARNING: Removing unreachable block (ram,0x005339e5) */
/* WARNING: Removing unreachable block (ram,0x005339d5) */
/* WARNING: Removing unreachable block (ram,0x005339f3) */
/* WARNING: Removing unreachable block (ram,0x00533a03) */
/* WARNING: Removing unreachable block (ram,0x00533a0e) */
/* WARNING: Removing unreachable block (ram,0x00533a0a) */
/* WARNING: Removing unreachable block (ram,0x005339fe) */
/* WARNING: Removing unreachable block (ram,0x00533a11) */

void FUN_00533900(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x35) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_00533bf0();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x35) == '\0') {
    if (*(char *)(param_3[2] + 0x35) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x35) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x35) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x35);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x35);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x35) == '\0') {
      uVar5 = FUN_00852250();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[0xd] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[0xd] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[0xd] == '\0') {
            *(undefined1 *)(piVar7 + 0xd) = 1;
            *(undefined1 *)(piVar6 + 0xd) = 0;
            FUN_00533b90(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x35) == '\0') {
            if ((*(char *)(*piVar7 + 0x34) != '\x01') || (*(char *)(piVar7[2] + 0x34) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x34) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x34) = 1;
                *(undefined1 *)(piVar7 + 0xd) = 0;
                FUN_008521f0(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 0xd) = (char)piVar6[0xd];
              *(undefined1 *)(piVar6 + 0xd) = 1;
              *(undefined1 *)(piVar7[2] + 0x34) = 1;
              FUN_00533b90(param_1);
              break;
            }
LAB_00533ae7:
            *(undefined1 *)(piVar7 + 0xd) = 0;
          }
        }
        else {
          if ((char)piVar7[0xd] == '\0') {
            *(undefined1 *)(piVar7 + 0xd) = 1;
            *(undefined1 *)(piVar6 + 0xd) = 0;
            FUN_008521f0(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x35) == '\0') {
            if ((*(char *)(piVar7[2] + 0x34) == '\x01') && (*(char *)(*piVar7 + 0x34) == '\x01'))
            goto LAB_00533ae7;
            if (*(char *)(*piVar7 + 0x34) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x34) = 1;
              *(undefined1 *)(piVar7 + 0xd) = 0;
              FUN_00533b90(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 0xd) = (char)piVar6[0xd];
            *(undefined1 *)(piVar6 + 0xd) = 1;
            *(undefined1 *)(*piVar7 + 0x34) = 1;
            FUN_008521f0(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 0xd) = 1;
  }
  if (7 < (uint)param_3[0xb]) {
    FUN_0089120c(param_3[6]);
  }
  param_3[0xb] = 7;
  param_3[10] = 0;
  *(undefined2 *)(param_3 + 6) = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

