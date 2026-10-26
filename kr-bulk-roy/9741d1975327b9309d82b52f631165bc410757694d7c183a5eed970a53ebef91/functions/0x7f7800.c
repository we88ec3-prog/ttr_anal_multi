
void FUN_007f7800(void)

{
  int iVar1;
  undefined4 in_ECX;
  int unaff_ESI;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093220a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if (*(int *)(unaff_ESI + 0x80) != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    iVar1 = FUN_00843ef0();
    if (iVar1 != 0) {
      local_14 = *(undefined4 *)(iVar1 + 0xb8);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      (**(code **)(*DAT_00fb76a8 + 0x5c))(&local_14);
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  }
  if (*(undefined4 **)(unaff_ESI + 0x80) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(unaff_ESI + 0x80))(1);
    *(undefined4 *)(unaff_ESI + 0x80) = 0;
  }
  ExceptionList = local_10;
  return;
}

