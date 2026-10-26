
void FUN_00653190(float param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *unaff_EDI;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b840;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  fVar3 = (float10)100.0;
  fVar4 = (float10)param_1 * fVar3;
  fVar5 = (float10)(float)fVar4;
  iVar1 = FUN_008fed10(local_14);
  unaff_EDI[0x38] = iVar1 + 1;
  if (extraout_ST1 < fVar5) {
    unaff_EDI[0x39] =
         (int)(float)(fVar3 * (float10)(float)(extraout_ST1 - extraout_ST0 * (float10)iVar1));
  }
  else {
    unaff_EDI[0x38] = iVar1;
    unaff_EDI[0x39] = (int)(float)fVar4;
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_8 = 0;
  FUN_00404300(&DAT_00c32ae4,1);
  uVar2 = FUN_0040ef80();
  local_8._0_1_ = 1;
  FUN_004041f0(uVar2,0,0xffffffff);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  FUN_00757800(&local_30);
  (**(code **)(*(int *)unaff_EDI[0x4a] + 200))();
  (**(code **)(*unaff_EDI + 0x128))();
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

