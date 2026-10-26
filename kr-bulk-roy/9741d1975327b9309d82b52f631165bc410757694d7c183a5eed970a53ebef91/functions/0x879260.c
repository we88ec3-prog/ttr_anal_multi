
void FUN_00879260(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  iVar4 = FUN_008fed10((*(int *)(unaff_EDI + 0x2c) - *(int *)(unaff_EDI + 0x28)) / 0xc + -1);
  iVar1 = *(int *)(unaff_EDI + 0x28) + iVar4 * 0xc;
  uVar2 = *(undefined4 *)(iVar1 + 4);
  uVar3 = *(undefined4 *)(iVar1 + 8);
  *unaff_ESI = *(undefined4 *)(*(int *)(unaff_EDI + 0x28) + iVar4 * 0xc);
  unaff_ESI[1] = uVar2;
  unaff_ESI[2] = uVar3;
  return;
}

