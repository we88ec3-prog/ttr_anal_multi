
void FUN_0047b190(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d438;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CScenarioReviewChapterItem::vftable;
  if (7 < (uint)in_ECX[0x98]) {
    FUN_0089120c(in_ECX[0x93],uVar1);
  }
  in_ECX[0x98] = 7;
  in_ECX[0x97] = 0;
  *(undefined2 *)(in_ECX + 0x93) = 0;
  *in_ECX = FoxUI::FXUIContentButton::vftable;
  local_8 = 0;
  FUN_0077b5f0(in_ECX + 0x57);
  local_8 = 0xffffffff;
  FUN_00754980();
  ExceptionList = local_10;
  return;
}

