
void FUN_0058f260(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  uint local_6c [4];
  undefined4 local_5c;
  uint local_58;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091af38;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = FUN_005391e0(local_18);
  if (iVar1 != *(int *)(param_1 + 4)) {
    piVar2 = (int *)(iVar1 + 0xc);
    if (7 < *(uint *)(iVar1 + 0x20)) {
      piVar2 = (int *)*piVar2;
    }
    iVar3 = FUN_0044df20(0,piVar2,*(undefined4 *)(iVar1 + 0x1c));
    if (-1 < iVar3) goto LAB_0058f397;
  }
  local_58 = 7;
  local_5c = 0;
  local_6c[0] = local_6c[0] & 0xffff0000;
  local_8 = 0;
  local_3c = 7;
  local_50[0] = local_50[0] & 0xffff0000;
  local_40 = 0;
  FUN_004026e0(in_ECX,0,0xffffffff);
  local_8._0_1_ = 1;
  local_20 = 7;
  local_24 = 0;
  local_34 = (uint)local_34._2_2_ << 0x10;
  FUN_00402800(local_6c);
  local_8 = CONCAT31(local_8._1_3_,2);
  uVar4 = FUN_00590030(local_50);
  FUN_0058fa00(iVar1,uVar4);
  if (7 < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  if (7 < local_3c) {
    FUN_0089120c(local_50[0]);
  }
  local_3c = 7;
  local_40 = 0;
  local_50[0] = local_50[0] & 0xffff0000;
  if (7 < local_58) {
    FUN_0089120c(local_6c[0]);
  }
LAB_0058f397:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

