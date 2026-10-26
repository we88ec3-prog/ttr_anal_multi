
undefined4 FUN_00832f60(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_EAX;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  iVar1 = *(int *)(in_EAX + 0x14);
  iVar2 = *(int *)(in_EAX + 0x1c);
  iVar3 = *(int *)(in_EAX + 0x18);
  iVar4 = *(int *)(in_ECX + 0x18);
  iVar5 = *(int *)(in_EAX + 0x20);
  if ((iVar4 == iVar5) || (iVar6 = *(int *)(in_ECX + 0x20), iVar6 == iVar3)) {
    uVar7 = (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x14)) / 2;
    uVar9 = (int)uVar7 >> 0x1f;
    uVar8 = (iVar2 - iVar1) / 2;
    uVar10 = (int)uVar8 >> 0x1f;
    uVar10 = ((uVar7 ^ uVar9) - uVar9) - ((uVar8 ^ uVar10) - uVar10);
    uVar8 = (int)uVar10 >> 0x1f;
    uVar7 = (*(int *)(in_ECX + 0x1c) + *(int *)(in_ECX + 0x14)) / 2 - (iVar1 + iVar2) / 2;
    uVar9 = (int)uVar7 >> 0x1f;
    if ((int)((uVar10 ^ uVar8) - uVar8) < (int)((uVar7 ^ uVar9) - uVar9)) {
      return 0;
    }
    return 1;
  }
  if ((*(int *)(in_ECX + 0x14) != iVar2) && (*(int *)(in_ECX + 0x1c) != iVar1)) {
    return 0;
  }
  uVar7 = iVar6 - iVar4 >> 0x1f;
  uVar8 = iVar5 - iVar3 >> 0x1f;
  uVar9 = ((iVar6 - iVar4 ^ uVar7) - uVar7) - ((iVar5 - iVar3 ^ uVar8) - uVar8);
  uVar7 = (int)uVar9 >> 0x1f;
  uVar10 = (iVar6 + iVar4) / 2 - (iVar3 + iVar5) / 2;
  uVar8 = (int)uVar10 >> 0x1f;
  if ((int)((uVar9 ^ uVar7) - uVar7) < (int)((uVar10 ^ uVar8) - uVar8)) {
    return 0;
  }
  return 1;
}

