
void FUN_007e3c50(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x28);
  iVar1 = iVar2 >> 0x1f;
  uVar3 = 0;
  if (iVar2 / 0x44 + iVar1 != iVar1) {
    do {
      iVar1 = FUN_007e25f0();
      *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)((*(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x28)) / 0x44));
  }
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + 1;
  return;
}

