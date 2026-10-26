
void FUN_006fac80(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(iVar1 + 8);
  if ((*(uint *)(iVar1 + 4) < (uint)((int)(iVar2 + (iVar2 >> 0x1f & 3U)) >> 2)) && (0x40 < iVar2)) {
    FUN_006feb00(param_1,iVar2 / 2);
  }
  uVar3 = *(uint *)(iVar1 + 0x3c);
  if (0x40 < uVar3) {
    uVar5 = uVar3 >> 1;
    if (uVar5 + 1 < 0xfffffffe) {
      uVar4 = FUN_00700880(param_1,*(undefined4 *)(iVar1 + 0x34),uVar3,uVar5);
      *(uint *)(iVar1 + 0x3c) = uVar5;
      *(undefined4 *)(iVar1 + 0x34) = uVar4;
      return;
    }
    uVar4 = FUN_00700860(param_1);
    *(uint *)(iVar1 + 0x3c) = uVar5;
    *(undefined4 *)(iVar1 + 0x34) = uVar4;
  }
  return;
}

