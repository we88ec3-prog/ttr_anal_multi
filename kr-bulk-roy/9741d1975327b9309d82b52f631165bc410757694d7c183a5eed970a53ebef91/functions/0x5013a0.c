
undefined4 FUN_005013a0(int param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  ushort *puVar6;
  int iVar7;
  ushort uVar8;
  uint uVar9;
  ushort *puVar10;
  undefined4 *puVar11;
  undefined4 **ppuVar12;
  undefined2 extraout_var;
  undefined2 uVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint *puVar16;
  uint local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 *local_40;
  ushort *local_3c;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00944218;
  local_14 = ExceptionList;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_c = 0;
  uVar8 = FUN_00500fd0(param_1);
  iVar3 = *(int *)(param_1 + 0x5eac);
  piVar4 = *(int **)(iVar3 + 4);
  piVar5 = (int *)*piVar4;
  iVar7 = 0;
  do {
    if (piVar5 == piVar4) {
      local_2c = iVar7 - local_28 >> 1;
      local_50 = 0;
      if (local_2c != 0) {
        local_48 = *(undefined4 **)(iVar3 + 4);
        local_44 = (undefined4 *)local_48[1];
        local_34 = local_48;
        do {
          uVar9 = (uint)*(ushort *)(local_28 + local_50 * 2);
          cVar1 = *(char *)((int)local_44 + 0xb5);
          local_4c = local_48;
          puVar14 = local_44;
          while (cVar1 == '\0') {
            if ((int)puVar14[3] < (int)uVar9) {
              puVar15 = (undefined4 *)puVar14[2];
              puVar14 = local_4c;
            }
            else {
              puVar15 = (undefined4 *)*puVar14;
            }
            local_4c = puVar14;
            puVar14 = puVar15;
            cVar1 = *(char *)((int)puVar15 + 0xb5);
          }
          if ((local_4c == local_48) || ((int)uVar9 < (int)local_4c[3])) {
            local_40 = local_48;
            ppuVar12 = &local_40;
          }
          else {
            ppuVar12 = &local_4c;
          }
          puVar14 = *ppuVar12;
          local_38 = puVar14;
          if (puVar14 != local_48) {
            puVar16 = (uint *)puVar14[8];
            puVar15 = (undefined4 *)(puVar14[9] - (int)puVar16 >> 2);
            local_4c = (undefined4 *)0x0;
            if (puVar15 != (undefined4 *)0x0) {
              puVar6 = *(ushort **)(param_1 + 0x5eb4);
              local_3c = *(ushort **)(param_1 + 0x5eb0);
              do {
                if (local_3c == puVar6) {
LAB_0050154a:
                  if ((uVar8 == 0) || ((uint)uVar8 != *puVar16)) goto LAB_0050160d;
                }
                else {
                  puVar10 = local_3c;
                  do {
                    if ((uint)*puVar10 == *puVar16) break;
                    puVar10 = puVar10 + 1;
                  } while (puVar10 != puVar6);
                  if (puVar10 == puVar6) goto LAB_0050154a;
                }
                local_4c = (undefined4 *)((int)local_4c + 1);
                puVar16 = puVar16 + 1;
              } while (local_4c < puVar15);
            }
            if ((uint)uVar8 != puVar14[4]) {
              puVar15 = (undefined4 *)(*(undefined4 **)(param_1 + 0x5efc))[1];
              cVar1 = *(char *)((int)puVar15 + 0x2d);
              local_38 = *(undefined4 **)(param_1 + 0x5efc);
              while (cVar1 == '\0') {
                if (*(ushort *)(puVar15 + 3) < *(ushort *)(puVar14 + 4)) {
                  puVar11 = (undefined4 *)puVar15[2];
                  puVar15 = local_38;
                }
                else {
                  puVar11 = (undefined4 *)*puVar15;
                }
                local_38 = puVar15;
                puVar15 = puVar11;
                cVar1 = *(char *)((int)puVar11 + 0x2d);
              }
              if ((local_38 == *(undefined4 **)(param_1 + 0x5efc)) ||
                 (*(ushort *)(puVar14 + 4) < *(ushort *)(local_38 + 3))) {
                local_30 = *(undefined4 **)(param_1 + 0x5efc);
                ppuVar12 = &local_30;
              }
              else {
                ppuVar12 = &local_38;
              }
              if ((*ppuVar12 != *(undefined4 **)(param_1 + 0x5efc)) &&
                 (*ppuVar12 != (undefined4 *)0xfffffff0)) {
                uVar2 = *(undefined2 *)(puVar14 + 4);
                uVar13 = 0;
                if (local_28 != 0) {
                  FUN_0089120c(local_28);
                  uVar13 = extraout_var;
                }
                ExceptionList = local_14;
                return CONCAT22(uVar13,uVar2);
              }
            }
          }
LAB_0050160d:
          local_50 = local_50 + 1;
        } while (local_50 < local_2c);
      }
      if (local_28 != 0) {
        FUN_0089120c(local_28);
      }
      ExceptionList = local_14;
      return 0;
    }
    if ((piVar5[5] == 2) && (piVar5[7] < 0x78)) {
      puVar6 = *(ushort **)(param_1 + 0x5eb4);
      puVar10 = *(ushort **)(param_1 + 0x5eb0);
      if (puVar10 != puVar6) {
        do {
          if ((uint)*puVar10 == piVar5[4]) break;
          puVar10 = puVar10 + 1;
        } while (puVar10 != puVar6);
        if (puVar10 != puVar6) goto LAB_0050144d;
      }
      local_4c = (undefined4 *)(uint)*(ushort *)(piVar5 + 4);
      FUN_0044b4e0(uVar9);
    }
LAB_0050144d:
    FUN_00503da0();
    piVar4 = *(int **)(iVar3 + 4);
    iVar7 = local_24;
  } while( true );
}

