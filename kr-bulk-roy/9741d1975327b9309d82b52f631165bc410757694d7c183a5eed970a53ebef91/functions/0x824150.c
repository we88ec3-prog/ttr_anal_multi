
void FUN_00824150(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090e8dc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CCubeSystem::vftable;
  local_8._0_1_ = 6;
  local_8._1_3_ = 0;
  FUN_00825810(*(undefined4 *)in_ECX[0x1a],(undefined4 *)in_ECX[0x1a]);
  FUN_0089120c(in_ECX[0x1a],uVar1);
  local_8._0_1_ = 7;
  FUN_00825810(*(undefined4 *)in_ECX[0x16],(undefined4 *)in_ECX[0x16]);
  FUN_0089120c(in_ECX[0x16]);
  local_8._0_1_ = 8;
  FUN_00825810(*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12]);
  FUN_0089120c(in_ECX[0x12]);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_00825810(*(undefined4 *)in_ECX[0xe],(undefined4 *)in_ECX[0xe]);
  FUN_0089120c(in_ECX[0xe]);
  if (in_ECX[9] != 0) {
    FUN_0089120c(in_ECX[9]);
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_005540c0(*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  FUN_0089120c(in_ECX[6]);
  local_8 = 0xb;
  FUN_005540c0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2]);
  ExceptionList = local_10;
  return;
}

