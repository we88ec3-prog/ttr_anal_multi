
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00671ea0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007564e0();
  unaff_ESI[0x3b] = 0;
  *unaff_ESI = FUI::CExpeditionCreateDialog::vftable;
  unaff_ESI[0x3c] = 0;
  unaff_ESI[0x3d] = 0;
  if ((_DAT_00fe2ffc & 1) == 0) {
    _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
    _DAT_00fe3000 = 1;
    _DAT_00fe3004 = 0;
    _atexit((_func_4879 *)&DAT_00bcfed0);
  }
  _DAT_00fe3004 = 1;
  return;
}

