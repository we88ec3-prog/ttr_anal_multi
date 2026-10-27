
void FUN_00649120(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int in_EDX;
  int *unaff_ESI;
  uint uVar9;
  
  uVar9 = 0;
  uVar7 = *(int *)(param_1 + 0xe4) - *(int *)(param_1 + 0xe0) >> 2;
  if (uVar7 != 0) {
    piVar8 = *(int **)(param_1 + 0xe0);
    do {
      if ((*piVar8 != 0) && (*(int *)(*piVar8 + 0x24c) == in_EDX)) {
        (**(code **)(**(int **)(*(int *)(param_1 + 0xe0) + uVar9 * 4) + 0xa0))(1);
        iVar1 = *(int *)(*(int *)(param_1 + 0xe0) + uVar9 * 4);
        iVar2 = *(int *)(iVar1 + 0x10);
        iVar3 = *(int *)(iVar1 + 0xc);
        iVar4 = *(int *)(iVar1 + 0x14);
        iVar5 = *(int *)(*(int *)(param_1 + 0xdc) + 8);
        iVar6 = *(int *)(*(int *)(param_1 + 0xdc) + 0xc);
        *unaff_ESI = *(int *)(iVar1 + 8) + iVar5;
        unaff_ESI[1] = iVar3 + iVar6;
        unaff_ESI[2] = iVar2 + iVar5;
        unaff_ESI[3] = iVar4 + iVar6;
        return;
      }
      uVar9 = uVar9 + 1;
      piVar8 = piVar8 + 1;
    } while (uVar9 < uVar7);
  }
  unaff_ESI[3] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[1] = 0;
  *unaff_ESI = 0;
  return;
}

