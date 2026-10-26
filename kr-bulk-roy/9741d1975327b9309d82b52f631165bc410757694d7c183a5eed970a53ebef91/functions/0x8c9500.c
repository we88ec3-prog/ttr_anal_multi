
undefined4 FUN_008c9500(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  
  puVar5 = (undefined1 *)(*(int *)(param_1 + 0x1c) + *(int *)(param_1 + 0x24));
  iVar10 = *(int *)(param_1 + 0x20);
  puVar3 = *(undefined1 **)(param_1 + 0x28);
  puVar6 = puVar5;
  while( true ) {
    if (iVar10 == 0) {
      return 6;
    }
    uVar8 = (uint)CONCAT11(*puVar6,puVar6[1]);
    if ((uVar8 <= param_2) && (param_2 <= CONCAT11(puVar6[2],puVar6[3]))) break;
    puVar6 = puVar6 + 8;
    iVar10 = iVar10 + -1;
  }
  uVar9 = CONCAT31(CONCAT21(CONCAT11(puVar6[4],puVar6[5]),puVar6[6]),puVar6[7]);
  if ((uint)((int)puVar3 - (int)puVar5) < uVar9) {
    return 8;
  }
  puVar5 = puVar5 + uVar9;
  if (puVar3 < puVar5 + 8) {
    return 6;
  }
  uVar1 = puVar5[3];
  uVar2 = puVar5[2];
  switch(CONCAT11(*puVar5,puVar5[1])) {
  case 1:
    puVar5 = puVar5 + (param_2 - uVar8) * 4 + 8;
    if (puVar3 < puVar5 + 8) {
      return 6;
    }
    uVar8 = CONCAT31(CONCAT21(CONCAT11(*puVar5,puVar5[1]),puVar5[2]),puVar5[3]);
    uVar7 = CONCAT31(CONCAT21(CONCAT11(puVar5[4],puVar5[5]),puVar5[6]),puVar5[7]);
    if (uVar8 == uVar7) {
      return 6;
    }
    break;
  case 2:
    if (puVar3 < puVar5 + 0x14) {
      return 6;
    }
    iVar11 = CONCAT31(CONCAT21(CONCAT11(puVar5[8],puVar5[9]),puVar5[10]),puVar5[0xb]);
    iVar10 = FUN_008c8e10(param_1,1);
    if (iVar10 != 0) {
      return 6;
    }
    uVar8 = param_2 - uVar8;
    goto LAB_008c9846;
  case 3:
    puVar5 = puVar5 + (param_2 - uVar8) * 2 + 8;
    if (puVar3 < puVar5 + 4) {
      return 6;
    }
    uVar8 = (uint)CONCAT11(*puVar5,puVar5[1]);
    uVar7 = (uint)CONCAT11(puVar5[2],puVar5[3]);
    if (uVar8 == uVar7) {
      return 6;
    }
    break;
  case 4:
    puVar6 = puVar5 + 0xc;
    if (puVar3 < puVar6) {
      return 6;
    }
    uVar9 = CONCAT31(CONCAT21(CONCAT11(puVar5[8],puVar5[9]),puVar5[10]),puVar5[0xb]);
    if (((int)puVar3 - (int)puVar6 >> 2) - 1U < uVar9) {
      return 6;
    }
    uVar12 = 0;
    if (uVar9 == 0) {
      return 6;
    }
    while (CONCAT11(*puVar6,puVar6[1]) != param_2) {
      uVar12 = uVar12 + 1;
      puVar6 = puVar6 + 4;
      if (uVar9 <= uVar12) {
        return 6;
      }
    }
    uVar8 = (uint)CONCAT11(puVar6[2],puVar6[3]);
    uVar7 = (uint)CONCAT11(puVar6[6],puVar6[7]);
    if (uVar9 <= uVar12) {
      return 6;
    }
    break;
  case 5:
  case 0x13:
    if (puVar3 < puVar5 + 0x18) {
      return 6;
    }
    iVar11 = CONCAT31(CONCAT21(CONCAT11(puVar5[8],puVar5[9]),puVar5[10]),puVar5[0xb]);
    iVar10 = FUN_008c8e10(param_1,1);
    if (iVar10 != 0) {
      return 6;
    }
    puVar6 = puVar5 + 0xf;
    uVar9 = CONCAT31(CONCAT21(CONCAT11(puVar5[0xc],puVar5[0xd]),puVar5[0xe]),puVar5[0xf]);
    if ((uint)((int)puVar3 - (int)(puVar5 + 0x10) >> 1) < uVar9) {
      return 6;
    }
    uVar8 = 0;
    if (uVar9 == 0) {
      return 6;
    }
    while (puVar5 = puVar6 + 1, puVar3 = puVar6 + 2, puVar6 = puVar6 + 2,
          CONCAT11(*puVar5,*puVar3) != param_2) {
      uVar8 = uVar8 + 1;
      if (uVar9 <= uVar8) {
        return 6;
      }
    }
    if (uVar9 <= uVar8) {
      return 6;
    }
LAB_008c9846:
    uVar8 = uVar8 * iVar11;
    uVar7 = iVar11 + uVar8;
    break;
  default:
    return 6;
  }
  if (uVar7 < uVar8) {
    return 6;
  }
  uVar4 = FUN_008c9350(CONCAT11(uVar2,uVar1),param_3,param_4);
  return uVar4;
}

