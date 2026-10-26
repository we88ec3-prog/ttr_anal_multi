
void FUN_00508660(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  undefined4 ***pppuVar2;
  short *psVar3;
  short *psVar4;
  undefined4 in_EDX;
  int local_4c;
  undefined1 local_48 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 **local_38 [4];
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_00936734;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_4c;
  ExceptionList = &local_14;
  local_24 = 7;
  local_28 = 0;
  local_38[0] = (undefined4 **)((uint)local_38[0] & 0xffff0000);
  local_c = 0;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c._0_1_ = 1;
    local_c._1_3_ = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffa8);
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = (uint)local_c._1_3_ << 8;
  }
  FUN_008438c0(local_48);
  if ((local_4c != DAT_00fab14c) && (*(int *)(local_4c + 0x10) != 0)) {
    local_28 = 0;
    pppuVar2 = (undefined4 ***)local_38[0];
    if (local_24 < 8) {
      pppuVar2 = local_38;
    }
    *(undefined2 *)pppuVar2 = 0;
  }
  local_40 = param_1;
  local_3c = param_2;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_c._0_1_ = 2;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_c = (uint)local_c._1_3_ << 8;
  }
  psVar3 = (short *)FUN_004f6a30(in_EDX);
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  FUN_00508a20();
  if (7 < local_24) {
    FUN_0089120c(local_38[0]);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_4c);
  return;
}

