
void FUN_008d1e70(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_1bc [4];
  int local_1ac;
  byte local_1a8;
  undefined4 local_198;
  int *local_194;
  undefined4 *local_190;
  uint local_18c;
  undefined4 local_188 [96];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_194 = param_3;
  local_190 = param_2;
  iVar1 = param_2[2];
  puVar4 = local_1bc;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar4 = puVar4 + 1;
  }
  local_1bc[2] = 2;
  if ((iVar1 == 10) || (iVar1 == 7)) {
    local_1bc[2] = 3;
  }
  FUN_008d0810(param_1,local_188,0x20,&local_18c);
  if ((int)local_18c < 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((uint)local_190[6] < local_18c) {
    local_18c = local_190[6];
  }
  uVar2 = *param_1;
  local_198 = param_1[2];
  if ((local_190[2] != 7) && (local_190[7] != 0)) {
    *(char *)(local_190[7] + *local_194) = (char)local_18c;
  }
  puVar4 = local_188;
  local_190 = (undefined4 *)uVar2;
  for (; 0 < (int)local_18c; local_18c = local_18c - 1) {
    uVar2 = puVar4[1];
    *param_1 = *puVar4;
    param_1[2] = uVar2;
    FUN_008d1aa0(param_1,local_1bc,local_194,param_4,0);
    local_1ac = local_1ac + (uint)local_1a8;
    puVar4 = puVar4 + 3;
  }
  param_1[2] = local_198;
  *param_1 = local_190;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

