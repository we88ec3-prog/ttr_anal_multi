
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063c410(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_c;
  
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  uVar9 = DAT_00fdf390 - DAT_00fdf38c >> 2;
  if (iVar2 != 0) {
    FUN_00408920(iVar2,uVar9);
  }
  local_c = 0;
  if (uVar9 != 0) {
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
      if ((local_c < (uint)(DAT_00fdf390 - DAT_00fdf38c >> 2)) &&
         (iVar2 = *(int *)(DAT_00fdf38c + local_c * 4), iVar2 != 0)) {
        iVar3 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
        iVar2 = *(int *)(iVar2 + 8);
        if ((iVar3 == 0) ||
           ((((int)local_c < 0 ||
             (*(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2 <= (int)local_c)) ||
            (iVar8 = *(int *)(*(int *)(iVar3 + 0xa8) + local_c * 4), iVar8 == 0)))) {
          iVar8 = 0;
        }
        else {
          uVar1 = iVar2 + 1;
          *(int *)(iVar8 + 0x20) = iVar2;
          uVar7 = *(uint *)(iVar3 + 0xe4);
          if (*(uint *)(iVar3 + 0xe4) < uVar1) {
            uVar7 = uVar1;
          }
          *(uint *)(iVar3 + 0xe4) = uVar7;
        }
        FUN_0063be80(iVar8);
      }
      local_c = local_c + 1;
    } while (local_c < uVar9);
  }
  piVar4 = *(int **)(param_1 + 0xec);
  puVar5 = (undefined4 *)piVar4[0x19];
  for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    iVar2 = puVar6[2];
    if ((*(int *)(iVar2 + 0x60) != 0) && ((*(int **)(iVar2 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x30))(iVar2);
    }
  }
  (**(code **)(*piVar4 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

