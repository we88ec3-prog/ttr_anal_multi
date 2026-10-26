
int * FUN_004644f0(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  short *psVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  short sVar9;
  int iVar10;
  bool bVar11;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009134ba;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  bVar6 = false;
  bVar7 = false;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
  }
  local_8 = 0;
  if ((*(int *)(*(int *)(*param_1 + 4) + 0xc + (int)param_1) == 0) &&
     (*(int *)(*(int *)(*param_1 + 4) + 0x3c + (int)param_1) != 0)) {
    FUN_006de0c0();
  }
  iVar2 = *(int *)(*param_1 + 4);
  if (*(int *)((int)param_1 + iVar2 + 0xc) == 0) {
    local_20 = *(int *)((int)param_1 + iVar2 + 0x24);
    uVar3 = *(uint *)((int)param_1 + iVar2 + 0x20);
    if ((local_20 < 1) && ((local_20 < 0 || (uVar3 < 2)))) {
      iVar10 = 0;
      local_20 = 0;
    }
    else {
      iVar10 = uVar3 - 1;
      local_20 = local_20 - (uint)(uVar3 == 0);
    }
    local_8 = 2;
    if ((*(uint *)((int)param_1 + iVar2 + 0x14) & 0x1c0) == 0x40) {
LAB_0046461d:
      piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
      if ((*(int *)piVar1[9] == 0) || (piVar4 = (int *)piVar1[0xd], *piVar4 < 1)) {
        sVar9 = (**(code **)(*piVar1 + 0xc))(param_2);
      }
      else {
        *piVar4 = *piVar4 + -1;
        psVar5 = *(short **)piVar1[9];
        *(short **)piVar1[9] = psVar5 + 1;
        sVar9 = (short)param_2;
        *psVar5 = sVar9;
      }
      if (sVar9 == -1) {
        bVar6 = true;
        bVar7 = true;
      }
      for (; ((!bVar6 && (-1 < local_20)) && ((0 < local_20 || (iVar10 != 0))));
          iVar10 = iVar10 + -1) {
        piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
        sVar9 = *(short *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1);
        if ((*(int *)piVar1[9] == 0) || (piVar4 = (int *)piVar1[0xd], *piVar4 < 1)) {
          sVar9 = (**(code **)(*piVar1 + 0xc))(sVar9);
        }
        else {
          *piVar4 = *piVar4 + -1;
          psVar5 = *(short **)piVar1[9];
          *(short **)piVar1[9] = psVar5 + 1;
          *psVar5 = sVar9;
          bVar6 = bVar7;
        }
        if (sVar9 == -1) {
          bVar6 = true;
          bVar7 = true;
        }
        local_20 = local_20 + -1 + (uint)(iVar10 != 0);
      }
    }
    else {
      while (!bVar6) {
        if ((local_20 < 0) || ((local_20 < 1 && (iVar10 == 0)))) goto LAB_0046461d;
        piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
        sVar9 = *(short *)(*(int *)(*param_1 + 4) + 0x40 + (int)param_1);
        if ((*(int *)piVar1[9] == 0) || (piVar4 = (int *)piVar1[0xd], *piVar4 < 1)) {
          sVar9 = (**(code **)(*piVar1 + 0xc))(sVar9);
        }
        else {
          *piVar4 = *piVar4 + -1;
          psVar5 = *(short **)piVar1[9];
          *(short **)piVar1[9] = psVar5 + 1;
          *psVar5 = sVar9;
          bVar6 = bVar7;
        }
        if (sVar9 == -1) {
          bVar6 = true;
          bVar7 = true;
        }
        bVar11 = iVar10 != 0;
        iVar10 = iVar10 + -1;
        local_20 = local_20 + -1 + (uint)bVar11;
      }
    }
  }
  local_8 = 1;
  iVar2 = *(int *)(*param_1 + 4);
  *(undefined4 *)(iVar2 + 0x20 + (int)param_1) = 0;
  *(undefined4 *)(iVar2 + 0x24 + (int)param_1) = 0;
  if (bVar6) {
    FUN_00431a90(0);
  }
  local_8 = 4;
  cVar8 = thunk_FUN_0089ccbb();
  if (cVar8 == '\0') {
    FUN_006ddfe0();
  }
  local_8 = 0xffffffff;
  piVar1 = *(int **)(*(int *)(*param_1 + 4) + 0x38 + (int)param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))();
  }
  ExceptionList = local_10;
  return param_1;
}

