
void FUN_0080e5c0(float *param_1)

{
  int iVar1;
  int in_ECX;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(in_ECX + 0x28);
  if (iVar1 != 0) {
    local_14 = *param_1 * 0.1;
    local_10 = param_1[1] * 0.1;
    local_c = param_1[2] * 0.1;
    if (*(int **)(iVar1 + 8) != (int *)0x0) {
      *(float *)(iVar1 + 0x10) = local_14;
      *(float *)(iVar1 + 0x14) = local_10;
      *(float *)(iVar1 + 0x18) = local_c;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      (**(code **)(**(int **)(iVar1 + 8) + 0x18))(&local_14,0);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

