
void FUN_0071a530(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar3 = FUN_0071a4c0();
  if (iVar3 == 0) {
    return;
  }
  *(int *)(iVar3 + 4) = unaff_ESI;
  iVar1 = *(int *)(unaff_ESI + 0x10);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x14);
    *(int *)(iVar2 + 0x18) = iVar3;
    *(int *)(iVar3 + 0x14) = iVar2;
    *(int *)(iVar1 + 0x14) = iVar3;
    return;
  }
  *(int *)(unaff_ESI + 0x10) = iVar3;
  *(int *)(iVar3 + 0x14) = iVar3;
  return;
}

