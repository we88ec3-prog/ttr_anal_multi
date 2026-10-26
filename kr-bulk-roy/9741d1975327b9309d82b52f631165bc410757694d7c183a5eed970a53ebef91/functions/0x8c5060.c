
undefined4 FUN_008c5060(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  if (*(uint *)(param_2 + 4) < param_1 + 0x14U) {
    FUN_008b8460(param_2,8);
  }
  uVar3 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                            *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7));
  puVar5 = (undefined1 *)(param_1 + 0x13);
  iVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 0x11)
                                    ),*(undefined1 *)(param_1 + 0x12)),*puVar5);
  if (((uint)(*(int *)(param_2 + 4) - param_1) < uVar3) || (uVar3 < iVar4 * 2 + 0x14U)) {
    FUN_008b8460(param_2,8);
  }
  if (0 < *(int *)(param_2 + 8)) {
    for (; iVar4 != 0; iVar4 = iVar4 + -1) {
      puVar1 = puVar5 + 1;
      puVar2 = puVar5 + 2;
      puVar5 = puVar5 + 2;
      if (*(uint *)(param_2 + 0x50) <= (uint)CONCAT11(*puVar1,*puVar2)) {
        FUN_008b8460(param_2,0x10);
      }
    }
  }
  return 0;
}

