
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006df020(void)

{
  int iVar1;
  uint local_18;
  int local_14;
  undefined8 local_10;
  
  if ((_DAT_00fe4b40 & 1) == 0) {
    _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
    FUN_006eb420();
  }
  if (DAT_00fe4b28 == 0 && DAT_00fe4b2c == 0) {
    FUN_006eb3c0(&local_18);
  }
  else {
    local_18 = DAT_00fe4b28;
    local_14 = DAT_00fe4b2c;
  }
  local_10 = (double)CONCAT44((local_14 - _DAT_00fe4b3c) - (uint)(local_18 < _DAT_00fe4b38),
                              local_18 - _DAT_00fe4b38);
  local_10 = (double)(longlong)local_10 / (double)_DAT_00fe4b20;
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  *(double *)(DAT_00fba7cc + 0x1358) = local_10;
  *(double *)(iVar1 + 0x1350) = local_10;
  *(undefined4 *)(iVar1 + 0x1378) = 0;
  return;
}

