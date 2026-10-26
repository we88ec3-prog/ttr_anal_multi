
void FUN_0046f8d0(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b984;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar3;
  if (s___AVCOnScreenKeyBoardDialog_FUI__00f7d370[0x22] == '\0') {
    __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
    return;
  }
  ExceptionList = &local_10;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
  }
  local_8 = 0xffffffff;
  local_38 = 0x193;
  FUN_005740f0(&local_38);
  if (local_34 != DAT_00fe5b10) {
    psVar5 = (short *)(local_34 + 0x10);
    if (7 < *(uint *)(local_34 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    local_8 = 1;
    if ((DAT_00fc0d94 & 1) == 0) {
      DAT_00fc0d94 = DAT_00fc0d94 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_0046fa20(uVar3);
      _atexit(FUN_00bcd950);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_0046fac0(&local_30);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
                    /* WARNING: Subroutine does not return */
    _exit(0);
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

