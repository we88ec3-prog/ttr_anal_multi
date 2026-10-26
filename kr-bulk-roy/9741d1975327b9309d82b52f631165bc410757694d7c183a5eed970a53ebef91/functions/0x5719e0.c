
void FUN_005719e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = 0x100;
  local_10 = 0x100;
  local_1c = 0x80;
  local_18 = 0;
  (**(code **)(*(int *)*param_1 + 0x20))(param_2,param_3,&local_1c,param_1[1]);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

