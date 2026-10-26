
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494360(void)

{
  if ((_DAT_00fd2cf4 & 1) == 0) {
    _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
    DAT_00fd2cf8 = CSceneManager::vftable;
    DAT_00fd8ba4 = 0;
    FUN_004b7dc0();
    _atexit((_func_4879 *)&LAB_00bcdcf0);
  }
                    /* WARNING: Could not recover jumptable at 0x004943aa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_00fd2cf8[1])();
  return;
}

