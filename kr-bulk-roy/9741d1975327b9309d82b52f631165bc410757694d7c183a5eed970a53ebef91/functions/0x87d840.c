
void FUN_0087d840(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puStack_fc;
  undefined1 *puStack_f8;
  undefined4 *puStack_f4;
  undefined4 uStack_f0;
  undefined4 *puStack_ec;
  undefined4 local_dc;
  undefined4 local_d8 [29];
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [12];
  undefined4 local_50 [9];
  uint uStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_dc;
  local_dc = param_3;
  if ((param_4 != 0) && (param_2 != (int *)0x0)) {
    puVar1 = (undefined4 *)(param_4 + 0x54);
    puVar3 = local_d8;
    for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar1 = (undefined4 *)(param_4 + 0x98);
    puVar3 = local_50;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_ec = local_50;
    uStack_f0 = 0x87d8b1;
    puVar1 = (undefined4 *)FUN_0087b030();
    puStack_f4 = local_50;
    uStack_f0 = 0;
    puVar3 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_f8 = (undefined1 *)0x87d8d4;
    puStack_ec = puStack_f4;
    D3DXMatrixInverse();
    puStack_fc = auStack_5c;
    puStack_f8 = puStack_fc;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,uStack_f0,auStack_64);
    __security_check_cookie(uStack_2c ^ (uint)&puStack_fc);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_dc);
  return;
}

