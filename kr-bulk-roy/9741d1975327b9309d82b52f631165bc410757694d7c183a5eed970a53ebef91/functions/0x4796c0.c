
void FUN_004796c0(undefined4 param_1,undefined4 param_2)

{
  uint in_stack_0000001c;
  undefined2 local_50 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b8d8;
  local_10 = ExceptionList;
  uStack_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_24 = 0;
  uStack_28 = 0;
  uStack_2c = 0;
  uStack_30 = 0;
  uStack_34 = 0;
  local_14 = (undefined1 *)local_50;
  local_8 = 0;
  local_40 = 0;
  local_3c = 7;
  local_50[0] = 0;
  FUN_004026e0(&param_2,0,0xffffffff);
  FUN_00479750();
  if (7 < in_stack_0000001c) {
    uStack_1c = param_2;
    uStack_20 = 0x479732;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

