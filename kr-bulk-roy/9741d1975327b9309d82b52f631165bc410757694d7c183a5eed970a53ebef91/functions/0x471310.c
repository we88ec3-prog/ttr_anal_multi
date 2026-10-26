
void FUN_00471310(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int unaff_EDI;
  int local_8;
  
  if (*(int *)(unaff_EDI + 0xd4) != 0) {
    iVar2 = *(int *)(unaff_EDI + 0xcc);
    iVar3 = *(int *)(unaff_EDI + 0xd4);
    iVar11 = 0;
    iVar4 = *(int *)(unaff_EDI + 0x14);
    iVar5 = *(int *)(unaff_EDI + 0xc);
    piVar12 = *(int **)(unaff_EDI + 0xa8);
    local_8 = 0;
    piVar6 = *(int **)(unaff_EDI + 0xac);
    for (; piVar12 != piVar6; piVar12 = piVar12 + 1) {
      if ((local_8 < iVar2 / iVar3) || (((iVar4 - iVar5) + iVar2) / iVar3 < local_8)) {
        uVar9 = *(uint *)(*piVar12 + 0x28);
        if ((uVar9 & 0x100) != 0) {
          *(uint *)(*piVar12 + 0x28) = uVar9 ^ 0x100;
        }
      }
      else {
        iVar10 = *(int *)(unaff_EDI + 0xd4);
        iVar7 = *piVar12;
        iVar8 = *(int *)(iVar7 + 8);
        *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + -iVar8;
        *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + -iVar8;
        iVar10 = (iVar10 * iVar11 - *(int *)(iVar7 + 0xc)) - iVar2 % iVar3;
        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + iVar10;
        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + iVar10;
        FUN_00746f70();
        if ((*(uint *)(*piVar12 + 0x28) >> 8 & 1) == 0) {
          puVar1 = (uint *)(*piVar12 + 0x28);
          *puVar1 = *puVar1 | 0x100;
          (**(code **)(*(int *)*piVar12 + 200))();
        }
        iVar11 = iVar11 + 1;
      }
      local_8 = local_8 + 1;
    }
  }
  return;
}

