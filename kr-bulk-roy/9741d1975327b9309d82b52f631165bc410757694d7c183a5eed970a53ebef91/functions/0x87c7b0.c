
void FUN_0087c7b0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puStack_a8;
  undefined4 *puStack_a4;
  undefined4 local_94;
  undefined4 local_90 [14];
  undefined1 auStack_58 [8];
  undefined4 local_50 [12];
  uint uStack_20;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_94;
  local_94 = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    puStack_a4 = (undefined4 *)0x87c7f4;
    FUN_0079c530();
    puVar2 = local_90;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_a8 = local_50;
    puStack_a4 = puStack_a8;
    D3DXMatrixTranspose();
    (**(code **)(*param_2 + 0x98))(param_2,unaff_ESI,auStack_58);
    __security_check_cookie(uStack_20 ^ (uint)&puStack_a8);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_94);
  return;
}

