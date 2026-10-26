
short FUN_008c51a0(int param_1,uint *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = *(int *)(param_1 + 0x10);
  uVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0xc),*(undefined1 *)(iVar3 + 0xd)),
                            *(undefined1 *)(iVar3 + 0xe)),*(undefined1 *)(iVar3 + 0xf));
  uVar6 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x10),*(undefined1 *)(iVar3 + 0x11)),
                            *(undefined1 *)(iVar3 + 0x12)),*(undefined1 *)(iVar3 + 0x13));
  uVar7 = *param_2 + 1;
  if (*param_2 + 1 < uVar4) {
    uVar7 = uVar4;
  }
  uVar4 = uVar7 - uVar4;
  if (uVar4 < uVar6) {
    puVar5 = (undefined1 *)(iVar3 + 0x13 + uVar4 * 2);
    do {
      uVar1 = puVar5[1];
      puVar5 = puVar5 + 2;
      uVar2 = *puVar5;
      if (CONCAT11(uVar1,uVar2) != 0) {
        *param_2 = uVar7;
        return CONCAT11(uVar1,uVar2);
      }
      uVar4 = uVar4 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar4 < uVar6);
    *param_2 = uVar7;
    return 0;
  }
  *param_2 = uVar7;
  return 0;
}

