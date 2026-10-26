
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d78f0(void)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  short *psVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  uint uVar6;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929c36;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar6 = uVar3;
  if ((_DAT_00fe69c8 & 1) == 0) {
    _DAT_00fe69c8 = _DAT_00fe69c8 | 1;
    DAT_00fe69c0 = 7;
    _DAT_00fe69bc = 0;
    DAT_00fe69ac._0_2_ = 0;
    _atexit((_func_4879 *)&LAB_00bcec80);
  }
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = 0xffffffff;
  }
  psVar4 = (short *)FUN_004f6a30(in_ECX);
  psVar1 = psVar4 + 1;
  do {
    sVar2 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar2 != 0);
  if ((int)psVar4 - (int)psVar1 >> 1 == 0) {
    FUN_00443d10();
  }
  uVar5 = FUN_004d8320();
  local_8 = 1;
  FUN_00402800(uVar5);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

