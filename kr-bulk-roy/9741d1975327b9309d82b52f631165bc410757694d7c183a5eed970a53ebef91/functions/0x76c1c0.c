
void FUN_0076c1c0(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  int *piVar8;
  int local_68;
  int local_60;
  
  iVar2 = *(int *)(in_ECX + 0xd4);
  if (iVar2 != 0) {
    iVar3 = *(int *)(in_ECX + 0xcc);
    FUN_008ff2e0((double)((float)((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) + iVar3) /
                         (float)iVar2));
    iVar7 = FUN_008fed10();
    iVar4 = *(int *)(in_ECX + 0xcc);
    if (*(int *)(in_ECX + 0xa4) != 0) {
      (**(code **)(**(int **)(in_ECX + 0xa4) + 0xbc))
                (0,0,*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),*(undefined4 *)(in_ECX + 0xd4));
    }
    piVar5 = *(int **)(in_ECX + 0xac);
    piVar8 = *(int **)(in_ECX + 0xa8);
    local_60 = 0;
    local_68 = 0;
    for (; piVar8 != piVar5; piVar8 = piVar8 + 1) {
      if ((local_60 < iVar3 / iVar2) || (iVar7 < local_60)) {
        (**(code **)(*(int *)*piVar8 + 0xbc))(0,0,*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8));
        uVar6 = *(uint *)(*piVar8 + 0x28);
        if ((uVar6 & 0x100) != 0) {
          *(uint *)(*piVar8 + 0x28) = uVar6 ^ 0x100;
        }
      }
      else {
        (**(code **)(*(int *)*piVar8 + 0xbc))
                  (0,*(int *)(in_ECX + 0xd4) * local_68 - iVar4 % iVar2,
                   *(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8));
        if ((*(uint *)(*piVar8 + 0x28) >> 8 & 1) == 0) {
          puVar1 = (uint *)(*piVar8 + 0x28);
          *puVar1 = *puVar1 | 0x100;
          (**(code **)(*(int *)*piVar8 + 200))();
        }
        local_68 = local_68 + 1;
      }
      local_60 = local_60 + 1;
    }
  }
  return;
}

