
void FUN_0082caa0(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907160;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CSkillInterrupt_Consume::vftable;
  local_8 = 1;
  FUN_004ca160(*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  FUN_0089120c(in_ECX[6],uVar1);
  *in_ECX = CInterruptAction::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

