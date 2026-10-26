
undefined2 FUN_00500fd0(int param_1)

{
  char cVar1;
  ushort uVar2;
  ushort *puVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  ushort *puVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  uint **ppuVar14;
  int iVar15;
  int *piVar16;
  uint uVar17;
  uint local_50;
  uint *local_4c [4];
  uint *local_3c;
  ushort *local_38;
  uint *local_34;
  uint *local_30;
  uint local_2c;
  uint **local_28;
  uint **local_24;
  uint **local_20;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_00940186;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  iVar11 = 0;
  ppuVar14 = (uint **)0x0;
  local_28 = (uint **)0x0;
  local_24 = (uint **)0x0;
  local_20 = (uint **)0x0;
  local_c = 0;
  local_50 = 0;
  uVar17 = 1;
  iVar15 = 0x210;
  do {
    uVar12 = iVar11;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 1;
      FUN_004e1590(uVar6);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = (uint)local_c._1_3_ << 8;
      uVar12 = local_50;
    }
    iVar11 = uVar12;
    if ((((uVar17 < 10) && (iVar7 = DAT_00f94304 + iVar15, *(int *)(iVar7 + 0x5c) != 0)) &&
        (iVar7 != 0)) && (iVar11 = *(int *)(iVar7 + 8), local_50 = iVar11, iVar11 <= (int)uVar12)) {
      iVar11 = uVar12;
      local_50 = uVar12;
    }
    iVar15 = iVar15 + 0x210;
    uVar17 = uVar17 + 1;
  } while (iVar15 < 0x14a0);
  local_4c[1] = *(uint **)(param_1 + 0x5eac);
  piVar16 = *(int **)local_4c[1][1];
  if (piVar16 != (int *)local_4c[1][1]) {
    do {
      if (((piVar16[7] <= (int)local_50) && (piVar16[7] < 0x78)) &&
         ((piVar16[5] == 2 || ((piVar16[5] == 1 && (piVar16[6] == 1)))))) {
        puVar3 = *(ushort **)(param_1 + 0x5eb4);
        puVar9 = *(ushort **)(param_1 + 0x5eb0);
        if (puVar9 != puVar3) {
          do {
            if ((uint)*puVar9 == piVar16[4]) break;
            puVar9 = puVar9 + 1;
          } while (puVar9 != puVar3);
          if (puVar9 != puVar3) goto LAB_0050115d;
        }
        uVar2 = *(ushort *)(piVar16 + 4);
        local_4c[0] = (uint *)(uint)uVar2;
        if ((local_4c < ppuVar14) && (local_28 <= local_4c)) {
          iVar11 = (int)local_4c - (int)local_28;
          if (ppuVar14 == local_20) {
            FUN_0044b5b0();
            ppuVar14 = local_24;
          }
          if (ppuVar14 != (uint **)0x0) {
            *(ushort *)ppuVar14 = *(ushort *)((int)local_28 + (iVar11 >> 1) * 2);
          }
        }
        else {
          if (ppuVar14 == local_20) {
            FUN_0044b5b0();
            ppuVar14 = local_24;
          }
          if (ppuVar14 != (uint **)0x0) {
            *(ushort *)ppuVar14 = uVar2;
          }
        }
        ppuVar14 = (uint **)((int)ppuVar14 + 2);
        local_24 = ppuVar14;
      }
LAB_0050115d:
      if (*(char *)((int)piVar16 + 0xb5) == '\0') {
        piVar4 = (int *)piVar16[2];
        if (*(char *)((int)piVar4 + 0xb5) == '\0') {
          cVar1 = *(char *)(*piVar4 + 0xb5);
          piVar16 = piVar4;
          piVar4 = (int *)*piVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar4 + 0xb5);
            piVar16 = piVar4;
            piVar4 = (int *)*piVar4;
          }
        }
        else {
          cVar1 = *(char *)(piVar16[1] + 0xb5);
          piVar5 = (int *)piVar16[1];
          piVar4 = piVar16;
          while ((piVar16 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar16[2]))) {
            cVar1 = *(char *)(piVar16[1] + 0xb5);
            piVar5 = (int *)piVar16[1];
            piVar4 = piVar16;
          }
        }
      }
    } while (piVar16 != (int *)local_4c[1][1]);
  }
  local_50 = 0;
  local_2c = (int)ppuVar14 - (int)local_28 >> 1;
  if (local_2c != 0) {
    local_4c[2] = (uint *)local_4c[1][1];
    local_4c[3] = (uint *)local_4c[2][1];
    local_4c[1] = local_4c[2];
    do {
      uVar17 = (uint)*(ushort *)((int)local_28 + local_50 * 2);
      cVar1 = *(char *)((int)local_4c[3] + 0xb5);
      local_4c[0] = local_4c[2];
      puVar13 = local_4c[3];
      while (cVar1 == '\0') {
        if ((int)puVar13[3] < (int)uVar17) {
          puVar8 = (uint *)puVar13[2];
          puVar13 = local_4c[0];
        }
        else {
          puVar8 = (uint *)*puVar13;
        }
        local_4c[0] = puVar13;
        puVar13 = puVar8;
        cVar1 = *(char *)((int)puVar8 + 0xb5);
      }
      if ((local_4c[0] == local_4c[2]) || ((int)uVar17 < (int)local_4c[0][3])) {
        local_3c = local_4c[2];
        ppuVar14 = &local_3c;
      }
      else {
        ppuVar14 = local_4c;
      }
      puVar13 = *ppuVar14;
      local_34 = puVar13;
      if (puVar13 != local_4c[2]) {
        uVar17 = (int)(puVar13[9] - (int)puVar13[8]) >> 2;
        uVar6 = 0;
        if (uVar17 != 0) {
          puVar3 = *(ushort **)(param_1 + 0x5eb4);
          local_38 = *(ushort **)(param_1 + 0x5eb0);
          local_4c[0] = (uint *)puVar13[8];
          do {
            if (local_38 == puVar3) goto LAB_00501357;
            puVar9 = local_38;
            do {
              if ((uint)*puVar9 == *local_4c[0]) break;
              puVar9 = puVar9 + 1;
            } while (puVar9 != puVar3);
            if (puVar9 == puVar3) goto LAB_00501357;
            local_4c[0] = local_4c[0] + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar17);
        }
        if (puVar13[4] != 0xea61) {
          puVar8 = (uint *)(*(uint **)(param_1 + 0x5efc))[1];
          cVar1 = *(char *)((int)puVar8 + 0x2d);
          local_34 = *(uint **)(param_1 + 0x5efc);
          while (cVar1 == '\0') {
            if ((ushort)puVar8[3] < (ushort)puVar13[4]) {
              puVar10 = (uint *)puVar8[2];
              puVar8 = local_34;
            }
            else {
              puVar10 = (uint *)*puVar8;
            }
            local_34 = puVar8;
            puVar8 = puVar10;
            cVar1 = *(char *)((int)puVar10 + 0x2d);
          }
          if ((local_34 == *(uint **)(param_1 + 0x5efc)) ||
             ((ushort)puVar13[4] < (ushort)local_34[3])) {
            local_30 = *(uint **)(param_1 + 0x5efc);
            ppuVar14 = &local_30;
          }
          else {
            ppuVar14 = &local_34;
          }
          if ((*ppuVar14 != *(uint **)(param_1 + 0x5efc)) && (*ppuVar14 != (uint *)0xfffffff0)) {
            uVar17 = puVar13[4];
            if (local_28 != (uint **)0x0) {
              FUN_0089120c(local_28);
            }
            ExceptionList = local_14;
            return (short)uVar17;
          }
        }
      }
LAB_00501357:
      local_50 = local_50 + 1;
    } while (local_50 < local_2c);
  }
  if (local_28 != (uint **)0x0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return 0;
}

