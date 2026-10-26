
void FUN_00830040(undefined4 param_1)

{
  int *piVar1;
  undefined4 unaff_EDI;
  undefined1 local_3c [32];
  int local_1c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_00714770();
  if (piVar1 == (int *)0x0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  (**(code **)(*piVar1 + 0x10))(local_3c,0x34,1);
  (**(code **)(*piVar1 + 4))();
  if (local_1c != 3) {
    FUN_0082f660(unaff_EDI);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_0082f850(param_1,unaff_EDI);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

