
void FUN_007ab360(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092bd28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 0;
    FUN_007b5430(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  local_8 = 0xffffffff;
  DAT_00fba834 = 0;
  WaitForSingleObject(DAT_00d63c70,0xffffffff);
  CloseHandle(DAT_00d63c70);
  DAT_00d63c70 = (HANDLE)0xffffffff;
  (**(code **)(*DAT_00fba838 + 0x14))();
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 1;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007cf7b0(&DAT_00fe3250);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb7738 + 0x14))(DAT_00fb7738);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb7738 != (int *)0x0) {
    (**(code **)(*DAT_00fb7738 + 8))(DAT_00fb7738);
    DAT_00fb7738 = (int *)0x0;
  }
  if (DAT_00fb773c != (int *)0x0) {
    (**(code **)(*DAT_00fb773c + 8))(DAT_00fb773c);
    DAT_00fb773c = (int *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  (**(code **)(*DAT_00fb76a8 + 0xd4))();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  ExceptionList = local_10;
  return;
}

