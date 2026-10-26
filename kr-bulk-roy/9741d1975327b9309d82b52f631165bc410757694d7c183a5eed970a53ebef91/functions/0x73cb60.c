
undefined4 FUN_0073cb60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  local_10 = param_1;
  local_14 = 0;
  FUN_008438c0(&local_10);
  if ((local_c != *(int *)(in_ECX + 0x3c)) && (*(int *)(local_c + 0x10) != 0)) {
    FUN_0073d790(in_ECX + 0xc,*(int *)(local_c + 0x10),param_2,0xffffffff,param_3,&local_14,0,0);
    return local_14;
  }
  return 0;
}

