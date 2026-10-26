
void FUN_0045a210(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iStack_90;
  uint uStack_8c;
  undefined1 auStack_7c [4];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  void *local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931788;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  uStack_8c = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  iStack_90 = 0x1c;
  puVar3 = (undefined4 *)FUN_00891268();
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = param_1[0xad];
    iVar2 = param_1[0xac];
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf4369;
    *puVar3 = FoxUI::FXUIEventI2::vftable;
    puVar3[5] = iVar2;
    puVar3[6] = iVar1;
  }
  iStack_90 = 0x45a295;
  FUN_004072a0();
  local_78 = 0xffffffff;
  local_74 = 0xffffffff;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0xffffffff;
  local_64 = 0xffffffff;
  local_4c = 7;
  local_50 = 0;
  local_60 = (uint)local_60._2_2_ << 0x10;
  local_44 = 0xffffffff;
  local_40 = 0xffffffff;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0xffffffff;
  local_2c = 0xffffffff;
  local_28 = (void *)0xffffffff;
  local_c = 0;
  iStack_90 = 0x45a2f4;
  FUN_0045d560();
  local_c = 0xffffffff;
  if (7 < local_4c) {
    iStack_90 = local_60;
    FUN_0089120c();
  }
  iStack_90 = 0;
  (**(code **)(*param_1 + 0x1ac))(0xffffffff,0xffffffff,0,0);
  ExceptionList = local_28;
  __security_check_cookie(local_30 ^ (uint)&iStack_90);
  return;
}

