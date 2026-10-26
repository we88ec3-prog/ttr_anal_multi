
void FUN_0087cda0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 *puStack_b4;
  undefined4 uStack_b0;
  undefined1 *puStack_ac;
  undefined4 *puStack_a8;
  undefined4 *puStack_a4;
  undefined4 local_94;
  undefined4 local_90 [11];
  undefined1 auStack_64 [12];
  undefined1 auStack_58 [8];
  undefined4 local_50 [9];
  uint uStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_94;
  local_94 = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    puStack_a4 = (undefined4 *)0x87cde4;
    FUN_0079c530();
    puVar2 = local_90;
    puVar3 = local_50;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puStack_a8 = local_50;
    puStack_ac = (undefined1 *)0x87ce01;
    puStack_a4 = puStack_a8;
    D3DXMatrixTranspose();
    puStack_b4 = auStack_58;
    uStack_b0 = 0;
    puStack_ac = puStack_b4;
    D3DXMatrixInverse();
    (**(code **)(*param_2 + 0x98))(param_2,puStack_a8,auStack_64);
    __security_check_cookie(uStack_2c ^ (uint)&puStack_b4);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_94);
  return;
}

