
void FUN_0087d3b0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_EBX;
  undefined4 *puVar3;
  undefined4 *puStack_128;
  undefined4 *puStack_124;
  undefined1 auStack_114 [4];
  undefined4 local_110;
  undefined4 local_10c [17];
  undefined4 local_c8 [28];
  undefined1 auStack_58 [8];
  undefined4 local_50 [12];
  uint uStack_20;
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
    puStack_128 = (undefined4 *)0x87d428;
    puStack_124 = (undefined4 *)FUN_007e7dd0();
    puStack_128 = (undefined4 *)0x87d436;
    puVar1 = (undefined4 *)FUN_0087b030();
    puVar3 = local_50;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_128 = local_50;
    puStack_124 = puStack_128;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_EBX,auStack_58);
    __security_check_cookie(uStack_20 ^ (uint)&puStack_128);
    return;
  }
  __security_check_cookie(local_c ^ (uint)auStack_114);
  return;
}

