
undefined4 FUN_00453d70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int local_bc [4];
  int local_ac [2];
  uint auStack_a4 [18];
  undefined **local_5c [18];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f6d4;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  FUN_00432890(local_bc);
  local_8 = 1;
  *(uint *)((int)auStack_a4 + *(int *)(local_ac[0] + 4) + 0xc) =
       *(uint *)((int)auStack_a4 + *(int *)(local_ac[0] + 4) + 0xc) & 0xffffefff | 0x2000;
  iVar1 = *(int *)(local_bc[0] + 4);
  *(undefined4 *)((int)auStack_a4 + iVar1) = 2;
  *(undefined4 *)((int)auStack_a4 + iVar1 + 4) = 0;
  FUN_00438d90(local_ac,param_2,uVar2);
  FUN_00431020();
  local_14 = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_00431040();
  local_5c[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)local_5c);
  ExceptionList = local_10;
  return param_1;
}

