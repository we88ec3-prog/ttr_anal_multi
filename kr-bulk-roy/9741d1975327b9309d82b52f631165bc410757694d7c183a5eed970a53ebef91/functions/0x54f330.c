
undefined4 FUN_0054f330(int param_1,char param_2,byte param_3,byte param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912c5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab278 & 1) == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_8 = 0;
    FUN_00817da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcced0);
  }
  local_8 = 0xffffffff;
  local_14 = (uint)*(ushort *)(param_1 + 2);
  FUN_008195e0(&local_14);
  if (local_18 != DAT_00fab280) {
    FUN_008196d0();
    if ((undefined4 *)local_18[5] == local_18) {
      if (param_2 != '\0') {
        ExceptionList = local_10;
        return 0;
      }
      if (local_18[6] == 0) {
        ExceptionList = local_10;
        return 0;
      }
      local_18 = *(undefined4 **)local_18[5];
    }
    if ((((local_18[4] != 0) && (param_3 < 4)) && (param_4 < 0xb)) &&
       (*(short *)(local_18[4] + 4 + ((uint)param_3 * 0xb + (uint)param_4) * 2) != 0)) {
      puVar1 = (undefined4 *)FUN_0054f4e0(param_1 + 4);
      *param_5 = *puVar1;
      param_5[1] = puVar1[1];
      param_5[2] = puVar1[2];
      param_5[3] = puVar1[3];
      ExceptionList = local_10;
      return 1;
    }
  }
  ExceptionList = local_10;
  return 0;
}

