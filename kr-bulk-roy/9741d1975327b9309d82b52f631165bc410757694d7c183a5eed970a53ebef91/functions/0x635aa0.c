
void FUN_00635aa0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009163d5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CTalkBoxDialog::vftable;
  local_8 = 1;
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1,uVar1);
    in_ECX[0x2f] = 0;
  }
  if (in_ECX[0x30] != 0) {
    FUN_00635b50(in_ECX[0x30]);
    in_ECX[0x30] = 0;
  }
  FUN_007b6d70();
  FUN_0089120c(in_ECX[0x27]);
  in_ECX[0x27] = 0;
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIDummy::vftable;
  FUN_00745380();
  ExceptionList = local_10;
  return;
}

