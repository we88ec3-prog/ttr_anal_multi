
void FUN_004e4c50(int param_1)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  short *psVar8;
  undefined4 *local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d58;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = *(int *)(param_1 + 2);
  if (iVar6 == 1) {
    piVar3 = (int *)FUN_0041e5c0();
    iVar6 = *piVar3;
    uVar4 = piVar3[1] - iVar6 >> 6;
    uVar7 = 0;
    if (uVar4 != 0) {
      piVar3 = (int *)(iVar6 + 0x3c);
      do {
        if (*piVar3 == 9) {
          local_58 = (undefined4 *)(uVar7 * 0x40 + iVar6);
          if (7 < (uint)local_58[5]) {
            local_58 = (undefined4 *)*local_58;
          }
          goto LAB_004e4cba;
        }
        uVar7 = uVar7 + 1;
        piVar3 = piVar3 + 0x10;
      } while (uVar7 < uVar4);
    }
    local_58 = (undefined4 *)&DAT_00bed1fc;
LAB_004e4cba:
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 0xffffffff;
    }
    local_54 = 0x57;
    FUN_005740f0(&local_54);
    if (local_50 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar8 = (short *)(local_50 + 0x10);
    if (7 < *(uint *)(local_50 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_4c = (uint)local_4c._2_2_ << 0x10;
    local_38 = 7;
    local_3c = 0;
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
    local_8 = 1;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_004d6b30(&local_4c);
    local_8 = 0xffffffff;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 3;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = 0xffffffff;
    }
    FUN_004d5ae0(&DAT_00fb11e8,0,local_58);
  }
  else if (iVar6 == 2) {
    local_50 = 0xe8;
    iVar6 = FUN_005854b0(local_14);
    FUN_005740f0(&local_50);
    if (local_54 == *(int *)(iVar6 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar8 = (short *)(local_54 + 0x10);
    if (7 < *(uint *)(local_54 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
    local_8 = 4;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 5;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,4);
    }
    FUN_004d6b30(&local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  else if (iVar6 == 0) {
    if ((((*(uint *)(param_1 + 6) < 10) &&
         (iVar6 = *(uint *)(param_1 + 6) * 0x210 + *(int *)(in_ECX + 0x6924),
         *(int *)(iVar6 + 0x5c) != 0)) && (iVar6 != 0)) && (iVar6 != -500)) {
      FUN_0081a860(*(undefined1 *)(param_1 + 10));
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

