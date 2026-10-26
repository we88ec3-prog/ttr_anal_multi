
undefined4
FUN_0073cad0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int in_ECX;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = param_1;
  local_10 = 0;
  local_c = 0;
  FUN_008438c0(&local_18);
  if (local_14 == *(int *)(in_ECX + 0x3c)) {
    *param_4 = 0;
    return 0;
  }
  if (*(int *)(local_14 + 0x10) != 0) {
    FUN_0073da10(in_ECX + 0xc,*(int *)(local_14 + 0x10),param_2,param_3,0,&local_10);
    *param_4 = local_10;
    return 0;
  }
  *param_4 = 0;
  return 0;
}

