
void FUN_00691ac0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d438;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0xf] = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  local_8 = 0;
  FUN_0077b5f0(in_ECX + 0x57);
  local_8 = 0xffffffff;
  FUN_00754980(uVar1);
  ExceptionList = local_10;
  return;
}

