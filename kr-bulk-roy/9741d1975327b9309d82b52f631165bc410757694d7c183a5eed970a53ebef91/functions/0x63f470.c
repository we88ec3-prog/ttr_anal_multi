
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063f470(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint local_c;
  
  bVar6 = false;
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  iVar9 = DAT_00fdf3b4 - DAT_00fdf3b0;
  iVar1 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  uVar10 = iVar9 >> 2;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar10);
  }
  local_c = 0;
  if (uVar10 != 0) {
    do {
      if ((_DAT_00fd94dc & 1) == 0) {
        _DAT_00fd94dc = _DAT_00fd94dc | 1;
        DAT_00fd94e0 = CMessengerMgr::vftable;
        DAT_00fdf38c = 0;
        DAT_00fdf390 = 0;
        _DAT_00fdf394 = 0;
        DAT_00fdf39c = 0;
        DAT_00fdf3a0 = 0;
        _DAT_00fdf3a4 = 0;
        DAT_00fdf3ac = 0;
        DAT_00fdf3b0 = 0;
        DAT_00fdf3b4 = 0;
        _DAT_00fdf3b8 = 0;
        FUN_004f1220();
        _atexit((_func_4879 *)&LAB_00bce260);
      }
      if ((local_c < (uint)(DAT_00fdf3b4 - DAT_00fdf3b0 >> 2)) &&
         (piVar2 = *(int **)(DAT_00fdf3b0 + local_c * 4), piVar2 != (int *)0x0)) {
        iVar1 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
        iVar3 = piVar2[2];
        if ((iVar1 == 0) ||
           ((((int)local_c < 0 ||
             (*(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2 <= (int)local_c)) ||
            (iVar7 = *(int *)(*(int *)(iVar1 + 0xa8) + local_c * 4), iVar7 == 0)))) {
          iVar7 = 0;
        }
        else {
          *(int *)(iVar7 + 0x20) = iVar3;
          uVar8 = iVar3 + 1;
          if (uVar8 <= *(uint *)(iVar1 + 0xe4)) {
            uVar8 = *(uint *)(iVar1 + 0xe4);
          }
          *(uint *)(iVar1 + 0xe4) = uVar8;
        }
        FUN_0063e770(iVar7);
        if (*piVar2 != 0) {
          bVar6 = true;
        }
      }
      local_c = local_c + 1;
    } while (local_c < uVar10);
  }
  uVar11 = CONCAT31((int3)(iVar9 >> 10),!bVar6);
  (**(code **)(**(int **)(param_1 + 0xf0) + 0x94))(uVar11);
  (**(code **)(**(int **)(param_1 + 0xf4) + 0x94))(uVar11);
  (**(code **)(**(int **)(param_1 + 0xf8) + 0x94))(uVar11);
  piVar2 = *(int **)(param_1 + 0xfc);
  puVar4 = (undefined4 *)piVar2[0x19];
  for (puVar5 = (undefined4 *)*puVar4; puVar5 != puVar4; puVar5 = (undefined4 *)*puVar5) {
    iVar1 = puVar5[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar2 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  return;
}

