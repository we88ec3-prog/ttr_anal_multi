
void FUN_004ef210(int param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  short *psVar5;
  short *psVar6;
  undefined4 local_58;
  int local_54;
  int local_50;
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fa8a;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_50 = param_1;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  local_14 = uVar3;
  FUN_0040b310("MAIL_RECEIVE");
  local_8 = 0;
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_0080a3a0(uVar3);
    _atexit((_func_4879 *)&LAB_00bccdd0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  piVar4 = (int *)FUN_0080ab00(&DAT_00fab028);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x14))();
  }
  local_8 = 0xffffffff;
  if (0xf < local_38) {
    FUN_0089120c(local_4c);
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_8 = 2;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_8 = 0xffffffff;
  }
  local_58 = 0xb;
  FUN_005740f0(&local_58);
  if (local_54 != DAT_00fe5aec) {
    psVar6 = (short *)(local_54 + 0x10);
    if (7 < *(uint *)(local_54 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 3;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 4;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,3);
    }
    FUN_004d6b30(&local_30);
    if (local_1c < 8) {
      *(undefined1 *)(local_50 + 0x19) = 1;
    }
    else {
      FUN_0089120c(local_30);
      *(undefined1 *)(local_50 + 0x19) = 1;
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

