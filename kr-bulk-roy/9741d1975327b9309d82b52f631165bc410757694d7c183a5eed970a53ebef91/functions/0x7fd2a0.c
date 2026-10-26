
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007fd2a0(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_28;
  undefined4 local_24;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c341;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  local_1c = (int)(param_1[8] - param_1[7]) >> 2;
  local_14 = 0;
  if (local_1c != 0) {
    do {
      iVar1 = *(int *)(param_1[7] + local_14 * 4);
      if ((DAT_00fe3284 & 1) == 0) {
        DAT_00fe3284 = DAT_00fe3284 | 1;
        local_8._0_1_ = 2;
        FUN_007df1e0(uVar2);
        _atexit((_func_4879 *)&LAB_00bd0ad0);
        local_8 = CONCAT31(local_8._1_3_,1);
      }
      local_18 = iVar1;
      FUN_007dfea0(&local_28,&local_18);
      FUN_004ca160(local_28,local_24);
      _DAT_00fe32b0 = 1;
      if (iVar1 != 0) {
        FUN_007f3880(iVar1);
        FUN_0089120c(iVar1);
      }
      local_14 = local_14 + 1;
    } while (local_14 < local_1c);
  }
  if (param_1[7] != 0) {
    FUN_0089120c(param_1[7]);
  }
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

