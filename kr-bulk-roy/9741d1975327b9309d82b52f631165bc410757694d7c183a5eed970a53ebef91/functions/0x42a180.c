
undefined4 * FUN_0042a180(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917c50;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = _malloc(0x194);
  local_8 = 0;
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_00744320(uVar1);
    local_8 = CONCAT31(local_8._1_3_,1);
    *puVar2 = FoxUI::FXUIButton::vftable;
    FUN_0077b520(puVar2 + 0x2a);
    *(undefined1 *)(puVar2 + 0x29) = 1;
    *puVar2 = FoxUI::FXUIButtonResizeRM::vftable;
    puVar3 = puVar2;
  }
  ExceptionList = local_10;
  return puVar3;
}

