
void FUN_0087d1b0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puStack_ec;
  undefined1 *puStack_e8;
  undefined4 *puStack_e4;
  undefined4 uStack_e0;
  undefined4 *puStack_dc;
  undefined4 local_cc;
  undefined4 local_c8 [25];
  undefined1 auStack_64 [8];
  undefined1 auStack_5c [12];
  undefined4 local_50 [9];
  uint uStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_cc;
  local_cc = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    puStack_dc = (undefined4 *)(param_5 + 4);
    puVar2 = (undefined4 *)(param_4 + 0x98);
    puVar3 = local_c8;
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    uStack_e0 = 0x87d217;
    FUN_007e7dd0();
    puStack_dc = (undefined4 *)0x87d222;
    FUN_0079c530();
    puVar2 = local_c8;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_e4 = local_50;
    uStack_e0 = 0;
    puStack_e8 = (undefined1 *)0x87d247;
    puStack_dc = puStack_e4;
    D3DXMatrixInverse();
    puStack_ec = auStack_5c;
    puStack_e8 = puStack_ec;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,uStack_e0,auStack_64);
    __security_check_cookie(uStack_2c ^ (uint)&puStack_ec);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_cc);
  return;
}

