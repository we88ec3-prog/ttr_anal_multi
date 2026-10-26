
void FUN_00594610(undefined4 param_1,char param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  undefined4 in_EDX;
  undefined1 auStack_74 [4];
  undefined4 local_70;
  undefined4 *local_68;
  undefined4 *local_64;
  undefined4 local_60;
  undefined4 *local_58;
  undefined4 *local_54;
  undefined4 local_50;
  undefined4 *local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00927000;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff80;
  ExceptionList = &local_14;
  local_70 = param_1;
  local_48 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_c = 0;
  FUN_006d4dc0();
  FUN_00402160(&DAT_00bed1fc,0);
  if (in_ECX == 0x18) {
    local_58 = (undefined4 *)0x0;
    local_54 = (undefined4 *)0x0;
    local_50 = 0;
    local_68 = (undefined4 *)0x0;
    local_64 = (undefined4 *)0x0;
    local_60 = 0;
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_006d4dc0(0xd,2,uVar2);
    if (local_58 != local_54) {
      if (param_2 == '\0') {
        FUN_00594570(*local_58);
      }
      else {
        FUN_00594a80(*local_58);
      }
    }
    FUN_004041f0(&local_38,0,0xffffffff);
    FUN_006d4dc0(0xe,2);
    if (local_68 != local_64) {
      if (param_2 == '\0') {
        FUN_00594570(*local_68);
      }
      else {
        FUN_00594a80(*local_68);
      }
    }
    puVar1 = local_68;
    FUN_004041f0(&local_38,0,0xffffffff);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0089120c(puVar1);
    }
    if (local_58 != (undefined4 *)0x0) {
      FUN_0089120c(local_58);
    }
  }
  else if (in_ECX == 0x19) {
    local_58 = (undefined4 *)0x0;
    local_54 = (undefined4 *)0x0;
    local_50 = 0;
    local_68 = (undefined4 *)0x0;
    local_64 = (undefined4 *)0x0;
    local_60 = 0;
    local_24 = 7;
    local_28 = 0;
    local_38 = (uint)local_38._2_2_ << 0x10;
    local_c = CONCAT31(local_c._1_3_,6);
    FUN_006d4dc0(0xe,2,uVar2);
    if (local_58 != local_54) {
      if (param_2 == '\0') {
        FUN_00594570(*local_58);
      }
      else {
        FUN_00594a80(*local_58);
      }
    }
    FUN_004041f0(&local_38,0,0xffffffff);
    FUN_006d4dc0(0xf,2);
    if (local_68 != local_64) {
      if (param_2 == '\0') {
        FUN_00594570(*local_68);
      }
      else {
        FUN_00594a80(*local_68);
      }
    }
    puVar1 = local_68;
    FUN_004041f0(&local_38,0,0xffffffff);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0089120c(puVar1);
    }
    if (local_58 != (undefined4 *)0x0) {
      FUN_0089120c(local_58);
    }
  }
  else if (in_ECX == 0x1a) {
    local_58 = (undefined4 *)0x0;
    local_54 = (undefined4 *)0x0;
    local_50 = 0;
    local_68 = (undefined4 *)0x0;
    local_64 = (undefined4 *)0x0;
    local_60 = 0;
    local_24 = 7;
    local_28 = 0;
    local_38 = (uint)local_38._2_2_ << 0x10;
    local_c = CONCAT31(local_c._1_3_,9);
    FUN_006d4dc0(0xd,2,uVar2);
    if (local_58 != local_54) {
      if (param_2 == '\0') {
        FUN_00594570(*local_58);
      }
      else {
        FUN_00594a80(*local_58);
      }
    }
    FUN_004041f0(&local_38,0,0xffffffff);
    FUN_006d4dc0(0xf,2);
    if (local_68 != local_64) {
      if (param_2 == '\0') {
        FUN_00594570(*local_68);
      }
      else {
        FUN_00594a80(*local_68);
      }
    }
    puVar1 = local_68;
    FUN_004041f0(&local_38,0,0xffffffff);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0089120c(puVar1);
    }
    if (local_58 != (undefined4 *)0x0) {
      FUN_0089120c(local_58);
    }
  }
  else if (local_48 == local_44) {
    FUN_0041f490(in_EDX);
  }
  else if (param_2 == '\0') {
    FUN_00594570(*local_48);
  }
  else {
    FUN_00594a80(*local_48);
  }
  if (local_48 != (undefined4 *)0x0) {
    FUN_0089120c(local_48);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

