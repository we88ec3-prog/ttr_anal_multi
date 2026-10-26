
void FUN_00549490(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  
  if (param_1 != 0) {
    iVar6 = 0;
    piVar4 = (int *)(unaff_EDI + 0xd8);
    while (*piVar4 != 0) {
      iVar6 = iVar6 + 1;
      piVar4 = piVar4 + 4;
      if (2 < iVar6) {
        return;
      }
    }
    if (iVar6 != -1) {
      iVar5 = FUN_005495f0(unaff_EDI);
      if (iVar5 != -1) {
        iVar1 = unaff_EDI + 0xa8 + iVar5 * 0x10;
        puVar2 = (undefined4 *)(unaff_EDI + 0xd8 + iVar6 * 0x10);
        *puVar2 = *(undefined4 *)(unaff_EDI + 0xa8 + iVar5 * 0x10);
        puVar2[1] = *(undefined4 *)(iVar1 + 4);
        puVar2[2] = *(undefined4 *)(iVar1 + 8);
        puVar2[3] = *(undefined4 *)(iVar1 + 0xc);
        return;
      }
      puVar3 = (uint *)(unaff_EDI + 0xd8 + iVar6 * 0x10);
      *puVar3 = 0;
      puVar3[1] = 1;
      puVar3[2] = 0;
      puVar3[3] = 0;
      *puVar3 = (uint)*(ushort *)(param_1 + 4);
    }
  }
  return;
}

