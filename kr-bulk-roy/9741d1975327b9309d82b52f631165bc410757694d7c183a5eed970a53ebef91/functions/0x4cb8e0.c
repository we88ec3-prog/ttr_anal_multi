
void FUN_004cb8e0(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906f28;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CActorState::vftable;
  local_8 = 0;
  FUN_005540c0(*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  FUN_0089120c(in_ECX[7],uVar1);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

