
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a8850(void)

{
  int *unaff_ESI;
  
  (**(code **)(*unaff_ESI + 0x90))(1);
  if ((_DAT_00fe2ffc & 1) == 0) {
    _DAT_00fe2ffc = _DAT_00fe2ffc | 1;
    _DAT_00fe3000 = 1;
    _DAT_00fe3004 = 0;
    _atexit((_func_4879 *)&DAT_00bcfed0);
  }
  _DAT_00fe3004 = 0;
                    /* WARNING: Could not recover jumptable at 0x006a88a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 0xd4))();
  return;
}

