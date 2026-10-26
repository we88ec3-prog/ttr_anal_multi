
void FUN_005537f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  int local_8;
  
  iVar7 = 0;
  do {
    local_10 = 0;
    local_c = 0;
    if ((0 < iVar7) && (*(int *)(param_1 + 0x40 + iVar7 * 4) != 0)) {
      local_10 = 1;
    }
    piVar6 = *(int **)(iVar7 * 0x10 + 4 + param_1);
    piVar8 = (int *)*piVar6;
    local_8 = iVar7 * 0x10 + param_1;
    if (piVar8 != piVar6) {
      do {
        piVar6 = (int *)piVar8[4];
        if (piVar8 != (int *)**(int **)(local_8 + 4)) {
          if (*(int *)(((int *)**(int **)(local_8 + 4))[4] + 0x3c) == 0) {
            local_c = 1;
          }
          if (piVar6[0xf] == 0) {
            local_c = 1;
          }
        }
        if ((local_10 != 0) || (local_c != 0)) {
          piVar6[9] = piVar6[9] + 1;
        }
        (**(code **)(*piVar6 + 0x14))();
        iVar3 = (**(code **)(*piVar6 + 0x24))();
        if (iVar3 == 0) {
          (**(code **)(*piVar6 + 8))();
          (**(code **)*piVar6)(1);
          puVar4 = (undefined4 *)FUN_007b6890(local_8,local_14,piVar8);
          piVar8 = (int *)*puVar4;
        }
        else if (*(char *)((int)piVar8 + 0x15) == '\0') {
          piVar6 = (int *)piVar8[2];
          if (*(char *)((int)piVar6 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar6 + 0x15);
            piVar8 = piVar6;
            piVar6 = (int *)*piVar6;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar6 + 0x15);
              piVar8 = piVar6;
              piVar6 = (int *)*piVar6;
            }
          }
          else {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar2 = (int *)piVar8[1];
            piVar6 = piVar8;
            while ((piVar8 = piVar2, cVar1 == '\0' && (piVar6 == (int *)piVar8[2]))) {
              cVar1 = *(char *)(piVar8[1] + 0x15);
              piVar2 = (int *)piVar8[1];
              piVar6 = piVar8;
            }
          }
        }
      } while (piVar8 != *(int **)(local_8 + 4));
    }
    if (iVar7 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(param_1 + 0x40 + iVar7 * 4);
    }
    *(undefined4 *)(param_1 + 0x44 + iVar7 * 4) = uVar5;
    piVar6 = (int *)**(int **)(local_8 + 4);
    if (piVar6 != *(int **)(local_8 + 4)) {
      do {
        if (*(int *)(piVar6[4] + 0x34) < 4) {
          piVar8 = (int *)(param_1 + 0x44 + iVar7 * 4);
          *piVar8 = *piVar8 + 1;
        }
        if (*(char *)((int)piVar6 + 0x15) == '\0') {
          piVar8 = (int *)piVar6[2];
          if (*(char *)((int)piVar8 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar8 + 0x15);
            piVar6 = piVar8;
            piVar8 = (int *)*piVar8;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar8 + 0x15);
              piVar6 = piVar8;
              piVar8 = (int *)*piVar8;
            }
          }
          else {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar2 = (int *)piVar6[1];
            piVar8 = piVar6;
            while ((piVar6 = piVar2, cVar1 == '\0' && (piVar8 == (int *)piVar6[2]))) {
              cVar1 = *(char *)(piVar6[1] + 0x15);
              piVar2 = (int *)piVar6[1];
              piVar8 = piVar6;
            }
          }
        }
      } while (piVar6 != *(int **)(local_8 + 4));
    }
    piVar6 = (int *)(param_1 + 0x44 + iVar7 * 4);
    *piVar6 = *piVar6 + *(int *)(local_8 + 8);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  return;
}

