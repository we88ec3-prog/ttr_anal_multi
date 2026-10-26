
/* WARNING: Removing unreachable block (ram,0x007f1ed8) */

void FUN_007f1eb0(int param_1)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  int local_28 [2];
  int local_20 [2];
  int local_18 [5];
  
  puVar1 = (uint *)(param_1 + 0x8c);
  if (*(int *)(param_1 + 0x8c) != *(int *)(param_1 + 0x90)) {
    *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x8c);
  }
  uVar8 = 0;
  local_18[2] = 0;
  iVar4 = (**(code **)(**(int **)(param_1 + 0x88) + 0x34))();
  if (iVar4 != 0) {
    do {
      iVar4 = (**(code **)(**(int **)(param_1 + 0x88) + 0x30))(uVar8);
      pcVar6 = (char *)(iVar4 + 8);
      if (0xf < *(uint *)(iVar4 + 0x1c)) {
        pcVar6 = *(char **)pcVar6;
      }
      local_18[3] = iVar4;
      iVar5 = _strncmp(pcVar6,"BB_",3);
      if (iVar5 == 0) {
        piVar2 = *(int **)(param_1 + 0x90);
        local_18[0] = iVar5;
        local_18[1] = iVar4;
        if (local_18 < piVar2) {
          if (local_18 < (int *)*puVar1) goto LAB_007f1f85;
          iVar5 = (int)local_18 - (int)*puVar1 >> 3;
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          puVar3 = *(undefined4 **)(param_1 + 0x90);
          if (puVar3 != (undefined4 *)0x0) {
            uVar8 = *puVar1;
            *puVar3 = *(undefined4 *)(uVar8 + iVar5 * 8);
            puVar3[1] = *(undefined4 *)(uVar8 + 4 + iVar5 * 8);
          }
        }
        else {
LAB_007f1f85:
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          piVar2 = *(int **)(param_1 + 0x90);
          if (piVar2 != (int *)0x0) {
            *piVar2 = local_18[0];
            piVar2[1] = iVar4;
          }
        }
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 8;
      }
      pcVar6 = (char *)(iVar4 + 8);
      if (0xf < *(uint *)(iVar4 + 0x1c)) {
        pcVar6 = *(char **)pcVar6;
      }
      iVar5 = _strncmp(pcVar6,"BY_",3);
      if (iVar5 == 0) {
        piVar2 = *(int **)(param_1 + 0x90);
        local_20[0] = 1;
        local_20[1] = iVar4;
        if (local_20 < piVar2) {
          if (local_20 < (int *)*puVar1) goto LAB_007f200d;
          iVar4 = (int)local_20 - (int)*puVar1 >> 3;
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          puVar3 = *(undefined4 **)(param_1 + 0x90);
          if (puVar3 != (undefined4 *)0x0) {
            uVar8 = *puVar1;
            *puVar3 = *(undefined4 *)(uVar8 + iVar4 * 8);
            puVar3[1] = *(undefined4 *)(uVar8 + 4 + iVar4 * 8);
          }
        }
        else {
LAB_007f200d:
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          puVar3 = *(undefined4 **)(param_1 + 0x90);
          if (puVar3 != (undefined4 *)0x0) {
            *puVar3 = 1;
            puVar3[1] = iVar4;
          }
        }
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 8;
        iVar4 = local_18[3];
      }
      pcVar6 = (char *)(iVar4 + 8);
      if (0xf < *(uint *)(iVar4 + 0x1c)) {
        pcVar6 = *(char **)pcVar6;
      }
      iVar5 = _strncmp(pcVar6,"BZ_",3);
      if (iVar5 == 0) {
        piVar2 = *(int **)(param_1 + 0x90);
        local_28[0] = 2;
        local_28[1] = iVar4;
        if ((local_28 < piVar2) && ((int *)*puVar1 <= local_28)) {
          iVar4 = (int)local_28 - (int)*puVar1 >> 3;
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          puVar3 = *(undefined4 **)(param_1 + 0x90);
          if (puVar3 != (undefined4 *)0x0) {
            uVar8 = *puVar1;
            *puVar3 = *(undefined4 *)(uVar8 + iVar4 * 8);
            puVar3[1] = *(undefined4 *)(uVar8 + 4 + iVar4 * 8);
          }
        }
        else {
          if (piVar2 == *(int **)(param_1 + 0x94)) {
            FUN_007cddf0();
          }
          puVar3 = *(undefined4 **)(param_1 + 0x90);
          if (puVar3 != (undefined4 *)0x0) {
            *puVar3 = 2;
            puVar3[1] = iVar4;
          }
        }
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 8;
      }
      uVar8 = local_18[2] + 1;
      local_18[2] = uVar8;
      uVar7 = (**(code **)(**(int **)(param_1 + 0x88) + 0x34))();
    } while (uVar8 < uVar7);
  }
  return;
}

