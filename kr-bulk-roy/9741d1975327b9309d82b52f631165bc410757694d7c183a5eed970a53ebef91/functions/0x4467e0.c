
void FUN_004467e0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint in_stack_00000018;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b510;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_34[0] = local_34[0] & 0xffff0000;
  local_20 = 7;
  local_24 = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  iVar1 = *(int *)(in_ECX + 0xfc);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_007578f0(uVar2);
  FUN_00759ed0(iVar1 + 0xe8,local_34,0x7b,0x7d);
  if (7 < local_20) {
    FUN_0089120c(local_34[0]);
  }
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

