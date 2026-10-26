
void FUN_0053b100(void)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  short *psVar4;
  undefined4 *in_ECX;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092f2ba;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(local_14);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
  }
  local_8 = 0xffffffff;
  local_54 = 0x1f;
  FUN_005740f0(&local_54);
  if (local_50 != DAT_00fe5aec) {
    FUN_004f6a30(*in_ECX);
    psVar3 = (short *)FUN_004ed610();
    local_8 = 2;
    if (7 < *(uint *)(psVar3 + 10)) {
      psVar3 = *(short **)psVar3;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar4 = psVar3;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 4;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004d6b30(&local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

