
undefined4 FUN_008c63e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 *puVar15;
  int iVar16;
  uint *local_18;
  int local_14;
  
  local_14 = *(int *)(param_1 + 0x18);
  iVar14 = *(int *)(param_1 + 0x10);
  iVar11 = FUN_008c5c80();
  if (iVar11 == 0) {
    local_18 = *(uint **)(param_1 + 0x20);
    if (local_14 != 0) {
      puVar12 = (undefined1 *)(iVar14 + 9);
      iVar11 = iVar14 + 8;
      iVar16 = iVar14 + 7;
      puVar15 = (undefined1 *)(iVar14 + 6);
      do {
        uVar4 = *(undefined1 *)(iVar16 + 3);
        uVar5 = *(undefined1 *)(iVar11 + 3);
        puVar13 = puVar12 + 7;
        uVar6 = puVar12[3];
        puVar1 = puVar15 + 7;
        puVar2 = (undefined1 *)(iVar16 + 7);
        puVar3 = (undefined1 *)(iVar11 + 7);
        puVar12 = puVar12 + 0xb;
        puVar15 = puVar15 + 0xb;
        uVar7 = *puVar15;
        uVar8 = *(undefined1 *)(iVar16 + 0xb);
        iVar16 = iVar16 + 0xb;
        uVar9 = *(undefined1 *)(iVar11 + 0xb);
        iVar11 = iVar11 + 0xb;
        uVar10 = *puVar12;
        if (((CONCAT31(CONCAT21(CONCAT11(*puVar1,*puVar2),*puVar3),*puVar13) != 0) &&
            (iVar14 = FUN_008c6070(param_3), iVar14 != 0)) ||
           ((CONCAT31(CONCAT21(CONCAT11(uVar7,uVar8),uVar9),uVar10) != 0 &&
            (iVar14 = FUN_008c60f0(param_3), iVar14 != 0)))) {
          *local_18 = (uint)CONCAT21(CONCAT11(uVar4,uVar5),uVar6);
          local_18 = local_18 + 1;
        }
        local_14 = local_14 + -1;
      } while (local_14 != 0);
    }
    *local_18 = 0;
    return *(undefined4 *)(param_1 + 0x20);
  }
  return 0;
}

