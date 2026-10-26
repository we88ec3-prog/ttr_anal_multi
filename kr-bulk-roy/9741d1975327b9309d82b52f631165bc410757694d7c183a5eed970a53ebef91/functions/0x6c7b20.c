
void FUN_006c7b20(void)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  undefined1 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00912376;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = 7;
  local_28 = 0;
  local_38 = local_38 & 0xffff0000;
  local_18 = 0xffffffff;
  local_8 = 0;
  local_3c = 0xe;
  local_1c = 1;
  local_14 = uVar3;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_44 = 0x2d;
  FUN_005740f0(&local_44);
  if (local_40 != DAT_00fe5ac8) {
    if (*(uint *)(local_40 + 0x24) < 8) {
      psVar5 = (short *)(local_40 + 0x10);
    }
    else {
      psVar5 = *(short **)(local_40 + 0x10);
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    FUN_006c8840(uVar3);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

