
void FUN_00825fa0(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  ushort uVar6;
  uint *puVar7;
  int *piVar8;
  undefined4 uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 **ppuVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint local_2c;
  uint *local_28;
  undefined4 *local_24;
  undefined4 *local_20 [2];
  ushort local_18;
  uint *local_14;
  
  local_2c = 0;
  if (*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 2 != 0) {
    do {
      iVar3 = *(int *)(*(int *)(param_2 + 0x14) + local_2c * 4);
      if (*(short *)(iVar3 + 8) != 0) {
        local_28 = (uint *)(uint)*(ushort *)(iVar3 + 4);
        FUN_00826280(&local_28);
        if ((local_24 == *(undefined4 **)(param_1 + 4)) ||
           (puVar10 = (uint *)local_24[4], (uint *)local_24[4] == (uint *)0x0)) {
          puVar7 = (uint *)FUN_00891268(8);
          if (puVar7 == (uint *)0x0) {
            puVar7 = (uint *)0x0;
          }
          else {
            *puVar7 = 0;
            puVar7[1] = 0x10000;
          }
          *puVar7 = (uint)*(ushort *)(iVar3 + 4);
          uVar2 = *(ushort *)(iVar3 + 4);
          local_20[0] = (undefined4 *)(uint)uVar2;
          local_28 = puVar7;
          piVar8 = (int *)FUN_00826280(local_20);
          puVar10 = local_28;
          if (*piVar8 == *(int *)(param_1 + 4)) {
            local_18 = uVar2;
            local_14 = puVar7;
            uVar9 = FUN_004ca670();
            FUN_008262f0(param_1,uVar9);
            puVar10 = local_28;
          }
        }
        *(short *)(puVar10 + 1) = (short)puVar10[1] + *(short *)(iVar3 + 8);
      }
      local_2c = local_2c + 1;
    } while (local_2c < (uint)(*(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 2));
  }
  uVar16 = 0;
  if (*(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 2 != 0) {
    do {
      iVar3 = *(int *)(*(int *)(param_2 + 0x24) + uVar16 * 4);
      puVar12 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
      uVar2 = *(ushort *)(iVar3 + 4);
      cVar1 = *(char *)((int)puVar12 + 0x15);
      local_20[0] = *(undefined4 **)(param_1 + 4);
      while (cVar1 == '\0') {
        if (*(ushort *)(puVar12 + 3) < uVar2) {
          puVar11 = (undefined4 *)puVar12[2];
          puVar12 = local_20[0];
        }
        else {
          puVar11 = (undefined4 *)*puVar12;
        }
        local_20[0] = puVar12;
        puVar12 = puVar11;
        cVar1 = *(char *)((int)puVar11 + 0x15);
      }
      local_24 = *(undefined4 **)(param_1 + 4);
      if ((local_20[0] == local_24) || (uVar2 < *(ushort *)(local_20[0] + 3))) {
        ppuVar13 = &local_24;
      }
      else {
        ppuVar13 = local_20;
      }
      if ((*ppuVar13 != local_24) && (iVar4 = (*ppuVar13)[4], iVar4 != 0)) {
        uVar2 = *(ushort *)(iVar3 + 8);
        uVar6 = *(ushort *)(iVar4 + 6);
        if (*(ushort *)(iVar4 + 6) <= uVar2) {
          uVar6 = uVar2;
        }
        *(ushort *)(iVar4 + 6) = uVar6;
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < (uint)(*(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 2));
  }
  local_28 = (uint *)0x0;
  if (*(int *)(param_2 + 0x38) - *(int *)(param_2 + 0x34) >> 2 != 0) {
    local_20[0] = (undefined4 *)(param_1 + 0x10);
    do {
      uVar16 = *(uint *)(*(int *)(param_2 + 0x34) + (int)local_28 * 4);
      local_24 = (undefined4 *)(uint)*(ushort *)(uVar16 + 4);
      local_2c = uVar16;
      puVar7 = (uint *)FUN_00684080(local_20[0]);
      puVar10 = (uint *)puVar7[1];
      if (&local_2c < puVar10) {
        puVar5 = (uint *)*puVar7;
        if (&local_2c < puVar5) goto LAB_008261f3;
        if (puVar10 == (uint *)puVar7[2]) {
          uVar16 = (int)puVar10 - (int)puVar5 >> 2;
          if (0x3ffffffe < uVar16) goto LAB_00826266;
          uVar16 = uVar16 + 1;
          uVar14 = (int)puVar7[2] - (int)puVar5 >> 2;
          if (uVar14 < uVar16) {
            if (0x3fffffff - (uVar14 >> 1) < uVar14) {
              uVar14 = 0;
            }
            else {
              uVar14 = uVar14 + (uVar14 >> 1);
            }
            if (uVar14 < uVar16) {
              uVar14 = uVar16;
            }
            FUN_00797980(uVar14);
          }
        }
        if ((undefined4 *)puVar7[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar7[1] =
               *(undefined4 *)(*puVar7 + ((int)&local_2c - (int)puVar5 >> 2) * 4);
        }
      }
      else {
LAB_008261f3:
        if (puVar10 == (uint *)puVar7[2]) {
          uVar14 = (int)((int)puVar10 - *puVar7) >> 2;
          if (0x3ffffffe < uVar14) {
LAB_00826266:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar14 = uVar14 + 1;
          uVar15 = (int)((int)puVar7[2] - *puVar7) >> 2;
          if (uVar15 < uVar14) {
            if (0x3fffffff - (uVar15 >> 1) < uVar15) {
              uVar15 = 0;
            }
            else {
              uVar15 = uVar15 + (uVar15 >> 1);
            }
            if (uVar15 < uVar14) {
              uVar15 = uVar14;
            }
            FUN_00797980(uVar15);
          }
        }
        if ((uint *)puVar7[1] != (uint *)0x0) {
          *(uint *)puVar7[1] = uVar16;
        }
      }
      puVar7[1] = puVar7[1] + 4;
      local_28 = (uint *)((int)local_28 + 1);
    } while (local_28 < (uint *)(*(int *)(param_2 + 0x38) - *(int *)(param_2 + 0x34) >> 2));
  }
  return;
}

