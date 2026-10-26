
void FUN_0083af10(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_b0 [17];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int *local_54;
  undefined4 local_50 [17];
  uint local_c;
  
  iVar1 = param_3;
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_54 = param_1;
  if (param_3 != 0) {
    local_6c = 0;
    local_68 = 0;
    local_60 = 0;
    local_5c = 0;
    local_58 = 0;
    if (*(int *)(param_3 + 0xb4) == 0) {
      iVar2 = FUN_008396e0(&local_6c,&local_60,&local_58);
      piVar4 = local_54;
      if (iVar2 != 0) {
        (**(code **)(*local_54 + 0x120))(&param_2,&local_6c,&local_60,&local_58);
      }
    }
    else {
      piVar4 = (int *)param_1[0x3b];
      puVar3 = (undefined4 *)(param_3 + 0x70);
      puVar5 = local_b0;
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar3 = local_b0;
      puVar5 = local_50;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      (**(code **)(*piVar4 + 0xb0))(piVar4,param_2 + 0x10,local_50);
      piVar4 = local_54;
    }
    local_64 = *(undefined4 *)(iVar1 + 0xb8);
    (**(code **)(*piVar4 + 0x18))(param_2,&local_64);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(DAT_00d61f20 ^ (uint)&stack0xfffffffc ^ (uint)&stack0xfffffffc);
  return;
}

