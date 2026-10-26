
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004a3720(undefined1 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined2 local_100c;
  undefined1 local_100a;
  undefined4 local_1009;
  undefined1 local_1005;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_100c = 0x27;
  local_100a = param_1;
  local_1009 = param_2;
  local_1005 = param_3;
  local_c = 8;
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,8);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

