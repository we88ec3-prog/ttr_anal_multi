
undefined4 FUN_008c3680(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (*(uint *)(param_2 + 4) < param_1 + 4U) {
    FUN_008b8460(param_2,8);
  }
  uVar2 = (uint)CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  if ((*(uint *)(param_2 + 4) < uVar2 + param_1) || (uVar2 < 0x106)) {
    FUN_008b8460(param_2,8);
  }
  if (0 < *(int *)(param_2 + 8)) {
    pbVar4 = (byte *)(param_1 + 6);
    iVar3 = 0x100;
    do {
      bVar1 = *pbVar4;
      pbVar4 = pbVar4 + 1;
      if (*(uint *)(param_2 + 0x50) <= (uint)bVar1) {
        FUN_008b8460(param_2,0x10);
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}

