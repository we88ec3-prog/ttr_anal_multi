
void FUN_004650f0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091ba2e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CLinkTextBox::vftable;
  local_8 = 2;
  FUN_00466430(*(undefined4 *)in_ECX[0x5d],(undefined4 *)in_ECX[0x5d]);
  FUN_0089120c(in_ECX[0x5d],uVar1);
  if (in_ECX[0x58] != 0) {
    FUN_0089120c(in_ECX[0x58],uVar1);
  }
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x5a] = 0;
  local_8 = 0xffffffff;
  FUN_00765a60();
  ExceptionList = local_10;
  return;
}

