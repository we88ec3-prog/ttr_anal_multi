
/* WARNING: Removing unreachable block (ram,0x006c698b) */

void FUN_006c68c0(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  short *psVar4;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00928a96;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_004f3d80(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  psVar3 = (short *)FUN_004f6a30(*(undefined4 *)(unaff_ESI + 0xb4));
  psVar4 = psVar3;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar3,(int)psVar4 - (int)(psVar3 + 1) >> 1);
  FUN_006c8840();
  FUN_006c8720();
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

