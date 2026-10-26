
void FUN_00564610(int param_1)

{
  int *piVar1;
  undefined1 local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x50))(local_14);
    if (param_1 == 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (param_1 == 1) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (param_1 == 2) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

