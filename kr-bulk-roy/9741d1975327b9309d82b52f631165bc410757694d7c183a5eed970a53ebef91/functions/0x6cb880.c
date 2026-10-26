
int FUN_006cb880(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  int in_stack_00000014;
  uint in_stack_00000018;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092a880;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000014 == 0) {
    if (7 < in_stack_00000018) {
      FUN_0089120c(param_1,uVar2);
    }
    ExceptionList = local_10;
    return 0;
  }
  local_34[0] = local_34[0] & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  iVar1 = *in_ECX;
  local_8._0_1_ = 1;
  FUN_007578f0();
  FUN_00759ed0(iVar1 + 0xe8,local_34,0x7b,0x7d);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_20) {
    FUN_0089120c(local_34[0],uVar2);
  }
  FUN_00754510();
  iVar1 = *in_ECX;
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return iVar1;
}

