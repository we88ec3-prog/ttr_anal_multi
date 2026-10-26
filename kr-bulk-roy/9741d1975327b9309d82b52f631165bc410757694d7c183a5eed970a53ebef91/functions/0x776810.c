
void FUN_00776810(void)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  undefined4 uVar4;
  short *in_ECX;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c [5];
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920918;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_68[0] = local_68[0] & 0xffff0000;
  local_54 = 7;
  local_58 = 0;
  psVar3 = in_ECX;
  do {
    sVar1 = *psVar3;
    psVar3 = psVar3 + 1;
  } while (sVar1 != 0);
  local_14 = uVar2;
  FUN_00402160(in_ECX,(int)psVar3 - (int)(in_ECX + 1) >> 1);
  local_8 = 0;
  FUN_00633110(local_30,local_68,L"SetCode",uVar2);
  local_8._0_1_ = 1;
  uVar4 = FUN_00764d80(local_4c,&DAT_00bed1fc);
  local_8._0_1_ = 2;
  FUN_00402800(uVar4);
  local_8._0_1_ = 1;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  uVar4 = FUN_00633110(local_4c,local_68,L"ItemCode");
  local_8._0_1_ = 3;
  FUN_00402800(uVar4);
  local_8._0_1_ = 1;
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  uVar4 = FUN_00764d80(local_4c,&DAT_00bed1fc);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_00402800(uVar4);
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  if (7 < local_54) {
    FUN_0089120c(local_68[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

