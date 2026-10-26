
void FUN_0087c5d0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_94;
  undefined4 local_90 [16];
  undefined4 local_50 [14];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_94;
  local_94 = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    FUN_0079c530();
    puVar2 = local_90;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    (**(code **)(*param_2 + 0x98))(param_2,local_94,local_50);
    __security_check_cookie(uStack_18 ^ (uint)&stack0xffffff60);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_94);
  return;
}

