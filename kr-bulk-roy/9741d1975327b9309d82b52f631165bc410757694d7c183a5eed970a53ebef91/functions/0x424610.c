
void FUN_00424610(undefined4 param_1,undefined4 param_2,void *param_3)

{
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009461ee;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fab130 + 4))(param_1,param_2);
  ExceptionList = param_3;
  return;
}

