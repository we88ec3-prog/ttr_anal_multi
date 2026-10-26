
void FUN_0066caa0(undefined4 param_1)

{
  uint in_stack_00000018;
  undefined2 local_4c [8];
  undefined4 local_3c;
  undefined4 local_38;
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
  
  puStack_c = &LAB_0091e518;
  local_10 = ExceptionList;
  uStack_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uStack_1c = 0;
  uStack_20 = 0;
  uStack_24 = 0;
  uStack_28 = 0;
  uStack_2c = 0;
  uStack_30 = 0;
  local_14 = (undefined1 *)local_4c;
  local_8 = 0;
  local_3c = 0;
  local_38 = 7;
  local_4c[0] = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  FUN_0066cbc0();
  if (7 < in_stack_00000018) {
    uStack_1c = param_1;
    uStack_20 = 0x66cb11;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  return;
}

