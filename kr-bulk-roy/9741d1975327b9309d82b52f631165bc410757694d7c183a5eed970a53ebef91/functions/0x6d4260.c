
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d4260(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d8de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (param_1 < 3) {
    _DAT_00fdf660 = &DAT_00fdf3f4 + param_1 * 0x10;
    _DAT_00fdf664 = param_1;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_8 = 0xffffffff;
    DAT_00fb91e9 = (byte)param_1;
    if (DAT_00fb91eb < (byte)param_1) {
      DAT_00fb91e9 = DAT_00fb91eb;
    }
    if (DAT_00fb91e9 < DAT_00fb91ea) {
      DAT_00fb91e9 = DAT_00fb91ea;
    }
    FUN_00823850();
    FUN_00823850();
    FUN_00823850();
  }
  ExceptionList = local_10;
  return;
}

