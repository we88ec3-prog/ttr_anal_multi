
void FUN_00658f50(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d1f0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CMissionConditionPanel::vftable;
  local_8 = 1;
  FUN_0065b490(*(undefined4 *)in_ECX[0x53],(undefined4 *)in_ECX[0x53]);
  FUN_0089120c(in_ECX[0x53],uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowThin::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

