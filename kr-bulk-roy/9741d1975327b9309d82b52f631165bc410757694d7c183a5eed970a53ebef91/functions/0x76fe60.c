
void FUN_0076fe60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,char param_6)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe8))(*(int **)(in_ECX + 0xc),0x13,&local_8);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe8))(*(int **)(in_ECX + 0xc),0xce,&local_c);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe8))(*(int **)(in_ECX + 0xc),0xcf,&local_10);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe8))(*(int **)(in_ECX + 0xc),0xd0,&local_14);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0x13,5);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xce,1);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xd0,2);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xcf,2);
  if (param_6 == '\0') {
    if (*(int *)(in_ECX + 8) == 0) goto LAB_0076ff56;
    piVar1 = *(int **)(in_ECX + 8);
  }
  else {
    if (*(int *)(in_ECX + 4) == 0) goto LAB_0076ff56;
    piVar1 = *(int **)(in_ECX + 4);
  }
  (**(code **)(*piVar1 + 0x3c))(piVar1,0,param_1,param_3,param_2,param_4,param_5);
LAB_0076ff56:
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0x13,local_8);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xce,local_c);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xcf,local_10);
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xe4))(*(int **)(in_ECX + 0xc),0xd0,local_14);
  return;
}

