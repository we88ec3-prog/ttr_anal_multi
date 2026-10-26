
undefined4 FUN_00647ea0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined1 local_bc [16];
  undefined1 local_ac [80];
  undefined **local_5c [18];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f6d4;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_00432890(local_bc);
  local_8 = 1;
  FUN_00438d90(local_ac,param_2,uVar1);
  FUN_00431020();
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_00431040();
  local_5c[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)local_5c);
  ExceptionList = local_10;
  return param_1;
}

