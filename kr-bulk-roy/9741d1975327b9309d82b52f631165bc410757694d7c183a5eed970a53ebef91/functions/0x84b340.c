
void FUN_0084b340(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x84) != *(int *)(unaff_EDI + 0x88)) {
    uVar2 = FUN_0084b990(param_1);
    *(undefined4 *)(unaff_EDI + 0x88) = uVar2;
  }
  iVar4 = (*(int *)(unaff_EDI + 0x78) - *(int *)(unaff_EDI + 0x74)) / 0x14;
  if (iVar4 != 0) {
    iVar5 = 0;
    do {
      iVar1 = *(int *)(*(int *)(unaff_EDI + 0x74) + iVar5);
      iVar3 = *(int *)(unaff_EDI + 0x74) + iVar5;
      if (iVar1 != 0) {
        FUN_0086ad30(iVar1,unaff_EDI,iVar3 + 4,iVar3 + 0x10,param_1);
      }
      iVar5 = iVar5 + 0x14;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}

