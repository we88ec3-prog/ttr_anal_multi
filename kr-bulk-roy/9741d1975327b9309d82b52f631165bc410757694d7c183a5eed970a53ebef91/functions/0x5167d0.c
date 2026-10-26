
/* WARNING: Removing unreachable block (ram,0x00516899) */
/* WARNING: Removing unreachable block (ram,0x005168a9) */
/* WARNING: Removing unreachable block (ram,0x005168b2) */
/* WARNING: Removing unreachable block (ram,0x005168b5) */
/* WARNING: Removing unreachable block (ram,0x005168a5) */
/* WARNING: Removing unreachable block (ram,0x005168c3) */
/* WARNING: Removing unreachable block (ram,0x005168d3) */
/* WARNING: Removing unreachable block (ram,0x005168de) */
/* WARNING: Removing unreachable block (ram,0x005168da) */
/* WARNING: Removing unreachable block (ram,0x005168ce) */
/* WARNING: Removing unreachable block (ram,0x005168e1) */

void FUN_005167d0(int param_1,undefined4 *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  
  if (*(char *)((int)param_3 + 0x21) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0085e240();
  piVar8 = (int *)*param_3;
  if (*(char *)((int)piVar8 + 0x21) == '\0') {
    if (*(char *)(param_3[2] + 0x21) == '\0') {
      piVar8 = (int *)param_3[2];
    }
  }
  else {
    piVar8 = (int *)param_3[2];
  }
  piVar7 = (int *)param_3[1];
  if (*(char *)((int)piVar8 + 0x21) == '\0') {
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
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      cVar1 = *(char *)(*piVar8 + 0x21);
      piVar2 = (int *)*piVar8;
      piVar6 = piVar8;
      while (piVar4 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar4;
        cVar1 = *(char *)((int)piVar2 + 0x21);
        piVar6 = piVar4;
      }
    }
    **(undefined4 **)(param_1 + 4) = piVar6;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (*(int **)(iVar3 + 8) == param_3) {
    if (*(char *)((int)piVar8 + 0x21) == '\0') {
      uVar5 = FUN_00852270();
      *(undefined4 *)(iVar3 + 8) = uVar5;
    }
    else {
      *(int **)(iVar3 + 8) = piVar7;
    }
  }
  if ((char)param_3[8] == '\x01') {
    if (piVar8 != *(int **)(*(int *)(param_1 + 4) + 4)) {
      do {
        piVar6 = piVar7;
        if ((char)piVar8[8] != '\x01') break;
        piVar7 = (int *)*piVar6;
        if (piVar8 == piVar7) {
          piVar7 = (int *)piVar6[2];
          if ((char)piVar7[8] == '\0') {
            *(undefined1 *)(piVar7 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00405150(param_1);
            piVar7 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            if ((*(char *)(*piVar7 + 0x20) != '\x01') || (*(char *)(piVar7[2] + 0x20) != '\x01')) {
              if (*(char *)(piVar7[2] + 0x20) == '\x01') {
                *(undefined1 *)(*piVar7 + 0x20) = 1;
                *(undefined1 *)(piVar7 + 8) = 0;
                FUN_00819bd0(param_1);
                piVar7 = (int *)piVar6[2];
              }
              *(char *)(piVar7 + 8) = (char)piVar6[8];
              *(undefined1 *)(piVar6 + 8) = 1;
              *(undefined1 *)(piVar7[2] + 0x20) = 1;
              FUN_00405150(param_1);
              break;
            }
LAB_005169b7:
            *(undefined1 *)(piVar7 + 8) = 0;
          }
        }
        else {
          if ((char)piVar7[8] == '\0') {
            *(undefined1 *)(piVar7 + 8) = 1;
            *(undefined1 *)(piVar6 + 8) = 0;
            FUN_00819bd0(param_1);
            piVar7 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar7 + 0x21) == '\0') {
            if ((*(char *)(piVar7[2] + 0x20) == '\x01') && (*(char *)(*piVar7 + 0x20) == '\x01'))
            goto LAB_005169b7;
            if (*(char *)(*piVar7 + 0x20) == '\x01') {
              *(undefined1 *)(piVar7[2] + 0x20) = 1;
              *(undefined1 *)(piVar7 + 8) = 0;
              FUN_00405150(param_1);
              piVar7 = (int *)*piVar6;
            }
            *(char *)(piVar7 + 8) = (char)piVar6[8];
            *(undefined1 *)(piVar6 + 8) = 1;
            *(undefined1 *)(*piVar7 + 0x20) = 1;
            FUN_00819bd0(param_1);
            break;
          }
        }
        piVar7 = (int *)piVar6[1];
        piVar8 = piVar6;
      } while (piVar6 != *(int **)(*(int *)(param_1 + 4) + 4));
    }
    *(undefined1 *)(piVar8 + 8) = 1;
  }
  piVar8 = (int *)param_3[4];
  if (piVar8 != (int *)0x0) {
    piVar7 = (int *)param_3[5];
    for (; piVar8 != piVar7; piVar8 = piVar8 + 4) {
      if (*piVar8 != 0) {
        FUN_0089120c(*piVar8);
      }
      *piVar8 = 0;
      piVar8[1] = 0;
      piVar8[2] = 0;
    }
    FUN_0089120c(param_3[4]);
  }
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  FUN_0089120c(param_3);
  if (*(int *)(param_1 + 8) != 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  *param_2 = param_3;
  return;
}

