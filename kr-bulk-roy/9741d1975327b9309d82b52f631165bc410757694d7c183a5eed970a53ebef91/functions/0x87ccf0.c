
void FUN_0087ccf0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_b4;
  undefined4 uStack_b0;
  undefined4 *puStack_ac;
  undefined1 auStack_9c [4];
  undefined4 local_98;
  undefined4 local_94 [14];
  undefined1 auStack_5c [12];
  undefined4 local_50 [11];
  uint uStack_24;
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
    puStack_b4 = local_50;
    uStack_b0 = 0;
    puStack_ac = puStack_b4;
    D3DXMatrixInverse();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_ESI,auStack_5c);
    __security_check_cookie(uStack_24 ^ (uint)&puStack_b4);
    return;
  }
  __security_check_cookie(DAT_00d61f20 ^ (uint)auStack_9c ^ (uint)auStack_9c);
  return;
}

