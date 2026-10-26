
undefined4 FUN_007e43d0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if (*(int *)(param_1 + 0x78) != 0) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58);
  iVar1 = iVar3 >> 0x1f;
  iVar3 = iVar3 / 0x2c + iVar1;
  uVar5 = 0;
  if (iVar3 != iVar1) {
    iVar4 = 0;
    do {
      iVar2 = (**(code **)(**(int **)(iVar4 + 0x28 + *(int *)(param_1 + 0x58)) + 0x2c))(param_2);
      if (iVar2 != 0) {
        return 1;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x2c;
    } while (uVar5 < (uint)(iVar3 - iVar1));
  }
  return 0;
}

