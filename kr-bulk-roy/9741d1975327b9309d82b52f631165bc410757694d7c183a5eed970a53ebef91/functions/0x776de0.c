
void FUN_00776de0(float *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 float param_7,undefined4 param_8,undefined4 param_9)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_d0 [64];
  undefined4 local_90 [16];
  undefined4 local_50 [17];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *param_1 = (float)param_2;
  param_1[1] = (float)param_3;
  param_1[2] = 0.0;
  param_1[5] = (float)in_ECX;
  param_1[6] = (float)param_4;
  param_1[7] = 0.0;
  D3DXMatrixScaling(local_50,param_8,param_9,0x3f800000);
  D3DXMatrixTranslation(local_d0,(float)param_5 - 0.5,(float)param_6 - 0.5,0x3f800000);
  D3DXMatrixMultiply(local_90,local_50,local_d0);
  puVar2 = local_90;
  puVar3 = local_50;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar1 = 2;
  do {
    D3DXVec3TransformCoord(param_1,param_1,local_50);
    param_1[4] = param_7;
    param_1 = param_1 + 5;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

