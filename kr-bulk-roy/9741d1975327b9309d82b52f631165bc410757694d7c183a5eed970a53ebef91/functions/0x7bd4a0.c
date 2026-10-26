
void FUN_007bd4a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bbfc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x40));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  uVar1 = DAT_00fb79e8 & 1;
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 4 + param_1 * 4);
  if (uVar1 == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x40));
  ExceptionList = local_10;
  return;
}

