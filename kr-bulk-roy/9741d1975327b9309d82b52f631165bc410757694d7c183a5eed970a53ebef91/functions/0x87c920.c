
void FUN_0087c920(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_b0;
  undefined4 *puStack_ac;
  undefined1 auStack_9c [4];
  undefined4 local_98;
  undefined4 local_94 [15];
  undefined1 auStack_58 [8];
  undefined4 local_50 [12];
  uint uStack_20;
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
    puStack_ac = puStack_b0;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_EBX,auStack_58);
    __security_check_cookie(uStack_20 ^ (uint)&puStack_b0);
    return;
  }
  __security_check_cookie(DAT_00d61f20 ^ (uint)auStack_9c ^ (uint)auStack_9c);
  return;
}

