
void FUN_00464310(undefined2 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_e0 [16];
  undefined1 local_d0 [80];
  undefined **local_80 [19];
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920133;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_00432890(local_e0);
  local_8 = 0;
  FUN_004644f0(local_d0,*param_1,uVar1);
  uVar2 = FUN_00431020();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004041f0(uVar2,0,0xffffffff);
  if (7 < local_20) {
    FUN_0089120c(local_34);
  }
  local_20 = 7;
  local_24 = 0;
  local_34 = local_34 & 0xffff0000;
  local_8 = 0xffffffff;
  FUN_00431040();
  local_80[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)local_80);
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

