
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00671f30(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = FUI::CExpeditionCreateDialog::vftable;
  if ((_DAT_00fe2ffc & 1) == 0) {
    _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
    _DAT_00fe3000 = 1;
    _DAT_00fe3004 = 0;
    _atexit((_func_4879 *)&DAT_00bcfed0);
  }
  _DAT_00fe3004 = 0;
  *unaff_ESI = FoxUI::FXUIWindowSimple::vftable;
  FUN_00756590();
  return;
}

