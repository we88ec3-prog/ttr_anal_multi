
void FUN_00812780(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  alGetListener3f(0x1004,&local_14,&local_10,&local_c);
  iVar1 = alGetError();
  if (iVar1 == 0) {
    *param_1 = local_14;
    param_1[1] = local_10;
    param_1[2] = local_c;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

