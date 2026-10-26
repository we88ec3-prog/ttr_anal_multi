
void FUN_00761220(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919108;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUIEdit::vftable;
  local_8 = 0;
  if (in_ECX[0x57] != 0) {
    FUN_00891d3d(in_ECX[0x57],uVar1);
    in_ECX[0x57] = 0;
  }
  if (in_ECX[0x52] != 0) {
    FUN_007571c0();
    in_ECX[0x52] = 0;
  }
  FUN_00757640(in_ECX + 0x42);
  local_8 = 0xffffffff;
  FUN_00769220();
  ExceptionList = local_10;
  return;
}

