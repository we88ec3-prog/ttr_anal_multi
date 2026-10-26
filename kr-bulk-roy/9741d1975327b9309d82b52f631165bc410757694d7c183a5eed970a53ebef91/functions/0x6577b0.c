
void FUN_006577b0(void)

{
  uint *puVar1;
  int *piVar2;
  code *pcVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iStack_48;
  int iStack_44;
  int local_40;
  
  iVar10 = 0;
  bVar5 = false;
  FUN_00471530();
  iVar7 = *(int *)(in_ECX + 0xcc);
  if (iVar7 != 0) {
    piVar9 = *(int **)(iVar7 + 0xa8);
    piVar2 = *(int **)(iVar7 + 0xac);
    if (*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x30) < *(int *)(in_ECX + 0xdc)) {
      (**(code **)(**(int **)(in_ECX + 0xd0) + 0xd0))();
      iVar7 = *(int *)(in_ECX + 0xd0);
      iVar8 = *(int *)(in_ECX + 0xa4);
      if (iVar8 <= *(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 8)) {
        iVar8 = *(int *)(iVar7 + 0x10) - *(int *)(iVar7 + 8);
      }
      *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) - iVar8;
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0xd0) + 0xd4))();
    }
    piVar6 = *(int **)(in_ECX + 0xd0);
    if (((uint)piVar6[10] >> 8 & 1) != 0) {
      iVar7 = *(int *)(in_ECX + 0xcc);
      if (0 < (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 0x14)) + *(int *)(in_ECX + 0xdc)) {
        iVar10 = (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 0x14)) + *(int *)(in_ECX + 0xdc);
      }
      piVar6[0x2e] = iVar10;
      if (iVar10 < piVar6[0x31]) {
        pcVar3 = *(code **)(*piVar6 + 0x128);
        piVar6[0x31] = iVar10;
        (*pcVar3)();
        (**(code **)(*piVar6 + 200))();
      }
      piVar6 = *(int **)(in_ECX + 0xd0);
      if (iVar10 < piVar6[0x31]) {
        pcVar3 = *(code **)(*piVar6 + 0x128);
        piVar6[0x31] = iVar10;
        (*pcVar3)();
        (**(code **)(*piVar6 + 200))();
      }
    }
    local_40 = 0;
    iStack_44 = 0;
    if ((*(uint *)(*(int *)(in_ECX + 0xd0) + 0x28) >> 8 & 1) == 0) {
      iStack_48 = 0;
    }
    else {
      iStack_48 = *(int *)(*(int *)(in_ECX + 0xd0) + 0xc4);
    }
    for (; piVar9 != piVar2; piVar9 = piVar9 + 1) {
      for (piVar6 = *(int **)(*(int *)(in_ECX + 0xcc) + 0xa8);
          (piVar6 != *(int **)(*(int *)(in_ECX + 0xcc) + 0xac) &&
          (*(int *)(*piVar6 + 0x20) != local_40)); piVar6 = piVar6 + 1) {
      }
      iVar7 = FUN_00657760();
      if (*(int *)(iVar7 + 4) < iStack_48) {
LAB_00657970:
        bVar4 = false;
      }
      else {
        bVar5 = true;
        iVar7 = FUN_00657760();
        if ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc)) + iStack_48 < *(int *)(iVar7 + 4))
        goto LAB_00657970;
        bVar4 = true;
      }
      if (bVar5) {
        bVar5 = false;
      }
      iVar7 = *piVar9;
      if (bVar4) {
        iVar10 = *(int *)(iVar7 + 8);
        *(int *)(iVar7 + 8) = *(int *)(iVar7 + 8) + -iVar10;
        *(int *)(iVar7 + 0x10) = *(int *)(iVar7 + 0x10) + -iVar10;
        iVar10 = iStack_44 - *(int *)(iVar7 + 0xc);
        *(int *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + iVar10;
        *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + iVar10;
        FUN_00746f70();
        iVar7 = FUN_00657760();
        iStack_44 = iStack_44 + (*(int *)(iVar7 + 0xc) - *(int *)(iVar7 + 4));
        if ((*(uint *)(*piVar9 + 0x28) >> 8 & 1) == 0) {
          puVar1 = (uint *)(*piVar9 + 0x28);
          *puVar1 = *puVar1 | 0x100;
          (**(code **)(*(int *)*piVar9 + 200))();
        }
      }
      else if ((*(uint *)(iVar7 + 0x28) & 0x100) != 0) {
        *(uint *)(iVar7 + 0x28) = *(uint *)(iVar7 + 0x28) ^ 0x100;
      }
      local_40 = local_40 + 1;
    }
    FUN_00745b80();
  }
  return;
}

