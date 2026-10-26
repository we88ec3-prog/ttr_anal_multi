
void FUN_0073b450(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_10 = in_ECX[3];
  local_c = in_ECX[4];
  local_18 = 0;
  local_14 = 0;
  if (param_2 == (undefined4 *)0x0) {
    param_2 = &local_18;
  }
  (**(code **)(*in_ECX + 0x2c))(param_2,0,0,0,param_1,param_3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

