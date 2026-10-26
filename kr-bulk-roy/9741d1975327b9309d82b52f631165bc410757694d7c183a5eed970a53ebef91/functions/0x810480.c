
void FUN_00810480(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x2001c) == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_20 = *param_1;
  local_1c = param_1[1];
  local_18 = param_1[2];
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = param_2[2];
  alSourcefv(*(undefined4 *)(in_ECX + 0x10),0x100f,&local_20);
  alGetError();
  FUN_00810080();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

