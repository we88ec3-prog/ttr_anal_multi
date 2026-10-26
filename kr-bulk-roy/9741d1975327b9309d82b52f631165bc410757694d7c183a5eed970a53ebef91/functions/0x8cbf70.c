
undefined4 FUN_008cbf70(undefined4 *param_1)

{
  int *piVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  undefined4 *puVar6;
  short sVar7;
  uint uVar8;
  ushort uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint local_28;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint *local_c;
  uint *local_8;
  
  FUN_005719c0();
  FUN_005719c0();
  FUN_005719c0();
  local_1c = (int)param_1[0x13] >> ((byte)*param_1 & 0x1f) & 0xffff;
  local_18 = (int)param_1[0x14] >> ((byte)*param_1 & 0x1f) & 0xffff;
  puVar6 = (undefined4 *)param_1[0x17];
  while (puVar6 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)puVar6[1];
    uVar9 = (*(short *)(puVar6 + 4) + *(short *)(puVar6 + 5)) - 1;
    bVar5 = (short)*(ushort *)(puVar6 + 5) < (short)local_18;
    if (bVar5) {
      local_18 = (uint)*(ushort *)(puVar6 + 5);
    }
    bVar5 = (short)local_1c < (short)uVar9;
    if (bVar5) {
      local_1c = (uint)uVar9;
    }
    *puVar6 = 0;
    FUN_008cb980();
    puVar6 = puVar3;
  }
  if (param_1[0xc] == 0) {
    param_1[0xb] = 0x14;
    return 1;
  }
  (*(code *)param_1[0x29])(param_1,&local_18,&local_1c);
  for (iVar4 = local_10; iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
    *(uint *)(iVar4 + 0x18) = (uint)(ushort)(*(short *)(iVar4 + 0x14) - (short)local_18);
  }
  iVar4 = param_1[0xc];
  local_28 = 0;
  if ((0 < iVar4) && (*(int *)(param_1[8] + iVar4 * -4) == (int)(short)local_18)) {
    param_1[0xc] = iVar4 + -1;
  }
  iVar4 = param_1[0xc];
  uVar13 = local_18 & 0xffff;
  iVar12 = local_10;
  while (local_14 = uVar13, 0 < iVar4) {
    local_10 = iVar12;
    if (iVar12 != 0) {
      do {
        piVar1 = (int *)(iVar12 + 0x18);
        *piVar1 = *piVar1 - (int)(short)local_28;
        iVar12 = *(int *)(iVar12 + 4);
        if (*piVar1 == 0) {
          FUN_008cb9b0();
          FUN_008cb980();
        }
      } while (iVar12 != 0);
    }
    FUN_008cb9d0();
    FUN_008cb9d0();
    uVar9 = *(ushort *)(param_1[8] + param_1[0xc] * -4);
    param_1[0xc] = param_1[0xc] + -1;
    local_28 = uVar9 - local_14 & 0xffff;
    puVar15 = local_8;
    if ((short)local_14 < (short)uVar9) {
      while( true ) {
        sVar7 = 0;
        puVar10 = local_c;
        puVar15 = local_8;
        if (local_8 != (uint *)0x0) {
          do {
            uVar13 = *puVar15;
            uVar11 = *puVar10;
            uVar8 = uVar13;
            if ((int)uVar11 < (int)uVar13) {
              uVar8 = uVar11;
              uVar11 = uVar13;
            }
            iVar4 = param_1[1];
            uVar13 = -iVar4 & uVar8;
            uVar14 = iVar4 + -1 + uVar11 & -iVar4;
            if ((((iVar4 < (int)(uVar11 - uVar8)) || (uVar13 == uVar8)) || (uVar14 == uVar11)) ||
               (((int)uVar13 <= (int)uVar14 && (uVar14 != iVar4 + uVar13)))) {
              (*(code *)param_1[0x2a])(param_1,local_14,uVar8,uVar11,puVar15,puVar10);
            }
            else if (((byte)puVar15[3] & 7) != 2) {
              *puVar15 = uVar8;
              *puVar10 = uVar11;
              sVar7 = sVar7 + 1;
              puVar15[6] = 1;
            }
            puVar15 = (uint *)puVar15[1];
            puVar10 = (uint *)puVar10[1];
          } while (puVar15 != (uint *)0x0);
          puVar15 = local_8;
          puVar10 = local_c;
          if (0 < sVar7) {
            do {
              if (puVar15[6] != 0) {
                puVar15[6] = 0;
                (*(code *)param_1[0x2b])(param_1,local_14,*puVar15,*puVar10,puVar15,puVar10);
              }
              puVar2 = puVar15 + 1;
              puVar15 = (uint *)*puVar2;
              puVar10 = (uint *)puVar10[1];
            } while ((uint *)*puVar2 != (uint *)0x0);
          }
        }
        (*(code *)param_1[0x2c])(param_1);
        local_14 = local_14 + 1;
        puVar15 = local_8;
        if ((short)uVar9 <= (short)local_14) break;
        FUN_008cb9d0();
        FUN_008cb9d0();
      }
    }
    while (puVar10 = local_c, puVar15 != (uint *)0x0) {
      puVar10 = puVar15 + 4;
      puVar15 = (uint *)puVar15[1];
      if (*puVar10 == 0) {
        FUN_008cb9b0();
      }
    }
    while (puVar10 != (uint *)0x0) {
      puVar15 = puVar10 + 4;
      puVar10 = (uint *)puVar10[1];
      if (*puVar15 == 0) {
        FUN_008cb9b0();
      }
    }
    uVar13 = local_14;
    iVar12 = local_10;
    iVar4 = param_1[0xc];
  }
  if ((short)uVar13 <= (short)local_1c) {
    do {
      (*(code *)param_1[0x2c])(param_1);
      uVar13 = uVar13 + 1;
    } while ((short)uVar13 <= (short)local_1c);
  }
  return 0;
}

