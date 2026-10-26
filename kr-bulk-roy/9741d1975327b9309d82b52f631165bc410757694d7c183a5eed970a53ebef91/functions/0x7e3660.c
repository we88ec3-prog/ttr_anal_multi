
void FUN_007e3660(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_4c [56];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092bab4;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe1df8 & 1) == 0) {
    DAT_00fe1df8 = DAT_00fe1df8 | 1;
    local_8 = 0;
    FUN_00716be0(local_14);
    _atexit((_func_4879 *)&LAB_00bcf1a0);
  }
  local_8 = 0xffffffff;
  iVar1 = FUN_00716740(param_2);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x30) < 0x10) {
      iVar1 = iVar1 + 0x1c;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1c);
    }
    if ((DAT_00fe3314 & 1) == 0) {
      DAT_00fe3314 = DAT_00fe3314 | 1;
      local_8 = 1;
      FUN_007ed9f0();
      _atexit((_func_4879 *)&LAB_00bd0ae0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fe3318 != 0) {
      FUN_007ed8d0(local_4c,iVar1);
      local_8 = 2;
      FUN_007edcd0();
      local_8 = 0xffffffff;
      FUN_007ee080();
    }
    FUN_007e3860(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

