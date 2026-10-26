
void FUN_0081e570(byte param_1)

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
  *in_ECX = CLocalizedWordFilterBase::vftable;
  local_8 = 0;
  FUN_0081cd10(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2],uVar1);
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

