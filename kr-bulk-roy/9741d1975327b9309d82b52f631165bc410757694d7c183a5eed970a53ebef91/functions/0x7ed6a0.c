
undefined4 FUN_007ed6a0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int local_bc [3];
  byte abStack_b0 [84];
  undefined **local_5c [19];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091879b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_00730050(in_ECX + 0x44,param_1);
  if (iVar2 == 0) {
    ExceptionList = local_10;
    return 1;
  }
  FUN_007a4790(local_bc,iVar2 + 0x30);
  local_8 = 0;
  FUN_007ed790(local_bc,param_2,uVar1);
  local_8 = 0xffffffff;
  if ((abStack_b0[*(int *)(local_bc[0] + 4)] & 6) == 0) {
    FUN_007a4860();
    local_5c[0] = std::ios_base::vftable;
    std::ios_base::_Ios_base_dtor((ios_base *)local_5c);
    ExceptionList = local_10;
    return 0;
  }
  FUN_007a4860();
  local_5c[0] = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)local_5c);
  ExceptionList = local_10;
  return 2;
}

