
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00775e50(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009057f8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = FoxUI::FXUIFontItem::vftable;
  local_8 = 0;
  if ((_DAT_00fe2890 & 1) == 0) {
    _DAT_00fe2890 = _DAT_00fe2890 | 1;
    if ((_DAT_00fe37e8 & 1) == 0) {
      _DAT_00fe37e8 = _DAT_00fe37e8 | 1;
      DAT_00fe37e4 = FoxUI::CReferenceFontImplEntry::vftable;
    }
    DAT_00fe2894 = (int *)&DAT_00fe37e4;
  }
  (**(code **)(*DAT_00fe2894 + 4))(param_1[3],uVar1);
  param_1[3] = 0;
  *param_1 = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

