
undefined4 FUN_008c5280(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uint uVar11;
  uint uVar12;
  undefined1 *puVar13;
  uint local_18;
  uint local_14;
  
  if (*(uint *)(param_2 + 4) < param_1 + 0x10U) {
    FUN_008b8460(param_2,8);
  }
  puVar8 = (undefined1 *)(param_1 + 0xd);
  puVar7 = (undefined1 *)(param_1 + 0xc);
  uVar6 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                            *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7));
  puVar9 = (undefined1 *)(param_1 + 0xe);
  puVar10 = (undefined1 *)(param_1 + 0xf);
  uVar11 = CONCAT31(CONCAT21(CONCAT11(*puVar7,*puVar8),*puVar9),*puVar10);
  if (((uint)(*(int *)(param_2 + 4) - param_1) < uVar6) || (uVar6 < uVar11 * 0xc + 0x10)) {
    FUN_008b8460(param_2,8);
  }
  local_18 = 0;
  local_14 = 0;
  if (uVar11 != 0) {
    do {
      puVar13 = puVar10 + 8;
      uVar6 = CONCAT31(CONCAT21(CONCAT11(puVar7[4],puVar8[4]),puVar9[4]),puVar10[4]);
      puVar1 = puVar9 + 8;
      puVar10 = puVar10 + 0xc;
      puVar9 = puVar9 + 0xc;
      uVar12 = CONCAT31(CONCAT21(CONCAT11(puVar7[8],puVar8[8]),*puVar1),*puVar13);
      uVar2 = puVar7[0xc];
      puVar7 = puVar7 + 0xc;
      uVar3 = puVar8[0xc];
      puVar8 = puVar8 + 0xc;
      uVar4 = *puVar9;
      uVar5 = *puVar10;
      if (uVar12 < uVar6) {
        FUN_008b8460(param_2,8);
      }
      if ((local_14 != 0) && (uVar6 <= local_18)) {
        FUN_008b8460(param_2,8);
      }
      if ((0 < *(int *)(param_2 + 8)) &&
         (*(uint *)(param_2 + 0x50) <=
          (CONCAT31(CONCAT21(CONCAT11(uVar2,uVar3),uVar4),uVar5) - uVar6) + uVar12)) {
        FUN_008b8460(param_2,0x10);
      }
      local_14 = local_14 + 1;
      local_18 = uVar12;
    } while (local_14 < uVar11);
  }
  return 0;
}

