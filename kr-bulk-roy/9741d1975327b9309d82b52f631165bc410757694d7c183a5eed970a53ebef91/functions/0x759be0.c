
/* WARNING: Removing unreachable block (ram,0x00759d3e) */

void FUN_00759be0(float param_1)

{
  short sVar1;
  short *psVar2;
  undefined4 in_ECX;
  undefined4 local_150;
  undefined4 local_140;
  uint local_13c;
  undefined4 local_134;
  undefined4 local_124;
  uint local_120;
  short local_118;
  undefined1 local_116 [254];
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919231;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_005d0d60(L" %0.1f",(double)param_1,local_18);
  psVar2 = &local_118;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(&local_118,(int)psVar2 - (int)local_116 >> 1);
  FUN_00759d70();
  local_13c = 7;
  local_140 = 0;
  local_150 = (uint)local_150._2_2_ << 0x10;
  FUN_00402160(&DAT_00bfb894,1);
  local_8._0_1_ = 1;
  local_134 = (uint)local_134._2_2_ << 0x10;
  local_120 = 7;
  local_124 = 0;
  FUN_00402160(&DAT_00c059b8,2);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00759330(in_ECX,&local_134,&local_150);
  if (7 < local_120) {
    FUN_0089120c();
  }
  local_120 = 7;
  local_124 = 0;
  local_134 = local_134 & 0xffff0000;
  if (7 < local_13c) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

