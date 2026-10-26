
void FUN_00767950(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_18;
  uint local_10;
  
  local_10 = *(uint *)(param_1 + 0x14c);
  uVar1 = *(uint *)(param_1 + 0x150);
  if ((int)uVar1 < (int)local_10) {
    iVar5 = *(int *)(param_1 + 0x158);
    iVar2 = *(int *)(param_1 + 0x154);
    uVar3 = local_10;
    local_10 = uVar1;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x154);
    iVar2 = *(int *)(param_1 + 0x158);
    uVar3 = uVar1;
  }
  iVar4 = uVar3 - local_10;
  if ((0 < iVar4) ||
     ((iVar4 == 0 &&
      (uVar3 = iVar2 - iVar5 >> 0x1f, uVar1 = iVar2 - iVar5 ^ uVar3,
      uVar1 != uVar3 && -1 < (int)(uVar1 - uVar3))))) {
    local_18 = 0;
    if (0 < iVar4 + 1) {
      do {
        if ((uint)(*(int *)(param_1 + 0x114) - *(int *)(param_1 + 0x110) >> 2) <= local_10) {
          return;
        }
        FUN_00757da0(param_2);
        local_18 = local_18 + 1;
        local_10 = local_10 + 1;
      } while (local_18 < iVar4 + 1);
    }
  }
  return;
}

