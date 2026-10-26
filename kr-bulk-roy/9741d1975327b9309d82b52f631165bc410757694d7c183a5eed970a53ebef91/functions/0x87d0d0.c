
void FUN_0087d0d0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_e0;
  undefined4 *puStack_dc;
  undefined4 local_cc;
  undefined4 local_c8 [28];
  undefined1 auStack_58 [8];
  undefined4 local_50 [12];
  uint uStack_20;
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
    puStack_e0 = (undefined4 *)0x87d137;
    FUN_007e7dd0();
    puStack_dc = (undefined4 *)0x87d142;
    FUN_0079c530();
    puVar2 = local_c8;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_e0 = local_50;
    puStack_dc = puStack_e0;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_ESI,auStack_58);
    __security_check_cookie(uStack_20 ^ (uint)&puStack_e0);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_cc);
  return;
}

