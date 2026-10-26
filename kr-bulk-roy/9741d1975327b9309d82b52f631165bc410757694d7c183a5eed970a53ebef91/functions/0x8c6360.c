
int FUN_008c6360(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = *(uint *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar2 = FUN_008c5c80();
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x20);
  uVar3 = 0;
  if (uVar1 != 0) {
    iVar6 = iVar4 + 9;
    iVar5 = iVar4 + 8;
    iVar4 = iVar4 + 7;
    do {
      *(uint *)(iVar2 + uVar3 * 4) =
           (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar4 + 3),*(undefined1 *)(iVar5 + 3)),
                          *(undefined1 *)(iVar6 + 3));
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0xb;
      iVar5 = iVar5 + 0xb;
      iVar6 = iVar6 + 0xb;
    } while (uVar3 < uVar1);
  }
  *(undefined4 *)(iVar2 + uVar3 * 4) = 0;
  return iVar2;
}

