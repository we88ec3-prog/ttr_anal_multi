
undefined2 FUN_008c4a00(int param_1,int param_2)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  uVar3 = param_2 - (uint)CONCAT11(*(undefined1 *)(iVar1 + 6),*(undefined1 *)(iVar1 + 7));
  uVar2 = 0;
  if (uVar3 < CONCAT11(*(undefined1 *)(iVar1 + 8),*(undefined1 *)(iVar1 + 9))) {
    uVar2 = CONCAT11(*(undefined1 *)(iVar1 + 10 + uVar3 * 2),
                     *(undefined1 *)(iVar1 + 0xb + uVar3 * 2));
  }
  return uVar2;
}

