
void FUN_0081a910(int param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x5c) == 0) {
    iVar4 = FUN_00891268(0x5c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_0081b660();
    }
    *(undefined4 *)(param_1 + 0x5c) = uVar5;
  }
  FUN_0081b720();
  local_14 = 0;
  puVar10 = DAT_00fb11b0;
  if (*(int *)(param_1 + 0x6c) - *(int *)(param_1 + 0x68) >> 3 != 0) {
    do {
      puVar1 = (uint *)(*(int *)(param_1 + 0x68) + local_14 * 8);
      if ((DAT_00fb11a8 & 1) == 0) {
        DAT_00fb11a8 = DAT_00fb11a8 | 1;
        local_8 = 0;
        FUN_00813890();
        _atexit((_func_4879 *)&LAB_00bccec0);
        local_8 = 0xffffffff;
        puVar10 = DAT_00fb11b0;
      }
      uVar11 = *puVar1;
      cVar2 = *(char *)((int)puVar10[1] + 0x15);
      puVar6 = (undefined4 *)puVar10[1];
      local_18 = puVar10;
      while (puVar8 = puVar6, cVar2 == '\0') {
        if ((uint)puVar8[3] < uVar11) {
          puVar6 = (undefined4 *)puVar8[2];
          puVar8 = local_18;
        }
        else {
          puVar6 = (undefined4 *)*puVar8;
        }
        cVar2 = *(char *)((int)puVar6 + 0x15);
        local_18 = puVar8;
      }
      if ((local_18 == puVar10) || (uVar11 < (uint)local_18[3])) {
        local_1c = puVar10;
        ppuVar7 = &local_1c;
      }
      else {
        ppuVar7 = &local_18;
      }
      if ((*ppuVar7 != puVar10) && (iVar4 = (*ppuVar7)[4], iVar4 != 0)) {
        uVar11 = 0;
        while ((uVar9 = (uint)(byte)puVar1[1], puVar10 = DAT_00fb11b0,
               uVar9 < (uint)(*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 0x14) >> 2) &&
               (iVar3 = *(int *)(*(int *)(iVar4 + 0x14) + uVar9 * 4),
               uVar11 < (uint)(*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x14) >> 2)))) {
          if (uVar11 < (uint)(*(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x14) >> 2)) {
            FUN_0081b7f0(*(undefined4 *)(param_1 + 0x5c));
            uVar11 = uVar11 + 1;
          }
          else {
            FUN_0081b7f0(*(undefined4 *)(param_1 + 0x5c));
            uVar11 = uVar11 + 1;
          }
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(*(int *)(param_1 + 0x6c) - *(int *)(param_1 + 0x68) >> 3));
  }
  ExceptionList = local_10;
  return;
}

