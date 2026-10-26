
void FUN_005632d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_c;
  int local_8;
  
  FUN_0082ef00(&param_1);
  if (local_8 != *(int *)(in_ECX + 0x1c)) {
    piVar1 = *(int **)(local_8 + 0x10);
    local_c = param_2;
    local_8 = param_3;
    (**(code **)(*piVar1 + 0x44))(&local_c,1);
    (**(code **)(*piVar1 + 0x58))(param_4);
  }
  return;
}

