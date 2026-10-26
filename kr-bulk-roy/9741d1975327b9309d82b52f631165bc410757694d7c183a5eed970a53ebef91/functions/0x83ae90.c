
void FUN_0083ae90(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int in_ECX;
  undefined1 *local_5c;
  undefined1 local_50 [56];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)local_50;
  local_5c = (undefined1 *)*param_4;
  FUN_00839640(local_50,param_2,param_3);
  local_5c = local_50;
  (**(code **)(**(int **)(in_ECX + 0xec) + 0xb0))(*(int **)(in_ECX + 0xec),*param_1 + 0x10);
  __security_check_cookie(uStack_18 ^ (uint)&local_5c);
  return;
}

