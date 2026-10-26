
void FUN_0087cc30(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_EDI;
  undefined4 *puVar3;
  undefined4 *puStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  undefined4 local_94;
  undefined4 local_90 [13];
  undefined1 auStack_5c [12];
  undefined4 local_50 [11];
  uint uStack_24;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_94;
  local_94 = param_3;
  if ((param_4 != 0) && (param_2 != (int *)0x0)) {
    puVar2 = (undefined4 *)(param_4 + 0x98);
    puVar3 = local_50;
    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_a4 = (undefined4 *)0x87cc80;
    FUN_0079c530();
    puVar2 = local_90;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_ac = local_50;
    uStack_a8 = 0;
    puStack_a4 = puStack_ac;
    D3DXMatrixInverse();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_EDI,auStack_5c);
    __security_check_cookie(uStack_24 ^ (uint)&puStack_ac);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_94);
  return;
}

