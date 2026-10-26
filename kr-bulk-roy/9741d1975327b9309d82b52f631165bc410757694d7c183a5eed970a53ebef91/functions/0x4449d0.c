
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004449d0(void)

{
  float *pfVar1;
  float10 fVar2;
  float10 fVar3;
  int local_18;
  
  _DAT_00fb8820 = 0.024543693;
  local_18 = 0;
  pfVar1 = (float *)&DAT_00fb8020;
  do {
    (&DAT_00fb7c20)[local_18] = (float)local_18 * _DAT_00fb8820;
    fVar2 = (float10)FUN_008ff0a0();
    fVar3 = (float10)FUN_008fef70();
    *pfVar1 = (float)fVar2;
    pfVar1[1] = -(float)fVar3;
    local_18 = local_18 + 1;
    pfVar1 = pfVar1 + 2;
  } while ((int)pfVar1 < 0xfb8820);
  _DAT_00fb8824 = 1.0 / _DAT_00fb8820;
  return &DAT_00fb7c20;
}

