
/* WARNING: Removing unreachable block (ram,0x00844f59) */
/* WARNING: Removing unreachable block (ram,0x00844f69) */
/* WARNING: Removing unreachable block (ram,0x00844f72) */
/* WARNING: Removing unreachable block (ram,0x00844f75) */
/* WARNING: Removing unreachable block (ram,0x00844f65) */
/* WARNING: Removing unreachable block (ram,0x00844f83) */
/* WARNING: Removing unreachable block (ram,0x00844f93) */
/* WARNING: Removing unreachable block (ram,0x00844f9e) */
/* WARNING: Removing unreachable block (ram,0x00844f9a) */
/* WARNING: Removing unreachable block (ram,0x00844f8e) */
/* WARNING: Removing unreachable block (ram,0x00844fa1) */

void FUN_00844e90(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  
  if (*(char *)((int)param_3 + 0x15) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0049e6a0();
  piVar9 = (int *)*param_3;
  if (*(char *)((int)piVar9 + 0x15) == '\0') {
    if (*(char *)(param_3[2] + 0x15) == '\0') {
      piVar9 = (int *)param_3[2];
    }
  }
  else {
    piVar9 = (int *)param_3[2];
  }
  piVar8 = (int *)param_3[1];
  if (*(char *)((int)piVar9 + 0x15) == '\0') {
    piVar9[1] = (int)piVar8;
  }
  if (*(int **)(*(int *)(param_1 + 4) + 4) == param_3) {
    *(int **)(*(int *)(param_1 + 4) + 4) = piVar9;
  }
  else if ((int *)*piVar8 == param_3) {
    *piVar8 = (int)piVar9;
  }
  else {
    piVar8[2] = (int)piVar9;
  }
  if ((int *)**(undefined4 **)(param_1 + 4) == param_3) {
    piVar7 = piVar8;
    if (*(char *)((int)piVar9 + 0x15) == '\0') {
      cVar1 = *(char *)(*piVar9 + 0x15);
      piVar2 = (int *)*piVar9;
      piVar7 = piVar9;
      while (piVar5 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar5;
        cVar1 = *(char *)((int)piVar2 + 0x15);
        piVar7 = piVar5;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar7;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar9 + 0x15) == '\0') {
      uVar6 = FUN_00823b80();
      *(undefined4 *)(iVar3 + 8) = uVar6;
    }
    else {
      *(int **)(iVar3 + 8) = piVar8;
    }
  }
  if ((char)param_3[5] == '\x01') {
    if (piVar9 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar7 = piVar8;
        if ((char)piVar9[5] != '\x01') break;
        piVar8 = (int *)*piVar7;
        if (piVar9 == piVar8) {
          piVar8 = (int *)piVar7[2];
          if ((char)piVar8[5] == '\0') {
            *(undefined1 *)(piVar8 + 5) = 1;
            *(undefined1 *)(piVar7 + 5) = 0;
            FUN_00763f60(param_1);
            piVar8 = (int *)piVar7[2];
          }
          if (*(char *)((int)piVar8 + 0x15) == '\0') {
            if ((*(char *)(*piVar8 + 0x14) != '\x01') || (*(char *)(piVar8[2] + 0x14) != '\x01')) {
              if (*(char *)(piVar8[2] + 0x14) == '\x01') {
                *(undefined1 *)(*piVar8 + 0x14) = 1;
                *(undefined1 *)(piVar8 + 5) = 0;
                FUN_0043e670(param_1);
                piVar8 = (int *)piVar7[2];
              }
              *(char *)(piVar8 + 5) = (char)piVar7[5];
              *(undefined1 *)(piVar7 + 5) = 1;
              *(undefined1 *)(piVar8[2] + 0x14) = 1;
              FUN_00763f60(param_1);
              break;
            }
LAB_0084507a:
            *(undefined1 *)(piVar8 + 5) = 0;
          }
        }
        else {
          if ((char)piVar8[5] == '\0') {
            *(undefined1 *)(piVar8 + 5) = 1;
            *(undefined1 *)(piVar7 + 5) = 0;
            FUN_0043e670(param_1);
            piVar8 = (int *)*piVar7;
          }
          if (*(char *)((int)piVar8 + 0x15) == '\0') {
            if ((*(char *)(piVar8[2] + 0x14) == '\x01') && (*(char *)(*piVar8 + 0x14) == '\x01'))
            goto LAB_0084507a;
            if (*(char *)(*piVar8 + 0x14) == '\x01') {
              *(undefined1 *)(piVar8[2] + 0x14) = 1;
              *(undefined1 *)(piVar8 + 5) = 0;
              FUN_00763f60(param_1);
              piVar8 = (int *)*piVar7;
            }
            *(char *)(piVar8 + 5) = (char)piVar7[5];
            *(undefined1 *)(piVar7 + 5) = 1;
            *(undefined1 *)(*piVar8 + 0x14) = 1;
            FUN_0043e670(param_1);
            break;
          }
        }
        piVar8 = (int *)piVar7[1];
        piVar9 = piVar7;
      } while (piVar7 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar9 + 5) = 1;
  }
  puVar4 = (undefined4 *)param_3[4];
  if (puVar4 != (undefined4 *)0x0) {
    piVar9 = puVar4 + 1;
    *piVar9 = *piVar9 + -1;
    if (*piVar9 == 0) {
      (**(code **)*puVar4)(1);
    }
  }
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

