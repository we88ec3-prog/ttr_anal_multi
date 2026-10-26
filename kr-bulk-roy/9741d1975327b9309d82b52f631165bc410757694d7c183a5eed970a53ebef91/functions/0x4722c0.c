
void FUN_004722c0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  int iVar11;
  int local_30;
  int local_28;
  
  if (((*(int *)(in_ECX + 0xd4) != 0) && (*(int *)(in_ECX + 0xd0) != 0)) &&
     (*(int *)(in_ECX + 0xd8) != 0)) {
    iVar2 = *(int *)(in_ECX + 0xcc);
    iVar3 = *(int *)(in_ECX + 0xd4);
    FUN_0043c810((float)((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) + iVar2) / (float)iVar3)
    ;
    iVar7 = FUN_008fed10();
    iVar9 = *(int *)(in_ECX + 0xcc) % *(int *)(in_ECX + 0xd4);
    if (*(int *)(in_ECX + 0xa4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0xa4) + 0xbc))
                (0,0,*(undefined4 *)(in_ECX + 0xd0),*(int *)(in_ECX + 0xd4));
    }
    iVar4 = *(int *)(in_ECX + 0xd8);
    piVar5 = *(int **)(in_ECX + 0xac);
    piVar10 = *(int **)(in_ECX + 0xa8);
    local_28 = 0;
    local_30 = 0;
    for (; piVar10 != piVar5; piVar10 = piVar10 + 1) {
      if ((local_28 < iVar4 * (iVar2 / iVar3)) || (iVar4 * iVar7 <= local_28)) {
        (**(code **)(*(int *)*piVar10 + 0xbc))
                  (0,0,*(undefined4 *)(in_ECX + 0xd0),*(undefined4 *)(in_ECX + 0xd4));
        uVar6 = *(uint *)(*piVar10 + 0x28);
        if ((uVar6 & 0x100) != 0) {
          *(uint *)(*piVar10 + 0x28) = uVar6 ^ 0x100;
        }
      }
      else {
        iVar11 = *(int *)(in_ECX + 0xd0) * (local_30 % *(int *)(in_ECX + 0xd8));
        iVar8 = *(int *)(in_ECX + 0xd4) * (local_30 / *(int *)(in_ECX + 0xd8));
        (**(code **)(*(int *)*piVar10 + 0xbc))
                  (iVar11,iVar8 - iVar9,*(int *)(in_ECX + 0xd0) + iVar11,
                   (*(int *)(in_ECX + 0xd4) - iVar9) + iVar8);
        if ((*(uint *)(*piVar10 + 0x28) >> 8 & 1) == 0) {
          puVar1 = (uint *)(*piVar10 + 0x28);
          *puVar1 = *puVar1 | 0x100;
          (**(code **)(*(int *)*piVar10 + 200))();
        }
        local_30 = local_30 + 1;
      }
      local_28 = local_28 + 1;
    }
  }
  return;
}

