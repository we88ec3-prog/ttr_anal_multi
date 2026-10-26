
void FUN_007769a0(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  short *in_ECX;
  undefined4 local_68 [5];
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009208c8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  psVar3 = in_ECX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_14 = uVar2;
  FUN_00402160(in_ECX,(int)psVar3 - (int)(in_ECX + 1) >> 1);
  local_8 = 0;
  FUN_00633110(local_30,local_4c,L"SetCode",uVar2);
  local_8._0_1_ = 1;
  FUN_00764810(param_1);
  uVar4 = FUN_00633110(local_68,local_4c,L"ItemCode");
  local_8._0_1_ = 2;
  FUN_00402800(uVar4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_54) {
    FUN_0089120c(local_68[0]);
  }
  FUN_00764810(param_1);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

