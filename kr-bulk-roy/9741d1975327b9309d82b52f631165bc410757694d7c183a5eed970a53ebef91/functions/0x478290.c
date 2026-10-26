
void FUN_00478290(undefined1 param_1,char param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 local_68;
  undefined4 local_58;
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
  
  puStack_c = &LAB_009412a0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if (param_3 == '\0') {
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_54 = 7;
    local_58 = 0;
    local_68 = (uint)local_68._2_2_ << 0x10;
    local_8._0_1_ = 7;
    local_8._1_3_ = 0;
    FUN_00478fb0(in_ECX,param_1,param_2);
    uVar3 = FUN_00478a50(local_30,param_1,param_2);
    local_8._0_1_ = 8;
    FUN_00402800(uVar3);
    local_8._0_1_ = 7;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    FUN_004787b0(param_2 + '\x01');
    uVar3 = FUN_00478a50(local_30,param_1,param_2 + '\x01');
    local_8._0_1_ = 9;
    FUN_00402800(uVar3);
    local_8._0_1_ = 7;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_30[0] = local_30[0] & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    FUN_004026e0(local_4c,0,0xffffffff);
    iVar1 = in_ECX[0x58];
    local_8._0_1_ = 10;
    FUN_007578f0();
    FUN_00759ed0(iVar1 + 0xe8,local_30,0x7b,0x7d);
    local_8._0_1_ = 7;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    (**(code **)(*(int *)in_ECX[0x58] + 200))();
    local_30[0] = local_30[0] & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    FUN_004026e0(&local_68,0,0xffffffff);
    iVar1 = in_ECX[0x5c];
    local_8._0_1_ = 0xb;
    FUN_007578f0();
    FUN_00759ed0(iVar1 + 0xe8,local_30,0x7b,0x7d);
    local_8 = CONCAT31(local_8._1_3_,7);
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_30[0] = local_30[0] & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    (**(code **)(*(int *)in_ECX[0x5c] + 200))();
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
    local_8 = 0xffffffff;
    local_54 = 7;
    local_58 = 0;
    local_68 = local_68 & 0xffff0000;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
  }
  else {
    local_54 = 7;
    local_58 = 0;
    local_68 = (uint)local_68._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00479230(param_2);
    uVar3 = FUN_00479470(local_4c,param_2);
    local_8._0_1_ = 2;
    FUN_00402800(uVar3);
    local_8._0_1_ = 1;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0],uVar2);
    }
    FUN_004788b0(param_2 + '\x01');
    uVar3 = FUN_00479470(local_4c,param_2 + '\x01');
    local_8._0_1_ = 3;
    FUN_00402800(uVar3);
    local_8._0_1_ = 1;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    FUN_004026e0(&local_68,0,0xffffffff);
    iVar1 = in_ECX[0x58];
    local_8._0_1_ = 4;
    FUN_007578f0();
    FUN_00759ed0(iVar1 + 0xe8,local_4c,0x7b,0x7d);
    local_8._0_1_ = 1;
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    (**(code **)(*(int *)in_ECX[0x58] + 200))();
    local_4c[0] = local_4c[0] & 0xffff0000;
    local_38 = 7;
    local_3c = 0;
    FUN_004026e0(local_30,0,0xffffffff);
    iVar1 = in_ECX[0x5c];
    local_8._0_1_ = 5;
    FUN_007578f0();
    FUN_00759ed0(iVar1 + 0xe8,local_4c,0x7b,0x7d);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    (**(code **)(*(int *)in_ECX[0x5c] + 200))();
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    local_8 = 0xffffffff;
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
  }
  (**(code **)(*in_ECX + 0x188))();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

