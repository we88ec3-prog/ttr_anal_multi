
void FUN_0040fbb0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091bf45;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CBuyPracticeTalentWnd::vftable;
  local_8 = 3;
  FUN_005540c0(*(undefined4 *)in_ECX[0x4e],(undefined4 *)in_ECX[0x4e]);
  FUN_0089120c(in_ECX[0x4e],uVar1);
  if (in_ECX[0x49] != 0) {
    FUN_00516210(in_ECX[0x4a]);
    FUN_0089120c(in_ECX[0x49],uVar1);
  }
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x4b] = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)in_ECX[0x46],(undefined4 *)in_ECX[0x46]);
  FUN_0089120c(in_ECX[0x46],uVar1);
  local_8 = 0xffffffff;
  *in_ECX = FoxUI::FXUIWindowClose::vftable;
  FUN_00756590();
  ExceptionList = local_10;
  return;
}

