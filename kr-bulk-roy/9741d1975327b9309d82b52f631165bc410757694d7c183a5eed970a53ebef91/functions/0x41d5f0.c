
void FUN_0041d5f0(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *local_20;
  undefined4 *local_1c;
  uint local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910f8e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar7 = *param_1;
  uVar4 = param_1[1] - iVar7 >> 3;
  local_18 = 0;
  puVar9 = DAT_00fb11b0;
  if (uVar4 != 0) {
    do {
      uVar10 = local_18;
      if (local_18 < uVar4) {
        local_14 = (uint *)(iVar7 + local_18 * 8);
      }
      else {
        local_14 = (uint *)0x0;
      }
      if ((DAT_00fb11a8 & 1) == 0) {
        DAT_00fb11a8 = DAT_00fb11a8 | 1;
        local_8 = 0;
        FUN_00813890(uVar3);
        _atexit((_func_4879 *)&LAB_00bccec0);
        local_8 = 0xffffffff;
        puVar9 = DAT_00fb11b0;
      }
      cVar1 = *(char *)((int)puVar9[1] + 0x15);
      puVar5 = (undefined4 *)puVar9[1];
      local_1c = puVar9;
      while (puVar8 = puVar5, cVar1 == '\0') {
        if ((uint)puVar8[3] < *local_14) {
          puVar5 = (undefined4 *)puVar8[2];
          puVar8 = local_1c;
        }
        else {
          puVar5 = (undefined4 *)*puVar8;
        }
        cVar1 = *(char *)((int)puVar5 + 0x15);
        local_1c = puVar8;
      }
      if ((local_1c == puVar9) || (*local_14 < (uint)local_1c[3])) {
        local_20 = puVar9;
        ppuVar6 = &local_20;
      }
      else {
        ppuVar6 = &local_1c;
      }
      if ((*ppuVar6 != puVar9) && (iVar7 = (*ppuVar6)[4], iVar7 != 0)) {
        uVar4 = 0;
        while ((puVar9 = DAT_00fb11b0, uVar10 = local_18,
               (uint)(ushort)local_14[1] <
               (uint)(*(int *)(iVar7 + 0x18) - *(int *)(iVar7 + 0x14) >> 2) &&
               (iVar2 = *(int *)(*(int *)(iVar7 + 0x14) + (uint)(ushort)local_14[1] * 4),
               uVar4 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)))) {
          if (uVar4 < (uint)(*(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2)) {
            FUN_0081b7f0(param_2);
            uVar4 = uVar4 + 1;
          }
          else {
            FUN_0081b7f0(param_2);
            uVar4 = uVar4 + 1;
          }
        }
      }
      iVar7 = *param_1;
      local_18 = uVar10 + 1;
      uVar4 = param_1[1] - iVar7 >> 3;
    } while (local_18 < uVar4);
  }
  ExceptionList = local_10;
  return;
}

