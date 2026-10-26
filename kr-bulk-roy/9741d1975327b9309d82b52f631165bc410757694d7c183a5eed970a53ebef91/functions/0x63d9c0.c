
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063d9c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint local_c;
  
  if ((_DAT_00fd94dc & 1) == 0) {
    _DAT_00fd94dc = _DAT_00fd94dc | 1;
    FUN_004f10f0();
    _atexit((_func_4879 *)&LAB_00bce260);
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  uVar8 = DAT_00fdf3a0 - DAT_00fdf39c >> 2;
  if (iVar1 != 0) {
    FUN_00408920(iVar1,uVar8);
  }
  local_c = 0;
  if (uVar8 != 0) {
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
      if ((local_c < (uint)(DAT_00fdf3a0 - DAT_00fdf39c >> 2)) &&
         (iVar1 = *(int *)(DAT_00fdf39c + local_c * 4), iVar1 != 0)) {
        iVar2 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
        iVar1 = *(int *)(iVar1 + 4);
        if ((iVar2 != 0) &&
           (((-1 < (int)local_c &&
             ((int)local_c < *(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2)) &&
            (iVar3 = *(int *)(*(int *)(iVar2 + 0xa8) + local_c * 4), iVar3 != 0)))) {
          *(int *)(iVar3 + 0x20) = iVar1;
          uVar7 = iVar1 + 1;
          if (uVar7 <= *(uint *)(iVar2 + 0xe4)) {
            uVar7 = *(uint *)(iVar2 + 0xe4);
          }
          *(uint *)(iVar2 + 0xe4) = uVar7;
        }
        FUN_00757710();
      }
      local_c = local_c + 1;
    } while (local_c < uVar8);
  }
  piVar4 = *(int **)(param_1 + 0xec);
  puVar5 = (undefined4 *)piVar4[0x19];
  for (puVar6 = (undefined4 *)*puVar5; puVar6 != puVar5; puVar6 = (undefined4 *)*puVar6) {
    iVar1 = puVar6[2];
    if ((*(int *)(iVar1 + 0x60) != 0) && ((*(int **)(iVar1 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar1 + 0x1c) + 0x30))(iVar1);
    }
  }
  (**(code **)(*piVar4 + 0x128))();
  (**(code **)(**(int **)(param_1 + 0xec) + 200))();
  return;
}

