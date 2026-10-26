
void FUN_004774b0(int param_1)

{
  undefined2 uVar1;
  undefined2 local_1d;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094135c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar1 = DAT_00f942c8;
  if ((DAT_00fb9368 & 1) == 0) {
    DAT_00fb9368 = DAT_00fb9368 | 1;
    local_c = 1;
    FUN_00822000();
    _atexit((_func_4879 *)&LAB_00bcd590);
  }
  local_c = 0xffffffff;
  local_1d = 0xf7;
  local_1b = FUN_00822660(uVar1);
  local_1a = *(undefined1 *)(param_1 + 0x168);
  local_19 = *(undefined1 *)(param_1 + 0x169);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_1d,5);
  }
  ExceptionList = local_14;
  return;
}

