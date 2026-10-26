
void FUN_004713f0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int unaff_ESI;
  int iVar14;
  int local_c;
  int local_8;
  
  if (*(int *)(unaff_ESI + 0xd4) != 0) {
    iVar2 = *(int *)(unaff_ESI + 0xcc);
    iVar3 = *(int *)(unaff_ESI + 0xd4);
    FUN_0043c810((float)((*(int *)(unaff_ESI + 0x14) - *(int *)(unaff_ESI + 0xc)) + iVar2) /
                 (float)iVar3);
    iVar11 = FUN_008fed10();
    iVar4 = *(int *)(unaff_ESI + 0xcc);
    iVar5 = *(int *)(unaff_ESI + 0xd4);
    iVar6 = *(int *)(unaff_ESI + 0xd8);
    piVar13 = *(int **)(unaff_ESI + 0xa8);
    piVar7 = *(int **)(unaff_ESI + 0xac);
    local_c = 0;
    local_8 = 0;
    for (; piVar13 != piVar7; piVar13 = piVar13 + 1) {
      if ((local_c < iVar6 * (iVar2 / iVar3)) || (iVar6 * iVar11 <= local_c)) {
        uVar10 = *(uint *)(*piVar13 + 0x28);
        if ((uVar10 & 0x100) != 0) {
          *(uint *)(*piVar13 + 0x28) = uVar10 ^ 0x100;
        }
      }
      else {
        iVar14 = *(int *)(unaff_ESI + 0xd8);
        iVar8 = *(int *)(unaff_ESI + 0xd4);
        iVar9 = *piVar13;
        iVar12 = *(int *)(unaff_ESI + 0xd0) * (local_8 % iVar14) - *(int *)(iVar9 + 8);
        *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + iVar12;
        *(int *)(iVar9 + 0x10) = *(int *)(iVar9 + 0x10) + iVar12;
        iVar14 = (iVar8 * (local_8 / iVar14) - *(int *)(iVar9 + 0xc)) - iVar4 % iVar5;
        *(int *)(iVar9 + 0xc) = *(int *)(iVar9 + 0xc) + iVar14;
        *(int *)(iVar9 + 0x14) = *(int *)(iVar9 + 0x14) + iVar14;
        FUN_00746f70();
        if ((*(uint *)(*piVar13 + 0x28) >> 8 & 1) == 0) {
          puVar1 = (uint *)(*piVar13 + 0x28);
          *puVar1 = *puVar1 | 0x100;
          (**(code **)(*(int *)*piVar13 + 200))();
        }
        local_8 = local_8 + 1;
      }
      local_c = local_c + 1;
    }
  }
  return;
}

