
void FUN_006a6600(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00945b3c;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_8 = 0xffffffff;
  iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  uVar11 = DAT_00fc0bc8 - DAT_00fc0bc4 >> 2;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar11);
  }
  uVar9 = 0;
  if (uVar11 != 0) {
    do {
      if ((DAT_00fbad10 & 1) == 0) {
        DAT_00fbad10 = DAT_00fbad10 | 1;
        local_8 = 1;
        FUN_004e8010(uVar6);
        _atexit((_func_4879 *)&LAB_00bcd6b0);
        local_8 = 0xffffffff;
      }
      if ((uVar9 < (uint)(DAT_00fc0bc8 - DAT_00fc0bc4 >> 2)) &&
         (iVar1 = *(int *)(DAT_00fc0bc4 + uVar9 * 4), iVar1 != 0)) {
        iVar2 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
        iVar1 = *(int *)(iVar1 + 4);
        if ((iVar2 == 0) ||
           ((((int)uVar9 < 0 || (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= (int)uVar9)
             ) || (iVar8 = *(int *)(*(int *)(iVar2 + 0xa8) + uVar9 * 4), iVar8 == 0)))) {
          iVar8 = 0;
        }
        else {
          *(int *)(iVar8 + 0x20) = iVar1;
          uVar10 = iVar1 + 1;
          if (uVar10 <= *(uint *)(iVar2 + 0xe4)) {
            uVar10 = *(uint *)(iVar2 + 0xe4);
          }
          *(uint *)(iVar2 + 0xe4) = uVar10;
        }
        FUN_006a6000(iVar8);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar11);
  }
  piVar3 = *(int **)(param_1 + 0xec);
  puVar4 = (undefined4 *)piVar3[0x19];
  for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
    iVar1 = puVar5[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar3 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if ((iVar1 == 0) || (iVar1 = *(int *)(iVar1 + 0xdc), iVar1 == 0)) {
    uVar7 = 0xffffffff;
  }
  else {
    uVar7 = *(undefined4 *)(iVar1 + 0x20);
  }
  FUN_006a6ce0(param_1,uVar7);
  ExceptionList = local_10;
  return;
}

