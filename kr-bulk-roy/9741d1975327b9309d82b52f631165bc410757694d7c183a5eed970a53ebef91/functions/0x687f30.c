
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00687f30(int param_1,uint ***param_2)

{
  uint ****ppppuVar1;
  short sVar2;
  code *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint **ppuVar8;
  undefined4 uVar9;
  int *piVar10;
  uint ***pppuVar11;
  uint ****ppppuVar12;
  uint ****ppppuStack_a4;
  uint uVar13;
  uint ****local_8c;
  uint ****local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  uint ***local_78;
  uint ***pppuStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  uint uStack_5c;
  uint uStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  uint uStack_34;
  void *pvStack_2c;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00945e06;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_8c;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xffffff68;
  ExceptionList = &local_14;
  local_8c = (uint ****)param_2;
  if (*(char *)(param_1 + 0x172) != '\0') {
    ppppuStack_a4 = (uint ****)0x687f85;
    uVar4 = FUN_006891e0();
    *(undefined1 *)(param_1 + 0x172) = uVar4;
  }
  if (*(int *)(*(int *)(param_1 + 0x164) + 0xcc) != 0) {
    ppppuStack_a4 = (uint ****)0x687fa1;
    FUN_006438f0();
  }
  local_7c = 0;
  if ((DAT_00fe30c0 & 1) == 0) {
    DAT_00fe30c0 = DAT_00fe30c0 | 1;
    local_c = 0;
    FUN_00830e90();
    ppppuStack_a4 = (uint ****)0x687fcb;
    _atexit((_func_4879 *)&LAB_00bd0070);
    local_c = 0xffffffff;
  }
  ppppuStack_a4 = (uint ****)local_8c[2];
  FUN_00831510();
  local_84 = *(undefined4 *)(*(int *)(param_1 + 300) + 0x248);
  local_80 = *(undefined4 *)(*(int *)(param_1 + 300) + 0x24c);
  local_78 = (uint ***)0x0;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_c = 1;
    FUN_004dd4a0();
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    ppppuStack_a4 = (uint ****)0x68804d;
    _atexit((_func_4879 *)&LAB_00bccdb0);
    local_c = 0xffffffff;
  }
  ppppuStack_a4 = (uint ****)&local_88;
  FUN_004dd400();
  if (((local_88 != (uint ****)DAT_00fab0e0) &&
      (ppuVar8 = (uint **)local_88[6], ppuVar8 != (uint **)0x0)) && (ppuVar8 != (uint **)0xffffffd8)
     ) {
    local_78 = (uint ***)ppuVar8[0xc];
  }
  if ((DAT_00fe30c0 & 1) == 0) {
    DAT_00fe30c0 = DAT_00fe30c0 | 1;
    local_c = 2;
    FUN_00830e90();
    ppppuStack_a4 = (uint ****)0x6880c0;
    _atexit((_func_4879 *)&LAB_00bd0070);
    local_c = 0xffffffff;
  }
  ppppuVar12 = local_8c;
  iVar6 = FUN_00831e00();
  if ((int)local_78 < iVar6) {
    ppppuStack_a4 = (uint ****)0x6880f7;
    FUN_0075cd30();
    uVar13 = 0;
    ppppuStack_a4 = (uint ****)0x688109;
    (**(code **)(**(int **)(param_1 + 0x14c) + 0x90))();
    ppppuStack_a4 = (uint ****)0x0;
    (**(code **)(**(int **)(param_1 + 0x150) + 0x90))();
    (**(code **)(**(int **)(param_1 + 0x154) + 0x90))();
    FUN_0075cd30();
    (**(code **)(**(int **)(param_1 + 0x158) + 0x90))();
    (**(code **)(**(int **)(param_1 + 0x15c) + 0x90))();
  }
  else {
    if ((int)local_78 < 0xf) {
      uVar13 = 1;
      ppppuStack_a4 = (uint ****)0x6881af;
      (**(code **)(**(int **)(param_1 + 0x14c) + 0x90))();
      ppppuStack_a4 = (uint ****)0x1;
      (**(code **)(**(int **)(param_1 + 0x150) + 0x90))();
    }
    else {
      ppppuStack_a4 = (uint ****)0x68817b;
      FUN_0075cd30();
      uVar13 = 0;
      ppppuStack_a4 = (uint ****)0x68818d;
      (**(code **)(**(int **)(param_1 + 0x14c) + 0x90))();
      ppppuStack_a4 = (uint ****)0x0;
      (**(code **)(**(int **)(param_1 + 0x150) + 0x90))();
    }
    (**(code **)(**(int **)(param_1 + 0x154) + 0x90))();
    (**(code **)(**(int **)(param_1 + 0x158) + 0x90))();
    (**(code **)(**(int **)(param_1 + 0x15c) + 0x90))();
  }
  (**(code **)(**(int **)(param_1 + 0x160) + 0x90))();
  (**(code **)(**(int **)(param_1 + 0x14c) + 200))();
  (**(code **)(**(int **)(param_1 + 0x150) + 200))();
  (**(code **)(**(int **)(param_1 + 0x154) + 200))();
  (**(code **)(**(int **)(param_1 + 0x158) + 200))();
  (**(code **)(**(int **)(param_1 + 0x15c) + 200))();
  (**(code **)(**(int **)(param_1 + 0x160) + 200))();
  iVar6 = *(int *)(param_1 + 0x14c);
  if (*(int *)(iVar6 + 0x24c) == 0) {
LAB_006882ae:
    if (*(int *)(iVar6 + 0x24c) != 0) {
      iVar7 = *(int *)(*(int *)(iVar6 + 0x24c) + 0xcc);
      if (iVar7 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(iVar7 + 0xdc);
      }
      if ((iVar7 != 0) && (*(int *)(iVar7 + 0x20) == 2)) {
        ppppuVar12[6] = (uint ***)0x3;
        goto LAB_00688308;
      }
    }
    if (*(int *)(iVar6 + 0x24c) == 0) {
LAB_00688302:
      ppuVar8 = (uint **)0xffffffff;
    }
    else {
      iVar6 = *(int *)(*(int *)(iVar6 + 0x24c) + 0xcc);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(iVar6 + 0xdc);
      }
      if (iVar6 == 0) goto LAB_00688302;
      ppuVar8 = *(uint ***)(iVar6 + 0x20);
    }
    ppppuVar12[6] = (uint ***)ppuVar8;
  }
  else {
    iVar7 = *(int *)(*(int *)(iVar6 + 0x24c) + 0xcc);
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(iVar7 + 0xdc);
    }
    if ((iVar7 == 0) || (*(int *)(iVar7 + 0x20) != 1)) goto LAB_006882ae;
    ppppuVar12[6] = (uint ***)0x2;
  }
LAB_00688308:
  iVar6 = *(int *)(*(int *)(param_1 + 0x158) + 0x24c);
  if (iVar6 == 0) {
LAB_00688335:
    ppuVar8 = (uint **)0xffffffff;
  }
  else {
    iVar6 = *(int *)(iVar6 + 0xcc);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
    }
    if (iVar6 == 0) goto LAB_00688335;
    ppuVar8 = *(uint ***)(iVar6 + 0x20);
  }
  ppppuVar12[7] = (uint ***)ppuVar8;
  iVar6 = *(int *)(*(int *)(param_1 + 0x158) + 0x24c);
  if (iVar6 == 0) {
LAB_00688468:
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_24 = 5;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_24 = 0xffffffff;
    }
    FUN_005740f0();
    if (uVar13 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    piVar10 = (int *)(uVar13 + 0x10);
    if (7 < *(uint *)(uVar13 + 0x24)) {
      piVar10 = (int *)*piVar10;
    }
    uStack_70 = (uint)uStack_70._2_2_ << 0x10;
    uStack_5c = 7;
    iStack_60 = 0;
    do {
      sVar2 = *(short *)piVar10;
      piVar10 = (int *)((int)piVar10 + 2);
    } while (sVar2 != 0);
    FUN_00402160();
    uStack_24 = 6;
    FUN_007578f0();
    FUN_00759ed0();
  }
  else {
    iVar6 = *(int *)(iVar6 + 0xcc);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
    }
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x20) != 0)) goto LAB_00688468;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      uStack_24 = 3;
      FUN_00584c40();
      _atexit((_func_4879 *)&LAB_00bcf390);
      uStack_24 = 0xffffffff;
    }
    uVar13 = 0x342;
    FUN_005740f0();
    if (uVar5 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    piVar10 = (int *)(uVar5 + 0x10);
    if (7 < *(uint *)(uVar5 + 0x24)) {
      piVar10 = (int *)*piVar10;
    }
    uStack_5c = 7;
    iStack_60 = 0;
    uStack_70 = (uint)uStack_70._2_2_ << 0x10;
    do {
      sVar2 = *(short *)piVar10;
      piVar10 = (int *)((int)piVar10 + 2);
    } while (sVar2 != 0);
    FUN_00402160();
    uStack_24 = 4;
    FUN_007578f0();
    FUN_00759ed0();
  }
  uStack_24 = 0xffffffff;
  if (7 < uStack_5c) {
    uStack_24 = 0xffffffff;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(param_1 + 0x16c) + 200))();
  if ((DAT_00fe3008 & 1) == 0) {
    DAT_00fe3008 = DAT_00fe3008 | 1;
    uStack_24 = 7;
    FUN_00513fa0();
    _atexit((_func_4879 *)&LAB_00bcff80);
  }
  uVar5 = FUN_00514ee0();
  uStack_70 = 0;
  uStack_6c = 0;
  uStack_68 = 0;
  uStack_64 = 0;
  iStack_60 = 0;
  local_8c = (uint ****)0x0;
  local_88 = (uint ****)0x0;
  local_84 = 0;
  uStack_24._1_3_ = 0;
  if ((DAT_00fe30c0 & 1) == 0) {
    DAT_00fe30c0 = DAT_00fe30c0 | 1;
    uStack_24._0_1_ = 9;
    uStack_24._1_3_ = 0;
    FUN_00830e90();
    _atexit((_func_4879 *)&LAB_00bd0070);
  }
  uStack_24._0_1_ = 8;
  FUN_008313c0();
  pppuStack_74 = (uint ***)0x0;
  local_7c = 0;
  local_78 = (uint ***)0x0;
  if (*(char *)(param_1 + 0x172) == '\0') {
    pppuStack_74 = ppppuStack_a4[0xb];
  }
  FUN_0052ef90();
  local_78 = ppppuStack_a4[9];
  local_7c = 1;
  pppuStack_74 = (uint ***)((*(char *)(param_1 + 0x172) != '\0') - 1 & uVar5);
  FUN_0052ef90();
  if ((DAT_00fe3008 & 1) == 0) {
    DAT_00fe3008 = DAT_00fe3008 | 1;
    uStack_24._0_1_ = 10;
    FUN_00513fa0();
    _atexit((_func_4879 *)&LAB_00bcff80);
    uStack_24._0_1_ = 8;
  }
  FUN_00515790();
  ppppuVar12 = local_8c;
  if ((uVar13 == DAT_00fe3014) || (uVar13 == 0xfffffff0)) goto joined_r0x00688713;
  if ((DAT_00fe30c0 & 1) == 0) {
    DAT_00fe30c0 = DAT_00fe30c0 | 1;
    uStack_24._0_1_ = 0xb;
    FUN_00830e90();
    _atexit((_func_4879 *)&LAB_00bd0070);
    uStack_24._0_1_ = 8;
  }
  FUN_00831b10();
  FUN_007597b0();
  (**(code **)(**(int **)(param_1 + 0x140) + 200))();
  if ((DAT_00fe30c0 & 1) == 0) {
    DAT_00fe30c0 = DAT_00fe30c0 | 1;
    uStack_24._0_1_ = 0xc;
    FUN_00830e90();
    _atexit((_func_4879 *)&LAB_00bd0070);
    uStack_24._0_1_ = 8;
  }
  if (iStack_60 == 0) {
    FUN_00757710();
  }
  else {
    iVar6 = *(int *)(*(int *)(param_1 + 0x14c) + 0x24c);
    if (iVar6 != 0) {
      iVar6 = *(int *)(iVar6 + 0xcc);
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(iVar6 + 0xdc);
      }
      if ((iVar6 != 0) && (*(int *)(iVar6 + 0x20) == 1)) {
        FUN_00585620();
        uVar9 = FUN_00585330();
        FUN_00402250(uVar9);
        FUN_00759e60();
        goto LAB_006888bd;
      }
    }
    iVar6 = FUN_0075cdd0();
    if (iVar6 == 2) {
      FUN_00585620();
      uVar9 = FUN_00585330();
      FUN_00402250(uVar9);
      FUN_00759e60();
    }
    else {
      FUN_00585620();
      uVar9 = FUN_00585330();
      FUN_00402250(uVar9);
      FUN_00759e60();
    }
  }
LAB_006888bd:
  (**(code **)(**(int **)(param_1 + 0x168) + 200))();
  if (local_8c != local_88) {
    ppppuVar12 = local_8c + 2;
    do {
      ppppuStack_a4 = ppppuVar12;
      if (ppppuVar12[-2] == (uint ***)0x0) {
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          uStack_24._0_1_ = 0xd;
          FUN_00584c40();
          _atexit((_func_4879 *)&LAB_00bcf390);
          uStack_24._0_1_ = 8;
        }
        FUN_005740f0();
        if (uVar13 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        FUN_00757710();
        FUN_00412df0();
        uStack_24._0_1_ = 0xe;
        FUN_00759ac0();
        uStack_24._0_1_ = 8;
        if (7 < uStack_3c) {
          FUN_0089120c();
        }
        uStack_50 = uStack_50 & 0xffff0000;
        uStack_3c = 7;
        uStack_40 = 0;
        (**(code **)(**(int **)(param_1 + 0x134) + 200))();
        ppppuStack_a4 = ppppuVar12;
      }
      else if (ppppuVar12[-2] == (uint ***)0x1) {
        if ((*(int *)(*(int *)(param_1 + 0x164) + 0xcc) == 0) ||
           (piVar10 = (int *)FUN_00412c70(), piVar10 == (int *)0x0)) {
LAB_00688949:
          piVar10 = (int *)0x0;
        }
        else {
          iVar6 = (**(code **)(*piVar10 + 4))();
          if (iVar6 != 0x12d) {
            MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
            goto LAB_00688949;
          }
        }
        FUN_00685810();
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          uStack_24._0_1_ = 0xf;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          uStack_24._0_1_ = 8;
        }
        if (DAT_00f94300 != -0x16f8) {
          FUN_00508e40();
        }
        FUN_007597b0();
        FUN_007597b0();
        (**(code **)(*(int *)piVar10[0x94] + 200))();
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          uStack_24._0_1_ = 0x10;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          uStack_24._0_1_ = 8;
        }
        ppppuVar12 = ppppuStack_a4;
        pppuVar11 = (uint ***)0x0;
        if (DAT_00f94300 != -0x16f8) {
          pppuVar11 = (uint ***)FUN_00508e40();
        }
        if (pppuVar11 < *ppppuVar12) {
          FUN_00685900();
        }
      }
      ppppuVar12 = ppppuStack_a4 + 3;
      ppppuVar1 = ppppuStack_a4 + 1;
      ppppuStack_a4 = ppppuVar12;
    } while (ppppuVar1 != local_88);
  }
  ppppuVar12 = local_8c;
  (**(code **)(**(int **)(param_1 + 0x138) + 0x90))();
  (**(code **)(**(int **)(param_1 + 0x138) + 200))();
  FUN_00749920();
  (**(code **)(**(int **)(param_1 + 0x164) + 200))();
joined_r0x00688713:
  if (ppppuVar12 != (uint ****)0x0) {
    FUN_0089120c();
  }
  ExceptionList = pvStack_2c;
  __security_check_cookie(uStack_34 ^ (uint)&ppppuStack_a4);
  return;
}

