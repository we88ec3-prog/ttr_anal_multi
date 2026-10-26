
undefined4 FUN_004b6200(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929e6e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb131c & 1) == 0) {
    DAT_00fb131c = DAT_00fb131c | 1;
    local_8 = 0;
    FUN_00570ec0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccf50);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb132c != (int *)0x0) {
    (**(code **)(*DAT_00fb132c + 0x20))(*(undefined4 *)(param_1 + 2),*(undefined1 *)(param_1 + 6));
  }
  ExceptionList = local_10;
  return 0;
}

