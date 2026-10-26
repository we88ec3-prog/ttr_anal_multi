
void FUN_00839640(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,float param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_cc [16];
  undefined1 local_8c [64];
  undefined1 local_4c [68];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  D3DXMatrixScaling(local_4c,*param_3,param_3[1],0x3f800000);
  D3DXMatrixRotationZ(local_8c,-param_4);
  D3DXMatrixMultiply(local_cc,local_4c,local_8c);
  puVar2 = local_cc;
  puVar3 = param_1;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[8] = *param_2;
  param_1[9] = param_2[1];
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

