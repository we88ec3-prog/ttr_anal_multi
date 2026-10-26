
void FUN_00438b50(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined1 *local_e8;
  uint uStack_e4;
  undefined1 local_e0 [16];
  undefined1 local_d0 [72];
  undefined **appuStack_88 [18];
  uint uStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  uint uStack_24;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009202b3;
  local_14 = ExceptionList;
  local_e8 = local_e0;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)local_e0);
  uStack_e4 = DAT_00d61f20 ^ (uint)local_e0;
  ExceptionList = &local_14;
  FUN_00432890();
  local_c = 0;
  local_e8 = (undefined1 *)*param_1;
  FUN_00438d90(local_d0);
  uVar1 = FUN_00431020();
  local_14 = (void *)CONCAT31(local_14._1_3_,1);
  FUN_004041f0(uVar1,0,0xffffffff);
  if (7 < uStack_2c) {
    FUN_0089120c(uStack_40);
  }
  uStack_40 = uStack_40 & 0xffff0000;
  uStack_2c = 7;
  uStack_30 = 0;
  local_14 = (void *)0xffffffff;
  FUN_00431040();
  appuStack_88[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)appuStack_88);
  ExceptionList = local_1c;
  __security_check_cookie(uStack_24 ^ (uint)&local_e8);
  return;
}

