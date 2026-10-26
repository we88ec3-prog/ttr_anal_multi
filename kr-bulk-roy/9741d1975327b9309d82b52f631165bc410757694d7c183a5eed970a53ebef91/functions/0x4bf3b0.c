
void FUN_004bf3b0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puStack_5c;
  int local_58;
  undefined4 uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094098b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&puStack_5c;
  ExceptionList = &local_14;
  local_58 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f9392c != *(byte *)(param_1 + 10)) {
    DAT_00f9392c = (uint)*(byte *)(param_1 + 10);
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
    if (DAT_00fba7ac == 2) {
      FUN_00544f50();
      param_1 = local_58;
      goto LAB_004bf4e3;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  puStack_5c = (undefined4 *)FUN_00891268(0xc0);
  local_c = 3;
  if (puStack_5c == (undefined4 *)0x0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00548540(puStack_5c);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bf4e3:
  if (iVar3 != 0) {
    (**(code **)(*DAT_00fba7a4 + 4))(iVar3);
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c = 9;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = 0xffffffff;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 10;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = 0xffffffff;
    }
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 0xb;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_c = 0xffffffff;
  }
  local_58 = 0x2a;
  FUN_005740f0(&local_58);
  if (puStack_5c != DAT_00fe5aec) {
    FUN_004f6a30(*(undefined4 *)(param_1 + 6));
    uVar4 = FUN_004f6a30(*(undefined4 *)(param_1 + 2));
    psVar5 = (short *)FUN_00498ef0(uVar4);
    local_c = 0xc;
    if (7 < *(uint *)(psVar5 + 10)) {
      psVar5 = *(short **)psVar5;
    }
    uStack_40 = 7;
    uStack_44 = 0;
    uStack_54 = (uint)uStack_54._2_2_ << 0x10;
    psVar6 = psVar5;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 0xe;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_c = CONCAT31(local_c._1_3_,0xd);
    FUN_004d6b30(&uStack_54);
    if (7 < uStack_40) {
      FUN_0089120c(uStack_54);
    }
    local_c = 0xffffffff;
    uStack_40 = 7;
    uStack_44 = 0;
    uStack_54 = uStack_54 & 0xffff0000;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0xf;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_00891268(0x14);
    puVar8 = (undefined4 *)0x0;
    if (puVar7 != (undefined4 *)0x0) {
      puVar7[3] = 0;
      *puVar7 = FoxUI::FXUIEvent::vftable;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[4] = 0xf4295;
      puVar8 = puVar7;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 0x10;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    puStack_5c = puVar8;
    FUN_00804260(&puStack_5c);
    ExceptionList = local_14;
    __security_check_cookie(local_1c ^ (uint)&puStack_5c);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

