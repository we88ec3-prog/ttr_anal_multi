
undefined4 FUN_008cfea0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  uVar6 = (uVar2 - 8) + *(int *)(param_1 + 0x10) * 8;
  iVar4 = 0;
  if (uVar2 <= uVar6) {
    do {
      iVar3 = (int)(uVar6 - uVar2) >> 4;
      uVar1 = *(uint *)(uVar2 + iVar3 * 8);
      iVar3 = uVar2 + iVar3 * 8;
      iVar5 = iVar3;
      if (uVar1 == param_2) break;
      uVar1 = uVar1 & 0x7fffffff;
      iVar5 = iVar4;
      if (uVar1 == param_2) {
        iVar5 = iVar3;
      }
      if (uVar2 == uVar6) break;
      if (uVar1 < param_2) {
        uVar2 = iVar3 + 8;
      }
      else {
        uVar6 = iVar3 - 8;
      }
      iVar4 = iVar5;
    } while (uVar2 <= uVar6);
    if (iVar5 != 0) {
      return *(undefined4 *)(iVar5 + 4);
    }
  }
  return 0;
}

