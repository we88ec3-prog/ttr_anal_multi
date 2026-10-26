
undefined4 FUN_008c4950(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  
  if (*(uint *)(param_2 + 4) < param_1 + 10U) {
    FUN_008b8460(param_2,8);
  }
  uVar3 = (uint)CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  puVar5 = (undefined1 *)(param_1 + 9);
  uVar4 = (uint)CONCAT11(*(undefined1 *)(param_1 + 8),*puVar5);
  if ((*(uint *)(param_2 + 4) < uVar3 + param_1) || (uVar3 < uVar4 * 2 + 10)) {
    FUN_008b8460(param_2,8);
  }
  if (0 < *(int *)(param_2 + 8)) {
    for (; uVar4 != 0; uVar4 = uVar4 - 1) {
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

