
void FUN_0087c720(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_a4;
  undefined1 auStack_98 [4];
  undefined4 local_94 [17];
  undefined4 local_50 [14];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_98;
  if ((param_4 != 0) && (param_2 != (int *)0x0)) {
    puVar2 = (undefined4 *)(param_4 + 0x54);
    puVar3 = local_94;
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = local_94;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_a4 = local_50;
    (**(code **)(*param_2 + 0x98))(param_2,param_3);
    __security_check_cookie(uStack_18 ^ (uint)&puStack_a4);
    return;
  }
  __security_check_cookie(DAT_00d61f20 ^ (uint)auStack_98 ^ (uint)auStack_98);
  return;
}

