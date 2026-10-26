
void FUN_00459470(void)

{
  int *local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_50;
  uint local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00931788;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_78 = 0xffffffff;
  local_74 = 0xffffffff;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0xffffffff;
  local_64 = 0xffffffff;
  local_4c = 7;
  local_50 = 0;
  local_60 = local_60 & 0xffff0000;
  local_44 = 0xffffffff;
  local_40 = 0xffffffff;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0xffffffff;
  local_2c = 0xffffffff;
  local_28 = 0xffffffff;
  local_c = 0;
  FUN_0045d560(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  local_c = 0xffffffff;
  if (7 < local_4c) {
    FUN_0089120c(local_60);
  }
  FUN_005d7240(0xffffffff,0xffffffff,0,0);
  (**(code **)(*local_7c + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

