
void FUN_008126f0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20 = *param_1;
  local_1c = param_1[1];
  local_18 = param_1[2];
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = param_2[2];
  alListenerfv(0x100f,&local_20);
  alGetError();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

