
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00807340(void)

{
  int *piVar1;
  LPCRITICAL_SECTION p_Var2;
  int *piVar3;
  
  FUN_00807730();
  FUN_00807730();
  p_Var2 = DAT_00fe3380;
  if (DAT_00fe3380 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(DAT_00fe3380);
    FUN_0089120c(p_Var2);
    DAT_00fe3380 = (LPCRITICAL_SECTION)0x0;
  }
  p_Var2 = DAT_00fe33b0;
  if (DAT_00fe33b0 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(DAT_00fe33b0);
    FUN_0089120c(p_Var2);
    DAT_00fe33b0 = (LPCRITICAL_SECTION)0x0;
  }
  FUN_007b6d70();
  FUN_0089120c(DAT_00fe3394);
  DAT_00fe3394 = 0;
  piVar3 = (int *)*DAT_00fe3388;
  *DAT_00fe3388 = (int)DAT_00fe3388;
  DAT_00fe3388[1] = (int)DAT_00fe3388;
  _DAT_00fe338c = 0;
  if (piVar3 != DAT_00fe3388) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fe3388);
  }
  FUN_0089120c(DAT_00fe3388);
  FUN_007b6d70();
  FUN_0089120c(DAT_00fe3364);
  DAT_00fe3364 = 0;
  piVar3 = (int *)*DAT_00fe3358;
  *DAT_00fe3358 = (int)DAT_00fe3358;
  DAT_00fe3358[1] = (int)DAT_00fe3358;
  _DAT_00fe335c = 0;
  if (piVar3 != DAT_00fe3358) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fe3358);
  }
  FUN_0089120c(DAT_00fe3358);
  return;
}

