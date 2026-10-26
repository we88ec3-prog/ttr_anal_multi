
void FUN_00808450(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090985d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = ObsessionsAI::CManager::vftable;
  local_8 = 1;
  FUN_0057ffd0(*(undefined4 *)in_ECX[8],(undefined4 *)in_ECX[8]);
  FUN_0089120c(in_ECX[8],uVar1);
  local_8 = 2;
  FUN_005540c0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2]);
  ExceptionList = local_10;
  return;
}

