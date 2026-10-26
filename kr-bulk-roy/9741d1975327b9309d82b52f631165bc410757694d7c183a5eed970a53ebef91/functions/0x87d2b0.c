
void FUN_0087d2b0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined4 *puVar3;
  undefined4 *puStack_12c;
  undefined4 uStack_128;
  undefined4 *puStack_124;
  undefined1 auStack_114 [4];
  undefined4 local_110;
  undefined4 local_10c [17];
  undefined4 local_c8 [27];
  undefined1 auStack_5c [12];
  undefined4 local_50 [11];
  uint uStack_24;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_114;
  local_110 = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    puVar1 = (undefined4 *)(param_4 + 0x54);
    puVar3 = local_c8;
    for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_124 = (undefined4 *)(param_5 + 4);
    puVar1 = (undefined4 *)(param_4 + 0x98);
    puVar3 = local_10c;
    for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    uStack_128 = 0x87d328;
    puStack_124 = (undefined4 *)FUN_007e7dd0();
    uStack_128 = 0x87d336;
    puVar1 = (undefined4 *)FUN_0087b030();
    puVar3 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_12c = local_50;
    uStack_128 = 0;
    puStack_124 = puStack_12c;
    D3DXMatrixInverse();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_ESI,auStack_5c);
    __security_check_cookie(uStack_24 ^ (uint)&puStack_12c);
    return;
  }
  __security_check_cookie(local_c ^ (uint)auStack_114);
  return;
}

