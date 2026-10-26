
void FUN_006d8290(undefined4 *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int in_ECX;
  void *pvStack_24;
  undefined1 local_20 [12];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092162e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00fb7bc8 & 1) == 0) {
    DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
    local_c = 0;
    FUN_00734ef0();
    _atexit((_func_4879 *)&LAB_00bcd4f0);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fb7b78 + 0x4c))(local_20,*(undefined4 *)(in_ECX + 0xc),param_3);
  *param_1 = param_4;
  *param_2 = uVar1;
  ExceptionList = pvStack_24;
  return;
}

