
void FUN_005b0290(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = *(int *)(*(int *)(unaff_ESI + 0x164) + 0xc);
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x228) + 0xb0);
  iVar2 = (*(int *)(*(int *)(unaff_ESI + 0x164) + 8) + 0x1db) - *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;
  iVar3 = (iVar3 + 10) - *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar3;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar3;
  FUN_00746f70();
  iVar3 = *(int *)(*(int *)(unaff_ESI + 0x164) + 0xc);
  iVar1 = *(int *)(*(int *)(unaff_ESI + 0x228) + 0xb4);
  iVar2 = (*(int *)(*(int *)(unaff_ESI + 0x164) + 8) + 0x2d5) - *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + iVar2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + iVar2;
  iVar3 = (iVar3 + 10) - *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + iVar3;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + iVar3;
  FUN_00746f70();
  return;
}

