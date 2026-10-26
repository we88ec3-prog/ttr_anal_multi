
undefined4 FUN_0082ed20(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int local_c;
  
  iVar1 = in_ECX[1];
  uVar4 = in_EAX[1] - iVar1;
  uVar9 = (int)uVar4 >> 0x1f;
  iVar2 = *in_ECX;
  uVar10 = *in_EAX - iVar2;
  iVar8 = (uVar4 ^ uVar9) - uVar9;
  uVar4 = (int)uVar10 >> 0x1f;
  iVar5 = (uVar10 ^ uVar4) - uVar4;
  if (iVar8 < iVar5) {
    iVar8 = iVar5;
  }
  if ((iVar8 != 0) && (local_c = 0, 0 < iVar8)) {
    iVar5 = *(int *)(param_1 + 8);
    iVar3 = *(int *)(param_1 + 0x20);
    do {
      iVar6 = FUN_008fed10();
      iVar7 = FUN_008fed10();
      if (*(int *)(iVar3 + 0x10 + (iVar5 * (iVar7 + iVar1) + iVar2 + iVar6) * 0x18) == 0) {
        return 0;
      }
      local_c = local_c + 1;
    } while (local_c < iVar8);
  }
  return 1;
}

