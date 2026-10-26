
undefined4 * FUN_0068da40(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a1d0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0x248);
  local_8 = 0;
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00754880(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *puVar2 = FoxUI::FXUIContentButton::vftable;
    FUN_0077b520(puVar2 + 0x57);
    *(undefined1 *)(puVar2 + 0x56) = 1;
    *puVar2 = FUI::CQuickJoinBtnTooTip::vftable;
    puVar3 = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}

