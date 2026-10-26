
undefined4 FUN_008d8f00(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = *(uint *)(*param_1 + 0x198);
  param_1[4] = uVar1;
  iVar2 = *(int *)(*param_1 + 0x1a0);
  uVar4 = 1;
  uVar3 = 0;
  param_1[5] = iVar2;
  if (1 < uVar1) {
    iVar5 = 0x10;
    while (*(uint *)(iVar5 + -0x10 + iVar2) < *(uint *)(iVar5 + iVar2)) {
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0x10;
      if ((uint)param_1[4] <= uVar4) {
        return uVar3;
      }
    }
    uVar3 = 8;
  }
  return uVar3;
}

