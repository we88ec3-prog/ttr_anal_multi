
void FUN_0058cce0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f658;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::FXUIAttributeHistory::vftable;
  local_8 = 0;
  FUN_0051af60(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  FUN_0089120c(in_ECX[2],uVar1);
  ExceptionList = local_10;
  return;
}

