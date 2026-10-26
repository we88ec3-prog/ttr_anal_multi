
undefined4 FUN_008c3790(uint param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  int local_8;
  
  if (*(uint *)(param_2 + 4) < param_1 + 4) {
    FUN_008b8460(param_2,8);
  }
  uVar9 = (uint)CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  puVar2 = (undefined1 *)(uVar9 + param_1);
  if ((*(undefined1 **)(param_2 + 4) < puVar2) || (uVar9 < 0x206)) {
    FUN_008b8460(param_2,8);
  }
  puVar10 = (undefined1 *)(param_1 + 6);
  param_1 = 0;
  local_8 = 0x100;
  do {
    puVar11 = puVar10;
    uVar4 = *puVar11;
    bVar5 = puVar11[1];
    if ((1 < *(int *)(param_2 + 8)) && ((bVar5 & 7) != 0)) {
      FUN_008b8460(param_2,8);
    }
    uVar9 = (uint)(ushort)(CONCAT11(uVar4,bVar5) >> 3);
    if (param_1 < uVar9) {
      param_1 = uVar9;
    }
    local_8 = local_8 + -1;
    puVar10 = puVar11 + 2;
  } while (local_8 != 0);
  iVar3 = param_1 * 8;
  if (*(undefined1 **)(param_2 + 4) < puVar11 + iVar3 + 10) {
    FUN_008b8460(param_2,8);
  }
  param_1 = param_1 + 1;
  do {
    uVar4 = puVar10[4];
    uVar9 = (uint)CONCAT11(puVar10[2],puVar10[3]);
    uVar6 = puVar10[5];
    uVar7 = puVar10[7];
    puVar12 = puVar10 + 8;
    uVar8 = puVar10[6];
    if (uVar9 != 0) {
      if ((1 < *(int *)(param_2 + 8)) &&
         ((0xff < CONCAT11(*puVar10,puVar10[1]) || (0x100 < CONCAT11(*puVar10,puVar10[1]) + uVar9)))
         ) {
        FUN_008b8460(param_2,8);
      }
      if (CONCAT11(uVar8,uVar7) != 0) {
        if ((puVar12 + (CONCAT11(uVar8,uVar7) - 2) < puVar11 + iVar3 + 10) ||
           (puVar2 < puVar12 + (CONCAT11(uVar8,uVar7) - 2) + uVar9 * 2)) {
          FUN_008b8460(param_2,9);
        }
        if (0 < *(int *)(param_2 + 8)) {
          puVar10 = puVar12 + uVar9 * 2;
          while (puVar12 < puVar10) {
            uVar7 = *puVar12;
            puVar13 = puVar12 + 2;
            puVar1 = puVar12 + 1;
            puVar12 = puVar13;
            if ((CONCAT11(uVar7,*puVar1) != 0) &&
               (*(uint *)(param_2 + 0x50) <=
                (uint)(ushort)(CONCAT11(uVar7,*puVar1) + CONCAT11(uVar4,uVar6)))) {
              FUN_008b8460(param_2,0x10);
            }
          }
        }
      }
    }
    param_1 = param_1 + -1;
    puVar10 = puVar12;
  } while (param_1 != 0);
  return 0;
}

