
void FUN_0083a690(float param_1,float param_2,undefined4 param_3,undefined4 param_4)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_60 [4];
  float local_5c;
  undefined4 local_58 [19];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_60;
  if (*(int *)(in_ECX + 0xec) != 0) {
    local_5c = param_1 / param_2;
    D3DXMatrixPerspectiveFovRH(local_58,local_5c,param_2,param_3,param_4);
    (**(code **)(**(int **)(in_ECX + 0xec) + 0xb0))(*(int **)(in_ECX + 0xec),3,local_58);
    puVar2 = local_58;
    puVar3 = (undefined4 *)(in_ECX + 0x54);
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_60);
  return;
}

