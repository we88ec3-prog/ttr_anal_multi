
/* WARNING: Removing unreachable block (ram,0x0056ee6b) */
/* WARNING: Removing unreachable block (ram,0x0056ee70) */

void FUN_0056ee50(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 **ppuVar9;
  undefined4 *puVar10;
  uint uVar11;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  int *local_8;
  
  if (*(int *)(param_1 + 0x74) != *(int *)(param_1 + 0x78)) {
    *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x74);
  }
  local_8 = (int *)**(int **)(param_1 + 0x54);
  if (local_8 != *(int **)(param_1 + 0x54)) {
    local_14 = param_1 + 0x44;
    do {
      piVar2 = (int *)local_8[2];
      local_c = (float)piVar2[0x11] + 0.333;
      local_24 = (undefined4 *)piVar2[2];
      puVar10 = (undefined4 *)(*(undefined4 **)(local_14 + 4))[1];
      cVar1 = *(char *)((int)puVar10 + 0x41);
      local_18 = 0;
      local_1c = *(undefined4 **)(local_14 + 4);
      while (cVar1 == '\0') {
        if ((int)puVar10[3] < *piVar2) {
          puVar5 = (undefined4 *)puVar10[2];
          puVar10 = local_1c;
        }
        else {
          puVar5 = (undefined4 *)*puVar10;
        }
        local_1c = puVar10;
        puVar10 = puVar5;
        cVar1 = *(char *)((int)puVar5 + 0x41);
      }
      if ((local_1c == *(undefined4 **)(local_14 + 4)) || (*piVar2 < (int)local_1c[3])) {
        local_20 = *(undefined4 **)(local_14 + 4);
        ppuVar9 = &local_20;
      }
      else {
        ppuVar9 = &local_1c;
      }
      puVar10 = *ppuVar9;
      if ((puVar10 == *(undefined4 **)(param_1 + 0x48)) ||
         (FUN_008438c0(&local_24), local_28 == puVar10[0xd])) {
        uVar11 = 0;
      }
      else {
        uVar11 = *(uint *)(local_28 + 0x10);
      }
      iVar6 = *(int *)(param_1 + 0x3c);
      if (uVar11 < (uint)((*(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0x10)) / 0x24)) {
        local_10 = (float)*(int *)(*(int *)(iVar6 + 0x10) + 0xc + uVar11 * 0x24);
      }
      else {
        local_10 = 0.0;
      }
      if (local_10 < local_c) {
        local_18 = 1;
        local_c = 0.0;
      }
      iVar6 = FUN_0056fd60(*piVar2);
      if (iVar6 != 0) {
        piVar7 = *(int **)(param_1 + 0x78);
        piVar4 = piVar2 + 4;
        if ((piVar4 < piVar7) && (*(int **)(param_1 + 0x74) <= piVar4)) {
          iVar6 = (int)piVar4 - (int)*(int **)(param_1 + 0x74) >> 3;
          if (piVar7 == *(int **)(param_1 + 0x7c)) {
            FUN_00539180();
          }
          piVar7 = *(int **)(param_1 + 0x78);
          if (piVar7 != (int *)0x0) {
            iVar3 = *(int *)(param_1 + 0x74);
            *piVar7 = *(int *)(iVar3 + iVar6 * 8);
            iVar6 = *(int *)(iVar3 + 4 + iVar6 * 8);
LAB_0056efe0:
            piVar7[1] = iVar6;
          }
        }
        else {
          if (piVar7 == *(int **)(param_1 + 0x7c)) {
            FUN_00539180();
          }
          piVar7 = *(int **)(param_1 + 0x78);
          if (piVar7 != (int *)0x0) {
            *piVar7 = *piVar4;
            iVar6 = piVar2[5];
            goto LAB_0056efe0;
          }
        }
        *(int *)(param_1 + 0x78) = *(int *)(param_1 + 0x78) + 8;
      }
      piVar2[0x11] = (int)local_c;
      puVar10 = (undefined4 *)(*(undefined4 **)(local_14 + 4))[1];
      puVar5 = (undefined4 *)*piVar2;
      cVar1 = *(char *)((int)puVar10 + 0x41);
      local_24 = *(undefined4 **)(local_14 + 4);
      while (cVar1 == '\0') {
        if ((int)puVar10[3] < (int)puVar5) {
          puVar8 = (undefined4 *)puVar10[2];
          puVar10 = local_24;
        }
        else {
          puVar8 = (undefined4 *)*puVar10;
        }
        local_24 = puVar10;
        puVar10 = puVar8;
        cVar1 = *(char *)((int)puVar8 + 0x41);
      }
      if ((local_24 == *(undefined4 **)(local_14 + 4)) || ((int)puVar5 < (int)local_24[3])) {
        local_2c = *(undefined4 **)(local_14 + 4);
        ppuVar9 = &local_2c;
      }
      else {
        ppuVar9 = &local_24;
      }
      if (((*ppuVar9 == *(undefined4 **)(param_1 + 0x48)) || ((*ppuVar9)[0xb] == 0)) ||
         ((local_24 = puVar5, FUN_005704f0(&local_24), local_30 != *(int *)(param_1 + 0x48) &&
          ((*(int *)(local_30 + 0x2c) == 2 && (local_18 != 0)))))) {
        piVar2 = local_8;
        iVar6 = local_8[2];
        if (iVar6 != 0) {
          if (7 < *(uint *)(iVar6 + 0x38)) {
            FUN_0089120c(*(undefined4 *)(iVar6 + 0x24));
          }
          *(undefined4 *)(iVar6 + 0x38) = 7;
          *(undefined4 *)(iVar6 + 0x34) = 0;
          *(undefined2 *)(iVar6 + 0x24) = 0;
          FUN_0089120c(iVar6);
        }
        piVar4 = (int *)*piVar2;
        if (piVar2 != *(int **)(param_1 + 0x54)) {
          *(int **)piVar2[1] = piVar4;
          *(int *)(*piVar2 + 4) = piVar2[1];
          FUN_0089120c(piVar2);
          *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
        }
      }
      else {
        piVar4 = (int *)*local_8;
      }
      local_8 = piVar4;
    } while (local_8 != *(int **)(param_1 + 0x54));
  }
  return;
}

