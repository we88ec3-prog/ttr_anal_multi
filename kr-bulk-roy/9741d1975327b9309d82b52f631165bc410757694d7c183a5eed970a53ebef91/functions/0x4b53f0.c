
void FUN_004b53f0(int param_1,uint param_2)

{
  short sVar1;
  code *pcVar2;
  undefined4 uVar3;
  short *psVar4;
  uint uVar5;
  short *psVar6;
  undefined2 local_b4 [8];
  undefined4 local_a4;
  undefined2 *local_a0;
  undefined2 local_98 [8];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_64 [4];
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00930a9e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_004054c0();
    uStack_7c = 0;
    local_60 = (undefined1 *)local_98;
    local_a0 = (undefined2 *)0x4b545a;
    FUN_00402250();
    local_c = 0;
    local_a0 = (undefined2 *)0x4b546c;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x4b5473;
    uVar3 = FUN_00585330();
    local_5c = (undefined1 *)local_b4;
    FUN_00402250(uVar3);
    break;
  case 1:
    FUN_004054c0();
    uStack_7c = 0;
    local_60 = (undefined1 *)local_98;
    local_a0 = (undefined2 *)0x4b54a3;
    FUN_00402250();
    local_c = 1;
    local_a0 = (undefined2 *)0x4b54b5;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x4b54bc;
    uVar3 = FUN_00585330();
    local_5c = (undefined1 *)local_b4;
    FUN_00402250(uVar3);
    break;
  case 2:
    FUN_004054c0();
    uStack_7c = 0;
    local_60 = (undefined1 *)local_98;
    local_a0 = (undefined2 *)0x4b54ec;
    FUN_00402250();
    local_c = 2;
    local_a0 = (undefined2 *)0x4b54fe;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x4b5505;
    uVar3 = FUN_00585330();
    local_5c = (undefined1 *)local_b4;
    FUN_00402250(uVar3);
    break;
  case 3:
    FUN_004054c0();
    uStack_7c = 0;
    local_60 = (undefined1 *)local_98;
    local_a0 = (undefined2 *)0x4b5535;
    FUN_00402250();
    local_c = 3;
    local_a0 = (undefined2 *)0x4b5547;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x4b554e;
    uVar3 = FUN_00585330();
    local_5c = (undefined1 *)local_b4;
    FUN_00402250(uVar3);
    break;
  case 4:
  case 6:
    if (param_2 < 3) {
      uVar5 = 0;
    }
    else {
      uVar5 = param_2 - 3 >> 2;
    }
    uStack_7c = 0x4b55cb;
    FUN_00402250();
    local_c._0_1_ = 5;
    local_c._1_3_ = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c._0_1_ = 6;
        FUN_004f3d80();
        uStack_7c = 0x4b5604;
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c._0_1_ = 5;
      }
      uStack_7c = 0x4b5619;
      FUN_004f6a30();
      uStack_80 = FUN_004ed610();
      uStack_7c = 0;
      local_c._0_1_ = 7;
      local_84 = 0x4b563c;
      FUN_004041f0();
      local_c._0_1_ = 5;
      if (7 < local_40) {
        uStack_7c = 0x4b5652;
        FUN_0089120c();
      }
      local_40 = 7;
      local_44 = 0;
      local_54 = local_54 & 0xffff0000;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c._0_1_ = 8;
      FUN_00587480();
      uStack_7c = 0x4b569a;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c._0_1_ = 5;
    }
    uStack_7c = 0;
    local_58 = (undefined1 *)local_98;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x4b56cd;
    FUN_00402160();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 10;
      local_a0 = (undefined2 *)0x4b570b;
      FUN_00584c40();
      local_a0 = (undefined2 *)0x4b5715;
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 9;
    local_5c = (undefined1 *)0x51;
    local_a0 = (undefined2 *)0x4b573a;
    FUN_005740f0();
    if (local_60 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    local_60 = (undefined1 *)local_b4;
    FUN_004ed610();
    local_c = CONCAT31(local_c._1_3_,5);
    FUN_0058b270(0xca);
    if (7 < local_24) {
      uStack_7c = 0x4b5791;
      FUN_0089120c();
    }
    goto LAB_004b58be;
  case 5:
    FUN_004054c0();
    uStack_7c = 0;
    local_60 = (undefined1 *)local_98;
    local_a0 = (undefined2 *)0x4b557e;
    FUN_00402250();
    local_c = 4;
    local_a0 = (undefined2 *)0x4b5590;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x4b5597;
    uVar3 = FUN_00585330();
    local_5c = (undefined1 *)local_b4;
    FUN_00402250(uVar3);
    break;
  default:
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0xb;
      FUN_00587480();
      uStack_7c = 0x4b57c0;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    uStack_7c = 0;
    local_58 = (undefined1 *)local_98;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x4b57f7;
    FUN_00402160();
    local_c = 0xc;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 0xd;
      local_c._1_3_ = 0;
      local_a0 = (undefined2 *)0x4b5825;
      FUN_00584c40();
      local_a0 = (undefined2 *)0x4b582f;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,0xc);
    }
    local_60 = (undefined1 *)0x52;
    local_a0 = (undefined2 *)0x4b5854;
    FUN_005740f0();
    if (local_5c == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_5c + 0x10);
    if (7 < *(uint *)(local_5c + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_60 = (undefined1 *)local_b4;
    local_a0 = (undefined2 *)0x7;
    local_a4 = 0;
    local_b4[0] = 0;
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
  }
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004b58be:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

