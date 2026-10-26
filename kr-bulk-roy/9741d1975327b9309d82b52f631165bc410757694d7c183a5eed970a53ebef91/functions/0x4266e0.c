
void FUN_004266e0(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 auStack_12c [6];
  undefined4 uStack_120;
  uint *puStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined2 local_110 [4];
  undefined4 uStack_108;
  undefined1 auStack_e4 [4];
  undefined1 *local_e0;
  int local_dc;
  int local_d8;
  byte *local_d4;
  undefined1 *puStack_d0;
  undefined4 uStack_cc;
  uint uStack_b4;
  undefined1 local_a4;
  undefined4 local_a0;
  uint local_9c [4];
  undefined4 local_8c;
  uint local_88;
  int local_80;
  int iStack_7c;
  undefined4 uStack_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093442e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_e4;
  ExceptionList = &local_14;
  local_e0 = (undefined1 *)0x0;
  local_dc = param_1;
  if ((DAT_00fb7324 & 1) == 0) {
    DAT_00fb7324 = DAT_00fb7324 | 1;
    local_c = 0;
    FUN_0081b920();
    _atexit((_func_4879 *)&LAB_00bcd080);
  }
  local_c = 0xffffffff;
  local_d8 = FUN_0081bb00();
  if (local_d8 != 0) {
    puVar2 = (undefined1 *)FUN_00426d40();
    local_a4 = *puVar2;
    local_a0 = *(undefined4 *)(puVar2 + 4);
    local_88 = 7;
    local_8c = 0;
    local_9c[0] = local_9c[0] & 0xffff0000;
    FUN_004026e0();
    local_c = 1;
    FUN_004fcd00();
    local_c = 2;
    if (*(uint *)(local_d8 + 0x28) < 2) {
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
      FUN_00402160();
      local_c = 4;
      local_e0 = (undefined1 *)0x2;
    }
    else {
      FUN_004ed610();
      local_c = CONCAT31(local_c._1_3_,3);
      local_e0 = (undefined1 *)0x1;
    }
    local_70 = (uint)local_70._2_2_ << 0x10;
    local_5c = 7;
    local_60 = 0;
    FUN_00402800();
    local_c = 5;
    if (((uint)local_e0 & 2) != 0) {
      local_e0 = (undefined1 *)((uint)local_e0 & 0xfffffffd);
      if (7 < local_40) {
        FUN_0089120c();
      }
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
    }
    local_c._0_1_ = 7;
    if (((uint)local_e0 & 1) != 0) {
      if (7 < local_24) {
        FUN_0089120c();
      }
      local_24 = 7;
      local_28 = 0;
      local_38 = local_38 & 0xffff0000;
    }
    local_e0 = (undefined1 *)local_110;
    uStack_114 = 0xffffffff;
    uStack_118 = 0;
    puStack_11c = &local_70;
    local_110[0] = 0;
    uStack_120 = 0x42692d;
    FUN_004026e0();
    puStack_d0 = (undefined1 *)auStack_12c;
    local_c._0_1_ = 8;
    uStack_118 = 7;
    puStack_11c = (uint *)0x0;
    auStack_12c[0] = 0;
    FUN_004026e0(local_d8 + 4,0,0xffffffff);
    local_c._0_1_ = 7;
    FUN_004213a0(L"{0}{1}");
    iVar3 = local_dc;
    local_c._0_1_ = 9;
    FUN_00757800();
    (**(code **)(**(int **)(iVar3 + 0xf8) + 200))();
    local_c = CONCAT31(local_c._1_3_,7);
    if (7 < uStack_b4) {
      FUN_0089120c();
    }
    puStack_d0 = (undefined1 *)local_110;
    uStack_114 = 0xffffffff;
    uStack_118 = 0;
    puStack_11c = local_9c;
    local_110[0] = 0;
    uStack_120 = 0x4269e5;
    FUN_004026e0();
    uStack_114 = 0x4269ec;
    FUN_004467e0();
    if (*(int *)(*(int *)(iVar3 + 0x108) + 0xcc) != 0) {
      FUN_00408920();
    }
    uVar4 = 0;
    if (iStack_7c - local_80 >> 3 != 0) {
      do {
        iVar3 = *(int *)(*(int *)(iVar3 + 0x108) + 0xcc);
        if ((((iVar3 != 0) && (-1 < (int)uVar4)) &&
            ((int)uVar4 < *(int *)(iVar3 + 0xac) - *(int *)(iVar3 + 0xa8) >> 2)) &&
           ((piVar1 = *(int **)(*(int *)(iVar3 + 0xa8) + uVar4 * 4), piVar1 != (int *)0x0 &&
            (iVar3 = (**(code **)(*piVar1 + 4))(), iVar3 != 0x12d)))) {
          uStack_108 = 0x426a93;
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
        }
        if ((uint)(iStack_7c - local_80 >> 3) <= uVar4) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d();
        }
        puStack_d0 = *(undefined1 **)(local_80 + uVar4 * 8);
        uStack_cc = *(undefined4 *)(local_80 + 4 + uVar4 * 8);
        FUN_00425e20();
        uVar4 = uVar4 + 1;
        iVar3 = local_dc;
      } while (uVar4 < (uint)(iStack_7c - local_80 >> 3));
    }
    FUN_00749920();
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_c._0_1_ = 10;
      FUN_005c3de0();
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_c = CONCAT31(local_c._1_3_,7);
    }
    if (DAT_00f947fc != 0) {
      local_d4 = (byte *)(uint)*local_d4;
      FUN_0082ef00();
    }
    FUN_00745060();
    (**(code **)(**(int **)(iVar3 + 0xf4) + 200))();
    if (7 < local_5c) {
      FUN_0089120c();
    }
    local_5c = 7;
    local_60 = 0;
    local_70 = local_70 & 0xffff0000;
    if (local_80 != 0) {
      FUN_0089120c();
    }
    local_80 = 0;
    iStack_7c = 0;
    uStack_78 = 0;
    if (7 < local_88) {
      FUN_0089120c();
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_e4);
  return;
}

