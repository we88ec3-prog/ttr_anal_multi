
void FUN_004bf780(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  short *psVar9;
  short *psVar10;
  int iVar11;
  undefined1 auStack_84 [4];
  int *piStack_80;
  undefined4 *puStack_7c;
  int local_78;
  int local_74;
  undefined4 uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_54;
  uint uStack_40;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009408cb;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  ExceptionList = &local_14;
  local_78 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f9392c != *(byte *)(param_1 + 0xe)) {
    DAT_00f9392c = (uint)*(byte *)(param_1 + 0xe);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 1) {
      FUN_00544f50();
      goto LAB_004bf8dd;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  piVar4 = (int *)FUN_00891268(0xb4);
  local_c = 2;
  piStack_80 = piVar4;
  if (piVar4 == (int *)0x0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    FUN_00544c40(piVar4);
    *piVar4 = (int)CMissionRoomController::vftable;
    DAT_00fba7ac = 1;
    DAT_00fba7a4 = piVar4;
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bf8dd:
  if (iVar3 != 0) {
    (**(code **)(*DAT_00fba7a4 + 4))(iVar3);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 9;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar5 = (undefined4 *)FUN_00891268(0x14);
  puStack_7c = (undefined4 *)0x0;
  if (puVar5 != (undefined4 *)0x0) {
    puVar5[3] = 0;
    *puVar5 = FoxUI::FXUIEvent::vftable;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[4] = &DAT_000f4296;
    puStack_7c = puVar5;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 10;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  FUN_00804260(&puStack_7c);
  if (*(char *)(local_78 + 0xf) == '\0') {
    iVar3 = *(int *)(local_78 + 10);
    if (iVar3 == 0) {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0x11;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 0x12;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = 0xffffffff;
        }
      }
      piStack_80 = (int *)&DAT_0000002c;
      iVar11 = FUN_005855b0();
      FUN_005740f0(&piStack_80);
      iVar3 = local_78;
      if (puStack_7c == *(undefined4 **)(iVar11 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      FUN_004f6a30(*(undefined4 *)(local_78 + 6));
      uVar7 = FUN_004f6a30(*(undefined4 *)(iVar3 + 2));
      psVar9 = (short *)FUN_00498ef0(uVar7);
      local_c = 0x13;
      if (7 < *(uint *)(psVar9 + 10)) {
        psVar9 = *(short **)psVar9;
      }
      uStack_5c = 7;
      uStack_60 = 0;
      uStack_70 = (uint)uStack_70._2_2_ << 0x10;
      psVar10 = psVar9;
      do {
        sVar1 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar10 - (int)(psVar9 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 0x15;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c = CONCAT31(local_c._1_3_,0x14);
      FUN_004d6b30(&uStack_70);
      if (7 < uStack_5c) {
        FUN_0089120c(uStack_70);
      }
      uStack_5c = 7;
      uStack_60 = 0;
      uStack_70 = uStack_70 & 0xffff0000;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      *(undefined4 *)(local_74 + 0xbd5c) = 3;
    }
    else {
      iVar11 = *(int *)(local_78 + 2);
      if (iVar11 == iVar3) {
        iVar11 = *(int *)(local_78 + 6);
      }
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0xb;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0xc;
        FUN_004f3d80();
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 0xd;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = 0xffffffff;
        }
      }
      puStack_7c = (undefined4 *)0x2b;
      iVar6 = FUN_005855b0();
      FUN_005740f0(&puStack_7c);
      if (piStack_80 == *(int **)(iVar6 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      piStack_80 = (int *)FUN_004f6a30(iVar3);
      uVar7 = FUN_004f6a30(iVar11);
      uVar8 = FUN_004f6a30(iVar3);
      psVar9 = (short *)FUN_004bff30(uVar8,uVar7);
      local_c = 0xe;
      if (7 < *(uint *)(psVar9 + 10)) {
        psVar9 = *(short **)psVar9;
      }
      uStack_70 = (uint)uStack_70._2_2_ << 0x10;
      uStack_5c = 7;
      uStack_60 = 0;
      psVar10 = psVar9;
      do {
        sVar1 = *psVar10;
        psVar10 = psVar10 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar9,(int)psVar10 - (int)(psVar9 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 0x10;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c = CONCAT31(local_c._1_3_,0xf);
      FUN_004d6b30(&uStack_70);
      if (7 < uStack_5c) {
        FUN_0089120c(uStack_70);
      }
      local_c = 0xffffffff;
      uStack_5c = 7;
      uStack_60 = 0;
      uStack_70 = uStack_70 & 0xffff0000;
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
      iVar3 = FUN_00404ba0();
      iVar11 = *(int *)(iVar3 + 0x5f50);
      iVar3 = *(int *)(local_78 + 10);
      *(undefined4 *)(local_74 + 0xbd5c) = 1;
      *(uint *)(local_74 + 0xbd60) = (uint)(iVar11 == iVar3);
    }
  }
  else if (*(char *)(local_78 + 0xf) == '\x01') {
    piStack_80 = (int *)0x2d;
    iVar3 = FUN_005855b0();
    FUN_005740f0(&piStack_80);
    if (puStack_7c == *(undefined4 **)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar9 = (short *)(puStack_7c + 4);
    if (7 < (uint)puStack_7c[9]) {
      psVar9 = *(short **)psVar9;
    }
    uStack_38 = (uint)uStack_38._2_2_ << 0x10;
    uStack_24 = 7;
    uStack_28 = 0;
    psVar10 = psVar9;
    do {
      sVar1 = *psVar10;
      psVar10 = psVar10 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar9,(int)psVar10 - (int)(psVar9 + 1) >> 1);
    local_c = 0x16;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 0x17;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = CONCAT31(local_c._1_3_,0x16);
    }
    FUN_004d6b30(&uStack_38);
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

