
void FUN_00478d80(undefined1 param_1,undefined1 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int *in_ECX;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_68;
  uint local_64;
  undefined4 local_58;
  uint local_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 local_38 [5];
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00944fc0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  local_7c = CONCAT31(local_7c._1_3_,param_2);
  uVar2 = local_7c;
  local_58 = CONCAT31(local_58._1_3_,param_1);
  uVar3 = local_58;
  if (param_3 == '\0') {
    FUN_00478fb0(in_ECX,local_58,local_7c);
    FUN_00478a50(local_54,uVar3,uVar2);
    local_c = 2;
    local_64 = 7;
    local_68 = 0;
    local_78 = (uint)local_78._2_2_ << 0x10;
    FUN_004026e0(local_54,0,0xffffffff);
    iVar1 = in_ECX[0x58];
    local_c._0_1_ = 3;
    FUN_007578f0();
    FUN_00759ed0(iVar1 + 0xe8,&local_78,0x7b,0x7d);
    local_c = CONCAT31(local_c._1_3_,2);
    if (7 < local_64) {
      FUN_0089120c(local_78);
    }
    local_78 = local_78 & 0xffff0000;
    local_64 = 7;
    local_68 = 0;
    (**(code **)(*(int *)in_ECX[0x58] + 200))();
    local_c = 0xffffffff;
    if (7 < uStack_40) {
      FUN_0089120c(local_54[0]);
    }
    uStack_40 = 7;
    uStack_44 = 0;
    local_54[0] = local_54[0] & 0xffff0000;
  }
  else {
    FUN_00479230(local_7c);
    FUN_00479470(local_38,uVar2);
    local_c = 0;
    local_78 = (uint)local_78._2_2_ << 0x10;
    local_64 = 7;
    local_68 = 0;
    FUN_004026e0(local_38,0,0xffffffff);
    iVar1 = in_ECX[0x58];
    local_c._0_1_ = 1;
    FUN_007578f0(uVar4);
    FUN_00759ed0(iVar1 + 0xe8,&local_78,0x7b,0x7d);
    local_c = (uint)local_c._1_3_ << 8;
    if (7 < local_64) {
      FUN_0089120c(local_78);
    }
    (**(code **)(*(int *)in_ECX[0x58] + 200))();
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(local_38[0]);
    }
  }
  (**(code **)(*in_ECX + 0x188))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

