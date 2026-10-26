
void FUN_008e2d30(void)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  uint extraout_ECX;
  uint extraout_ECX_00;
  int iVar8;
  int extraout_ECX_01;
  uint uVar9;
  int extraout_ECX_02;
  int extraout_EDX;
  uint *puVar10;
  int unaff_EDI;
  uint local_3c;
  int local_38;
  uint *local_34;
  uint local_30;
  uint *local_2c;
  int local_28;
  undefined4 *local_24;
  int *local_20;
  int *local_1c;
  uint *local_18;
  uint *local_14;
  int *local_10;
  uint local_c;
  char local_5;
  
  FUN_008e0730();
  local_30 = *(uint *)(unaff_EDI + 0x14);
  local_c = 0;
  if (local_30 != 0) {
    local_24 = (undefined4 *)(unaff_EDI + 0x18);
    local_1c = (int *)(unaff_EDI + 0x24);
    puVar4 = (uint *)(unaff_EDI + 0x28);
    local_20 = (int *)(unaff_EDI + 0x10);
    local_28 = unaff_EDI + 0x1c;
    local_10 = (int *)(unaff_EDI + 0x14);
    do {
      local_14 = puVar4;
      local_5 = FUN_008e0ec0();
      uVar6 = extraout_ECX + 1;
      if (local_5 == '\0') {
        uVar6 = extraout_ECX;
      }
      cVar2 = FUN_008e0f00();
      puVar1 = local_14;
      uVar9 = extraout_ECX_00;
      if (cVar2 == '\0') {
        iVar3 = *puVar4 - (*puVar4 & 0xffff0000);
        local_34 = (uint *)(unaff_EDI + (uVar6 * 5 + 10) * 4);
        uVar9 = *local_34;
        iVar8 = uVar9 - (uVar9 & 0xffff0000);
        local_2c = (uint *)-iVar3;
        puVar10 = (uint *)-iVar8;
        puVar4 = (uint *)0x0;
        if (iVar3 != 0) {
          puVar4 = local_2c + 0x4000;
        }
        local_18 = (uint *)0x0;
        if (iVar8 != 0) {
          local_18 = puVar10 + 0x4000;
        }
        if ((int)puVar4 < (int)local_18) {
          local_18 = puVar4;
        }
        puVar4 = local_2c;
        if ((int)local_2c <= (int)puVar10) {
          puVar4 = puVar10;
        }
        if ((uVar6 < local_30 - 1) &&
           (*(int *)(unaff_EDI + (uVar6 * 5 + 0xf) * 4) < (int)(uVar9 + 0x8000 + (int)local_18))) {
          if ((local_c == 0) || (*local_10 <= (int)((*local_14 - 0x8000) + (int)puVar4))) {
            local_14 = puVar4;
            if (-(int)puVar4 <= (int)local_18) goto LAB_008e2e70;
          }
          else {
            local_14 = (uint *)0x0;
          }
          cVar2 = FUN_008e0f00();
          if (cVar2 == '\0') {
            local_38 = extraout_ECX_01 - (int)local_14;
            local_3c = uVar6;
            FUN_008e2300(&local_3c);
          }
        }
        else if (((local_c == 0) ||
                 (uVar9 = *local_14, local_14 = local_18,
                 *local_10 <= (int)((uVar9 - 0x8000) + (int)puVar4))) &&
                (local_14 = local_18, -(int)puVar4 < (int)local_18)) {
          local_14 = puVar4;
        }
LAB_008e2e70:
        *puVar1 = *puVar1 + (int)local_14;
        uVar9 = local_c;
        puVar4 = puVar1;
        if (local_5 != '\0') {
          *local_34 = *local_34 + (int)local_14;
        }
      }
      if (uVar9 != 0) {
        if (*local_1c != *local_20) {
          uVar5 = FUN_008b7f40(*puVar4 - *local_10,*local_1c - *local_20);
          *local_24 = uVar5;
          uVar9 = local_c;
        }
      }
      if (local_5 != '\0') {
        local_2c = (uint *)(unaff_EDI + uVar6 * 0x14);
        if (local_2c[9] != local_2c[4]) {
          uVar6 = FUN_008b7f40(*(int *)(unaff_EDI + (uVar6 * 5 + 10) * 4) - local_2c[5],
                               local_2c[9] - local_2c[4]);
          local_2c[6] = uVar6;
          uVar9 = local_c;
        }
        local_1c = local_1c + 5;
        local_20 = local_20 + 5;
        local_10 = local_10 + 5;
        uVar9 = uVar9 + 1;
        puVar4 = puVar4 + 5;
        local_28 = local_28 + 0x14;
        local_24 = local_24 + 5;
      }
      local_1c = local_1c + 5;
      local_20 = local_20 + 5;
      local_10 = local_10 + 5;
      local_24 = local_24 + 5;
      puVar4 = puVar4 + 5;
      local_28 = local_28 + 0x14;
      local_30 = *(uint *)(unaff_EDI + 0x14);
      local_c = uVar9 + 1;
      local_14 = puVar4;
    } while (local_c < local_30);
  }
  for (local_c = FUN_008e0740(); local_c != 0; local_c = local_c + -1) {
    piVar7 = (int *)FUN_008e22e0();
    iVar3 = *piVar7 * 5 + 10;
    local_34 = (uint *)(*(int *)(unaff_EDI + iVar3 * 4) + piVar7[1]);
    if ((int)(local_34 + 0x2000) <= *(int *)(unaff_EDI + (*piVar7 * 5 + 0xf) * 4)) {
      *(uint **)(unaff_EDI + iVar3 * 4) = local_34;
      cVar2 = FUN_008e0ec0();
      if (cVar2 != '\0') {
        *(int *)(extraout_EDX + 0x14) =
             *(int *)(extraout_EDX + 0x14) + *(int *)(extraout_ECX_02 + 4);
      }
    }
  }
  return;
}

