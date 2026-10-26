
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006637f0(void)

{
  int *unaff_ESI;
  
  if ((_DAT_00fe1c4c & 1) == 0) {
    _DAT_00fe1c4c = _DAT_00fe1c4c | 1;
    FUN_004ff560();
    _atexit((_func_4879 *)&DAT_00bced40);
  }
  FUN_00663840(unaff_ESI,DAT_00fe1c6f);
  FUN_00663930(unaff_ESI);
  FUN_006641a0();
                    /* WARNING: Could not recover jumptable at 0x0066383e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*unaff_ESI + 200))();
  return;
}

