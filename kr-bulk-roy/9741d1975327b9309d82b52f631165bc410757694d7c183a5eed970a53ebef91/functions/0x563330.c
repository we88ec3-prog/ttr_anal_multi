
void FUN_00563330(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,int param_6)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  
  local_14 = param_1;
  FUN_0082ef00(&local_14);
  if ((local_10 != *(int *)(in_ECX + 0x1c)) &&
     (piVar1 = *(int **)(local_10 + 0x10), piVar1 != (int *)0x0)) {
    local_10 = param_2;
    local_c = param_3;
    FUN_004d0ce0();
    if (param_4 != 0) {
      (**(code **)(*piVar1 + 0x68))(param_5,0x3f800000);
      piVar1[0x10d] = param_6;
    }
  }
  return;
}

