
/* WARNING: Removing unreachable block (ram,0x005ba7ae) */
/* WARNING: Removing unreachable block (ram,0x005ba87e) */

void FUN_005ba510(void)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  int *in_ECX;
  int local_54;
  int local_50;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093359e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX == (int *)0x0) {
LAB_005ba569:
    in_ECX = (int *)0x0;
  }
  else {
    iVar4 = (**(code **)(*in_ECX + 4))();
    if (iVar4 != 0x105bf) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_005ba569;
    }
  }
  iVar4 = in_ECX[6];
  local_8 = 0;
  local_8._1_3_ = 0;
  if (in_ECX[7] == 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 1;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    local_50 = 0x60;
    FUN_005740f0();
    if (local_54 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(uint *)(local_54 + 0x24) < 8) {
      psVar5 = (short *)(local_54 + 0x10);
    }
    else {
      psVar5 = *(short **)(local_54 + 0x10);
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  else {
    if (in_ECX[7] != 1) goto LAB_005ba699;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    FUN_005740f0();
    if (local_50 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(uint *)(local_50 + 0x24) < 8) {
      psVar5 = (short *)(local_50 + 0x10);
    }
    else {
      psVar5 = *(short **)(local_50 + 0x10);
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160();
LAB_005ba699:
  local_1c = 7;
  local_20 = 0;
  local_30 = (undefined4 *)((uint)local_30._2_2_ << 0x10);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8._0_1_ = 4;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8._0_1_ = 3;
  FUN_008438c0();
  if (local_50 == DAT_00fb7574) {
    local_20 = 0;
    puVar6 = local_30;
    if (local_1c < 8) {
      puVar6 = &local_30;
    }
    *(undefined2 *)puVar6 = 0;
  }
  else {
    FUN_004026e0();
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8._0_1_ = 5;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8._0_1_ = 3;
  }
  puVar6 = (undefined4 *)FUN_00891268();
  if (puVar6 != (undefined4 *)0x0) {
    iVar2 = in_ECX[5];
    puVar6[1] = 0xffffffff;
    puVar6[2] = 0xffffffff;
    puVar6[3] = 0;
    puVar6[4] = 0xf440d;
    *puVar6 = FoxUI::FXUIEventI1::vftable;
    puVar6[5] = iVar2;
  }
  FUN_00402160();
  puVar6 = local_30;
  if (local_1c < 8) {
    puVar6 = &local_30;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 7;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
  }
  local_8._0_1_ = 6;
  FUN_005740f0();
  if (iVar4 == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  FUN_00498ef0(puVar6);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_0058b270(0xcf);
  if (7 < local_1c) {
    FUN_0089120c();
  }
  local_30 = (undefined4 *)((uint)local_30 & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

