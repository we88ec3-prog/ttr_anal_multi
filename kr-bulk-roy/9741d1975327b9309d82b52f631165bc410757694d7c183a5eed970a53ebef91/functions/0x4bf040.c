
void FUN_004bf040(undefined1 *param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  int iVar4;
  undefined1 auStack_b4 [16];
  undefined4 uStack_a4;
  short *psStack_a0;
  undefined2 local_98 [8];
  undefined4 local_88;
  undefined4 local_84;
  int *piStack_80;
  short *psStack_7c;
  undefined1 auStack_68 [4];
  int local_64;
  int local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093077e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_68;
  ExceptionList = &local_14;
  local_5c = param_1;
  if (param_1[2] == '\0') {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 0;
      FUN_004f3d80();
      psStack_7c = (short *)0x4bf0b3;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_c = 1;
      psStack_7c = (short *)0x4bf0db;
      FUN_00584c40();
      psStack_7c = (short *)0x4bf0e5;
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_c = 0xffffffff;
    local_64 = 0x29;
    psStack_7c = (short *)0x4bf10b;
    FUN_005740f0();
    if (local_60 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psStack_7c = (short *)0x4bf138;
    FUN_004f6a30();
    psStack_7c = (short *)FUN_004ed610();
    local_c = 2;
    if (7 < *(uint *)(psStack_7c + 10)) {
      psStack_7c = *(short **)psStack_7c;
    }
    local_54 = (uint)local_54._2_2_ << 0x10;
    local_40 = 7;
    local_44 = 0;
    psVar3 = psStack_7c;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    piStack_80 = (int *)0x4bf18f;
    FUN_00402160();
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 4;
      FUN_004d4d10();
      psStack_7c = (short *)0x4bf1b8;
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_c = CONCAT31(local_c._1_3_,3);
    psStack_7c = (short *)0x4bf1cf;
    FUN_004d6b30();
    if (7 < local_40) {
      psStack_7c = (short *)0x4bf1e4;
      FUN_0089120c();
    }
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    if (7 < local_24) {
      psStack_7c = (short *)0x4bf212;
      FUN_0089120c();
    }
  }
  else if (param_1[2] == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 5;
      FUN_00587480();
      psStack_7c = (short *)0x4bf248;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    psStack_7c = (short *)0x0;
    local_60 = 0x196;
    piStack_80 = (int *)0x4bf264;
    iVar4 = FUN_005854b0();
    piStack_80 = &local_60;
    local_84 = 0x4bf276;
    FUN_005740f0();
    if (local_64 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psStack_a0 = (short *)(local_64 + 0x10);
    if (7 < *(uint *)(local_64 + 0x24)) {
      psStack_a0 = *(short **)psStack_a0;
    }
    local_58 = (undefined1 *)local_98;
    local_84 = 7;
    local_88 = 0;
    local_98[0] = 0;
    psVar3 = psStack_a0;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    uStack_a4 = 0x4bf2cb;
    FUN_00402160();
    local_c = 6;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c._0_1_ = 7;
      local_c._1_3_ = 0;
      FUN_004f3d80();
      psStack_a0 = (short *)0x4bf2fd;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_c = CONCAT31(local_c._1_3_,6);
    }
    local_60 = 0x55;
    iVar4 = FUN_005854b0();
    psStack_a0 = (short *)0x4bf327;
    FUN_005740f0();
    if (local_64 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psStack_a0 = (short *)0x4bf35a;
    FUN_004f6a30();
    local_5c = auStack_b4;
    FUN_004ed610();
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_68);
  return;
}

