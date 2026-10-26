
void FUN_006c7160(int param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  short *psVar4;
  undefined1 auStack_54 [4];
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_24;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093be04;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  ExceptionList = &local_14;
  local_50 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f93930 != *(int *)(local_50 + 0xb4)) {
    local_2c = 7;
    local_30 = 0;
    local_40 = local_40 & 0xffff0000;
    local_20 = 0xffffffff;
    local_c = 1;
    local_44 = 7;
    local_24 = 1;
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    local_4c = 0x20;
    FUN_005740f0(&local_4c);
    if (local_48 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar4 = (short *)(local_48 + 0x10);
    if (7 < *(uint *)(local_48 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    psVar3 = psVar4;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar3 - (int)(psVar4 + 1) >> 1);
    FUN_006c8840();
    if (7 < local_2c) {
      FUN_0089120c(local_40);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_54);
  return;
}

