
void FUN_006c0ab0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ae5a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00744640(param_1,param_2);
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(uVar1);
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde28 + 0x20))(DAT_00fcde28,0);
  if ((DAT_00fc1b14 & 1) == 0) {
    DAT_00fc1b14 = DAT_00fc1b14 | 1;
    local_8 = 1;
    FUN_0055ee90();
    _atexit((_func_4879 *)&LAB_00bcdf90);
    local_8 = 0xffffffff;
  }
  FUN_0055fad0();
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 2;
    FUN_00736880();
    _atexit(FUN_00bce6f0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fcde28 + 0x2c))(DAT_00fcde28);
  ExceptionList = local_10;
  return;
}

