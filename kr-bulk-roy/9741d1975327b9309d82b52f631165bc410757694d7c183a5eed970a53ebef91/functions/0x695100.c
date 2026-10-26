
void FUN_00695100(int param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint3 uVar8;
  undefined4 in_ECX;
  short *psVar9;
  ushort *puVar10;
  ushort uVar11;
  bool bVar12;
  undefined2 local_90 [2];
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 *local_80;
  short *local_7c;
  undefined1 *local_64 [2];
  int *local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00935b38;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)local_64;
  ExceptionList = &local_14;
  uVar3 = DAT_00fab22c & 1;
  *(undefined4 *)(param_1 + 0x2a0) = in_ECX;
  if (uVar3 == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    local_7c = (short *)0x69516d;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  piVar4 = (int *)FUN_004dfb60();
  local_5c = piVar4;
  if (piVar4 != (int *)0x0) {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 1;
      FUN_004f3d80();
      local_7c = (short *)0x6951b9;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
    local_7c = (short *)0x6951cf;
    local_7c = (short *)FUN_004f6a30();
    local_54 = (ushort *)((uint)local_54._2_2_ << 0x10);
    local_40 = 7;
    local_44 = 0;
    psVar9 = local_7c;
    do {
      sVar1 = *psVar9;
      psVar9 = psVar9 + 1;
    } while (sVar1 != 0);
    local_80 = (undefined4 *)0x69520a;
    FUN_00402160();
    local_c = 2;
    if (*(uint *)(param_1 + 0x28c) < 8) {
      puVar10 = (ushort *)(param_1 + 0x278);
    }
    else {
      puVar10 = *(ushort **)(param_1 + 0x278);
    }
    puVar5 = local_54;
    if (local_40 < 8) {
      puVar5 = (ushort *)&local_54;
    }
    do {
      uVar11 = *puVar5;
      bVar12 = uVar11 < *puVar10;
      if (uVar11 != *puVar10) {
LAB_00695266:
        iVar6 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
        goto LAB_0069526b;
      }
      if (uVar11 == 0) break;
      uVar11 = puVar5[1];
      bVar12 = uVar11 < puVar10[1];
      if (uVar11 != puVar10[1]) goto LAB_00695266;
      puVar5 = puVar5 + 2;
      puVar10 = puVar10 + 2;
    } while (uVar11 != 0);
    iVar6 = 0;
LAB_0069526b:
    if ((iVar6 != 0) || (piVar4[0xf5] != *(int *)(param_1 + 0x298))) {
      local_64[0] = (undefined1 *)local_90;
      local_7c = (short *)0x7;
      local_80 = (undefined4 *)0x0;
      local_90[0] = 0;
      FUN_004026e0(&local_54,0,0xffffffff);
      FUN_004183b0(L"Lv.{0=##} {1}",piVar4[0xf5]);
      local_c._0_1_ = 3;
      local_7c = (short *)0x6952d9;
      FUN_00757800();
      local_c = CONCAT31(local_c._1_3_,2);
      if (7 < local_24) {
        local_7c = (short *)0x6952ef;
        FUN_0089120c();
      }
      (**(code **)(**(int **)(param_1 + 0x268) + 200))();
      local_7c = (short *)0x0;
      local_80 = &local_54;
      uStack_84 = 0x695316;
      FUN_004026e0();
      *(int *)(param_1 + 0x298) = local_5c[0xf5];
      piVar4 = local_5c;
    }
    uVar11 = *(ushort *)(piVar4 + 0x22);
    local_64[0] = (undefined1 *)(uint)uVar11;
    if (uVar11 != *(ushort *)(param_1 + 0x294)) {
      if ((DAT_00f94394 & 1) == 0) {
        DAT_00f94394 = DAT_00f94394 | 1;
        local_c._0_1_ = 4;
        FUN_005c3de0();
        local_7c = (short *)0x695364;
        _atexit((_func_4879 *)&LAB_00bccc30);
        local_c = CONCAT31(local_c._1_3_,2);
      }
      iVar6 = *(int *)(param_1 + 0x264);
      uStack_58 = *(undefined4 *)(&DAT_00f94414 + (uint)uVar11 * 4);
      if (((*(char *)(iVar6 + 0xa4) != '\0') && (*(int *)(iVar6 + 0x94) != 0)) &&
         (iVar6 = (**(code **)(**(int **)(iVar6 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
        FUN_0077b200();
        uVar11 = (ushort)local_64[0];
      }
      (**(code **)(**(int **)(param_1 + 0x264) + 200))();
      *(ushort *)(param_1 + 0x294) = uVar11;
    }
    piVar4 = local_5c;
    iVar6 = (**(code **)(*local_5c + 0x70))();
    if (*(int *)(param_1 + 0x29c) != iVar6) {
      iVar6 = (**(code **)(*piVar4 + 0x70))();
      local_64[0] = (undefined1 *)((float)iVar6 / 100.0);
      pcVar2 = *(code **)(**(int **)(param_1 + 0x26c) + 0x128);
      (*(int **)(param_1 + 0x26c))[0x34] = (int)local_64[0];
      (*pcVar2)();
      (**(code **)(**(int **)(param_1 + 0x26c) + 200))();
      uVar7 = (**(code **)(*piVar4 + 0x70))();
      *(undefined4 *)(param_1 + 0x29c) = uVar7;
    }
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c._0_1_ = 5;
      FUN_004dec90();
      local_7c = (short *)0x69545d;
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    local_7c = (short *)0x695480;
    FUN_008438c0();
    if (local_64[0] == DAT_00fab14c) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(local_64[0] + 0x10);
    }
    local_7c = (short *)0x6954a1;
    uVar7 = (**(code **)(**(int **)(param_1 + 600) + 0x94))();
    uVar8 = (uint3)((uint)uVar7 >> 8);
    if ((iVar6 == 0) || (*(char *)(iVar6 + 0x29) == '\0')) {
      local_7c = (short *)((uint)uVar8 << 8);
    }
    else {
      local_7c = (short *)CONCAT31(uVar8,1);
    }
    local_80 = (undefined4 *)0x6954d3;
    uVar7 = (**(code **)(**(int **)(param_1 + 0x25c) + 0x94))();
    uVar8 = (uint3)((uint)uVar7 >> 8);
    if (((iVar6 == 0) || (*(char *)(iVar6 + 0x28) == '\0')) || (*(char *)(iVar6 + 0x29) != '\0')) {
      local_80 = (undefined4 *)((uint)uVar8 << 8);
    }
    else {
      local_80 = (undefined4 *)CONCAT31(uVar8,1);
    }
    uStack_84 = 0x6954fa;
    (**(code **)(**(int **)(param_1 + 0x260) + 0x94))();
    uStack_84 = 1;
    uStack_88 = 0x69550c;
    (**(code **)(**(int **)(param_1 + 0x248) + 0x94))();
    uStack_88 = 0;
    uStack_8c = 0x695520;
    (**(code **)(**(int **)(param_1 + 0x24c) + 0x94))();
    if (7 < local_40) {
      local_7c = (short *)0x695531;
      FUN_0089120c();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)local_64);
  return;
}

