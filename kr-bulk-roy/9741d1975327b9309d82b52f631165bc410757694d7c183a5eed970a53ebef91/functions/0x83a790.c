
void FUN_0083a790(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int in_ECX;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [68];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_74;
  if (*(int *)(in_ECX + 0xec) != 0) {
    local_68 = param_1;
    local_64 = param_2;
    local_60 = param_3;
    local_74 = param_4;
    local_70 = param_5;
    local_6c = param_6;
    local_5c = param_7;
    local_58 = param_8;
    local_54 = param_9;
    D3DXMatrixLookAtRH(local_50,&local_68,&local_74,&local_5c);
    (**(code **)(**(int **)(in_ECX + 0xec) + 0xb0))(*(int **)(in_ECX + 0xec),2,local_50);
    FUN_00839490();
  }
  __security_check_cookie(local_c ^ (uint)&local_74);
  return;
}

