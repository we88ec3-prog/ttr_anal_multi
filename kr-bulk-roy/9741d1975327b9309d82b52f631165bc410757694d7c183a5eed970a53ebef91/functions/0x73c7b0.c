
void FUN_0073c7b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int in_ECX;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = param_1;
  FUN_008438c0(&local_18);
  if ((local_14 != *(int *)(in_ECX + 0x3c)) && (*(int *)(local_14 + 0x10) != 0)) {
    FUN_0073db20(in_ECX + 0xc,*(int *)(local_14 + 0x10),param_2);
  }
  local_10 = 0;
  local_c = 0;
  local_14 = param_1;
  FUN_008438c0(&local_14);
  if ((local_18 != *(int *)(in_ECX + 0x3c)) && (*(int *)(local_18 + 0x10) != 0)) {
    FUN_0073da10(in_ECX + 0xc,*(int *)(local_18 + 0x10),param_2,0xffffffff,0,&local_10);
  }
  *param_4 = 0;
  param_4[1] = 0;
  param_4[2] = local_10;
  param_4[3] = local_c;
  return;
}

