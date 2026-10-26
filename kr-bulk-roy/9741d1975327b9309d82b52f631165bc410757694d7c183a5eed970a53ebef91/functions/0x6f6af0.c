
undefined4 FUN_006f6af0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_EDI;
  
  iVar3 = (*unaff_EDI - (int)unaff_EDI) + -0xc;
  if (iVar3 == 0) {
    return 0;
  }
  iVar1 = unaff_EDI[2];
  if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar2 = *(undefined4 **)(iVar1 + 8);
  uVar4 = FUN_006fec70(iVar1,unaff_EDI + 3,iVar3);
  *puVar2 = uVar4;
  puVar2[2] = 4;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
  *unaff_EDI = (int)(unaff_EDI + 3);
  unaff_EDI[1] = unaff_EDI[1] + 1;
  return 1;
}

