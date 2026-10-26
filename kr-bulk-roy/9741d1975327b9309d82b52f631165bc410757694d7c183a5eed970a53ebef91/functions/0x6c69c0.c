
void FUN_006c69c0(char param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  short *psVar5;
  undefined4 local_48;
  int local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_2c;
  uint local_28;
  char local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009123b6;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = 7;
  local_2c = 0;
  local_3c = local_3c & 0xffff0000;
  local_1c = 0xffffffff;
  local_8 = 0;
  local_40 = 1;
  local_20 = param_1;
  local_18 = uVar3;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_48 = 0x2b;
  FUN_005740f0(&local_48);
  if (local_44 != DAT_00fe5ac8) {
    if (*(uint *)(local_44 + 0x24) < 8) {
      psVar5 = (short *)(local_44 + 0x10);
    }
    else {
      psVar5 = *(short **)(local_44 + 0x10);
    }
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    if (param_1 == '\0') {
      local_1c = 0xff808080;
    }
    FUN_006c8840(uVar3);
    if (7 < local_28) {
      FUN_0089120c(local_3c);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

