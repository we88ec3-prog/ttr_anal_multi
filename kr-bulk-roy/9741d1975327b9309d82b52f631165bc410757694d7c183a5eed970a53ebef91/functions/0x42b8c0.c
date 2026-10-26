
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b8c0(int param_1)

{
  ushort uVar1;
  short sVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort *puVar8;
  short *psVar9;
  short *psVar10;
  int iVar11;
  ushort *puVar12;
  undefined1 auStack_9c [7];
  byte bStack_95;
  ushort uStack_94;
  undefined1 uStack_92;
  undefined1 uStack_91;
  undefined1 uStack_90;
  undefined1 uStack_8f;
  byte bStack_8e;
  int local_8c;
  undefined4 uStack_88;
  int iStack_84;
  uint uStack_80;
  uint local_7c;
  uint uStack_78;
  uint uStack_74;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094570a;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffff58;
  ExceptionList = &local_14;
  uVar4 = DAT_00fb1378 & 1;
  local_8c = param_1;
  local_7c = 0xffffffff;
  *(float *)(param_1 + 0x118) = *(float *)(param_1 + 0x118) + 0.033333335;
  if (uVar4 == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(uVar7);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  piVar3 = *(int **)(param_1 + 0x104);
  if (DAT_00fb7258 == 0) {
    if (((uint)piVar3[10] >> 7 & 1) != 0) {
      (**(code **)(*piVar3 + 0x90))(0);
    }
  }
  else {
    local_7c = *(uint *)(DAT_00fb7258 + 0x24);
    if (((uint)piVar3[10] >> 7 & 1) == 0) {
      (**(code **)(*piVar3 + 0x90))(1);
    }
  }
  local_24 = 7;
  local_28 = 0;
  local_38 = (uint)local_38._2_2_ << 0x10;
  local_40 = 7;
  local_44 = 0;
  local_54 = (uint)local_54._2_2_ << 0x10;
  local_5c = 7;
  local_60 = 0;
  local_70 = (uint)local_70._2_2_ << 0x10;
  local_c._0_1_ = 3;
  local_c._1_3_ = 0;
  iVar11 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
  if (iVar11 == 0) {
    uStack_74 = 0xffffffff;
    uStack_80 = 0;
    iStack_84 = 0;
  }
  else {
    iVar11 = *(int *)(iVar11 + 0xdc);
    if (iVar11 == 0) {
      uStack_74 = 0xffffffff;
      uStack_80 = 0;
      iStack_84 = 0;
    }
    else {
      uStack_74 = *(uint *)(iVar11 + 0x20);
      uStack_80 = 0;
      iStack_84 = 0;
    }
  }
  do {
    uVar4 = uStack_80;
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c._0_1_ = 4;
      FUN_00539c20(uVar7);
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_c._0_1_ = 3;
    }
    if (uVar4 < (uint)((DAT_00fb723c - DAT_00fb7238) / 0x36)) {
      puVar12 = (ushort *)(DAT_00fb7238 + iStack_84);
    }
    else {
      puVar12 = (ushort *)0x0;
    }
    iVar11 = *(int *)(*(int *)(param_1 + 0x108) + 0xcc);
    if (((iVar11 == 0) || ((int)uVar4 < 0)) ||
       (*(int *)(iVar11 + 0xac) - *(int *)(iVar11 + 0xa8) >> 2 <= (int)uVar4)) {
      iVar11 = 0;
    }
    else {
      iVar11 = *(int *)(*(int *)(iVar11 + 0xa8) + uVar4 * 4);
    }
    bStack_95 = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    FUN_00402160(&DAT_00bed1fc,0);
    FUN_00402160(&DAT_00bed1fc,0);
    uStack_94 = 0xffff;
    uStack_92 = 0xff;
    uStack_91 = 0xff;
    uStack_78 = 0xffffffff;
    uStack_88 = 0xffffffff;
    if (puVar12 == (ushort *)0x0) {
      if ((uVar4 == uStack_74) && (*(int *)(*(int *)(local_8c + 0x108) + 0xcc) != 0)) {
        FUN_0042c8e0(0xffffffff);
      }
      *(uint *)(iVar11 + 0x28) = *(uint *)(iVar11 + 0x28) | 4;
    }
    else {
      puVar8 = puVar12 + 2;
      do {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
      } while (uVar1 != 0);
      FUN_00402160(puVar12 + 2,(int)puVar8 - (int)(puVar12 + 3) >> 1);
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c._0_1_ = 5;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c._0_1_ = 3;
      }
      psVar9 = (short *)FUN_004f6a30(*(undefined4 *)(puVar12 + 0x17));
      psVar10 = psVar9;
      do {
        sVar2 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar9,(int)psVar10 - (int)(psVar9 + 1) >> 1);
      psVar10 = (short *)(&PTR_DAT_00d6a218)[*(byte *)((int)puVar12 + 0x35)];
      psVar9 = psVar10;
      do {
        sVar2 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar10,(int)psVar9 - (int)(psVar10 + 1) >> 1);
      uStack_78 = (uint)*(byte *)((int)puVar12 + 0x33);
      uStack_94 = (ushort)(byte)puVar12[0x19];
      uStack_92 = 0;
      uStack_91 = 0;
      if (*puVar12 == local_7c) {
        uStack_88 = 0xffffcc00;
      }
      else if (((char)puVar12[0x1a] != '\0') || ((byte)puVar12[0x19] == uStack_78)) {
        uStack_88 = 0xff666666;
      }
      if ((*(uint *)(iVar11 + 0x28) & 4) != 0) {
        *(uint *)(iVar11 + 0x28) = *(uint *)(iVar11 + 0x28) ^ 4;
      }
    }
    FUN_0042b1c0(&bStack_95,&local_54,&uStack_94,&uStack_78,&uStack_88);
    uStack_80 = uStack_80 + 1;
    iStack_84 = iStack_84 + 0x36;
    param_1 = local_8c;
  } while (iStack_84 < 0x1e6);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c._0_1_ = 6;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c._0_1_ = 3;
  }
  iVar11 = DAT_00fb722c;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c._0_1_ = 7;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c._0_1_ = 3;
  }
  iVar6 = local_8c;
  iVar5 = DAT_00fb7230;
  if ((*(int *)(local_8c + 0x11c) != iVar11) || (*(int *)(local_8c + 0x120) != DAT_00fb7230)) {
    FUN_007597b0(0);
    FUN_007597b0(1);
    (**(code **)(**(int **)(iVar6 + 0x10c) + 200))();
    *(int *)(iVar6 + 0x11c) = iVar11;
    *(int *)(iVar6 + 0x120) = iVar5;
  }
  if (5.0 < *(float *)(iVar6 + 0x118)) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c._0_1_ = 8;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_c._0_1_ = 3;
    }
    iVar5 = local_8c;
    iVar11 = DAT_00fb722c;
    bStack_95 = (byte)(*(uint *)(*(int *)(local_8c + 0xf4) + 0x28) >> 9) & 1;
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c._0_1_ = 9;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_c._0_1_ = 3;
    }
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    uStack_94 = 0x52;
    uStack_92 = (undefined1)iVar11;
    uStack_91 = 9;
    uStack_90 = 5;
    uStack_8f = 0;
    bStack_8e = bStack_95;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_94,7);
    }
    *(undefined4 *)(iVar5 + 0x118) = 0;
  }
  if (7 < local_5c) {
    FUN_0089120c(local_70);
  }
  local_5c = 7;
  local_60 = 0;
  local_70 = local_70 & 0xffff0000;
  if (7 < local_40) {
    FUN_0089120c(local_54);
  }
  local_40 = 7;
  local_44 = 0;
  local_54 = local_54 & 0xffff0000;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

