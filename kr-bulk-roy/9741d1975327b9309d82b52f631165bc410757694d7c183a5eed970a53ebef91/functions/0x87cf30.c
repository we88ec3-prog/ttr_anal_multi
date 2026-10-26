
void FUN_0087cf30(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puStack_bc;
  undefined4 uStack_b8;
  undefined1 *puStack_b4;
  undefined4 *puStack_b0;
  undefined4 *puStack_ac;
  undefined1 auStack_9c [4];
  undefined4 local_98;
  undefined4 local_94 [12];
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [8];
  undefined4 local_50 [9];
  uint uStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_9c;
  local_98 = param_3;
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
    puStack_b0 = local_50;
    puStack_b4 = (undefined1 *)0x87cf8d;
    puStack_ac = puStack_b0;
    D3DXMatrixTranspose();
    puStack_bc = auStack_58;
    uStack_b8 = 0;
    puStack_b4 = puStack_bc;
    D3DXMatrixInverse();
    (**(code **)(*param_2 + 0x98))(param_2,puStack_ac,auStack_64);
    __security_check_cookie(uStack_2c ^ (uint)&puStack_bc);
    return;
  }
  __security_check_cookie(DAT_00d61f20 ^ (uint)auStack_9c ^ (uint)auStack_9c);
  return;
}

