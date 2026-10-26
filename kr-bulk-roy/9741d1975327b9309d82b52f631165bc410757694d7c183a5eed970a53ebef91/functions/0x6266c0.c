
void FUN_006266c0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  undefined4 *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091a3b7;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::CJoyStickOptionDefWnd::vftable;
  local_18[0] = in_ECX + 0x4b;
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  FUN_005540c0(*(undefined4 *)in_ECX[0x4c],(undefined4 *)in_ECX[0x4c]);
  FUN_0089120c(in_ECX[0x4c],uVar1);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_00628330(local_18,*(undefined4 *)in_ECX[0x48],(undefined4 *)in_ECX[0x48]);
  FUN_0089120c(in_ECX[0x48]);
  local_8 = 0xffffffff;
  FUN_00629fc0();
  ExceptionList = local_10;
  return;
}

