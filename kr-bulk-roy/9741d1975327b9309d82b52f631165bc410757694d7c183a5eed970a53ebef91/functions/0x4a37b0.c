
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004a37b0(undefined2 param_1)

{
  undefined2 local_100c;
  undefined2 local_100a;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_100c = 0x20;
  local_100a = param_1;
  local_c = 5;
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,5);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

