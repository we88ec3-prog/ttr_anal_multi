
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565600(undefined4 param_1)

{
  _DAT_00fe36d4 = 4;
  if ((_DAT_00fe36dc & 1) == 0) {
    _DAT_00fe36dc = _DAT_00fe36dc | 1;
    _DAT_00fe36d8 = param_1;
    return;
  }
  _DAT_00fe36d8 = param_1;
  return;
}

