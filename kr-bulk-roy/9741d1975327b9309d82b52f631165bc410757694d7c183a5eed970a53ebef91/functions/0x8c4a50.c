
short FUN_008c4a50(int param_1,uint *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  
  iVar3 = *(int *)(param_1 + 0x10);
  uVar5 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 6),*(undefined1 *)(iVar3 + 7));
  uVar4 = *param_2 + 1;
  uVar7 = (uint)CONCAT11(*(undefined1 *)(iVar3 + 8),*(undefined1 *)(iVar3 + 9));
  if (0xffff < uVar4) {
    *param_2 = 0;
    return 0;
  }
  if (uVar4 < uVar5) {
    uVar4 = uVar5;
  }
  uVar5 = uVar4 - uVar5;
  if (uVar5 < uVar7) {
    puVar6 = (undefined1 *)(iVar3 + 9 + uVar5 * 2);
    do {
      uVar1 = puVar6[1];
      puVar6 = puVar6 + 2;
      uVar2 = *puVar6;
      if (CONCAT11(uVar1,uVar2) != 0) {
        *param_2 = uVar4;
        return CONCAT11(uVar1,uVar2);
      }
      uVar5 = uVar5 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar5 < uVar7);
    *param_2 = 0;
    return 0;
  }
  *param_2 = 0;
  return 0;
}

