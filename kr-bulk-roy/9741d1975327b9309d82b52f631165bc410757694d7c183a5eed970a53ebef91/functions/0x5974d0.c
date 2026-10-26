
void FUN_005974d0(int param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  short *psVar6;
  undefined4 *puVar7;
  int iVar8;
  short *psVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f8f2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_3c = param_1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_c = 0xffffffff;
  local_44 = 0x1bb;
  FUN_005740f0(&local_44);
  if (local_40 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar9 = (short *)(local_40 + 0x10);
  if (7 < *(uint *)(local_40 + 0x24)) {
    psVar9 = *(short **)psVar9;
  }
  local_38 = (undefined4 *)((uint)local_38._2_2_ << 0x10);
  local_24 = 7;
  local_28 = 0;
  psVar6 = psVar9;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar9,(int)psVar6 - (int)(psVar9 + 1) >> 1);
  local_c = 1;
  uVar11 = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 2;
    local_c._1_3_ = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  switch(DAT_00f9392c) {
  case 2:
    if (param_2 == 0x2af9) {
      uVar11 = 2;
      uVar12 = 0x24;
      goto LAB_00597610;
    }
LAB_0059766f:
    uVar12 = 0x1bb;
    uVar11 = 0;
    FUN_005854b0(0x1bb);
    FUN_00585330(uVar12);
    goto LAB_00597621;
  case 3:
  case 4:
  case 5:
  case 8:
  case 9:
  case 0xb:
  case 0x1b:
  case 0x1c:
    if (param_2 == 0x2af9) {
      uVar12 = 0x22;
      uVar11 = 2;
      FUN_005854b0(0x22);
      psVar6 = (short *)FUN_00585330(uVar12);
      psVar9 = psVar6;
      do {
        sVar1 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar6,(int)psVar9 - (int)(psVar6 + 1) >> 1);
    }
    else {
      uVar12 = 0x1bb;
      uVar11 = 0;
      FUN_005854b0(0x1bb);
      psVar6 = (short *)FUN_00585330(uVar12);
      psVar9 = psVar6;
      do {
        sVar1 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar6,(int)psVar9 - (int)(psVar6 + 1) >> 1);
    }
    break;
  case 6:
    FUN_004fa440();
    goto LAB_00597874;
  case 7:
  case 0x15:
  case 0x17:
  case 0x18:
    if (param_2 != 0x2af9) goto LAB_0059766f;
    uVar11 = 1;
    uVar12 = 0x23;
LAB_00597610:
    FUN_005854b0(uVar12);
    FUN_00585330(uVar12);
LAB_00597621:
    FUN_0041f490(&local_38);
  }
  if (*(int *)(local_3c + 0x130) == 0) {
    puVar5 = (undefined4 *)FUN_00891268(0x18);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf43ff;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
      puVar5[5] = uVar11;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    local_40 = 0x196;
    FUN_005740f0(&local_40);
    iVar3 = local_3c;
    if (local_44 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (undefined4 *)(local_44 + 0x10);
    if (7 < *(uint *)(local_44 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    puVar10 = local_38;
    if (local_24 < 8) {
      puVar10 = &local_38;
    }
    uVar11 = FUN_00404b10(0xcf,puVar10,puVar7,puVar5,local_3c);
    *(undefined4 *)(iVar3 + 0x130) = uVar11;
  }
  else if ((*(uint *)(*(int *)(local_3c + 0x130) + 0x28) >> 8 & 1) == 0) {
    puVar5 = (undefined4 *)FUN_00891268(0x18);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      puVar5[5] = uVar11;
      puVar5[1] = 0xffffffff;
      puVar5[2] = 0xffffffff;
      puVar5[3] = 0;
      puVar5[4] = 0xf43ff;
      *puVar5 = FoxUI::FXUIEventI1::vftable;
    }
    local_40 = 0x196;
    iVar8 = FUN_005854b0();
    FUN_005740f0(&local_40);
    iVar3 = local_3c;
    if (local_44 == *(int *)(iVar8 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (undefined4 *)(local_44 + 0x10);
    if (7 < *(uint *)(local_44 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    puVar10 = local_38;
    if (local_24 < 8) {
      puVar10 = &local_38;
    }
    uVar11 = FUN_00404b10(0xcf,puVar10,puVar7,puVar5,local_3c);
    *(undefined4 *)(iVar3 + 0x130) = uVar11;
  }
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
LAB_00597874:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

