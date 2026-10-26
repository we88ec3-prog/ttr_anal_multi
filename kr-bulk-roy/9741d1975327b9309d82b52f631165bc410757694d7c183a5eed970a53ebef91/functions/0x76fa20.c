
void FUN_0076fa20(float *param_1,int param_2,int param_3,float param_4,int param_5,int param_6,
                 int param_7,int param_8,undefined4 param_9,undefined4 param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 local_cc [64];
  undefined4 local_8c [16];
  undefined4 local_4c [17];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  fVar1 = (float)param_5;
  fVar2 = (float)param_6;
  *param_1 = fVar1;
  param_1[1] = fVar2;
  param_1[2] = 0.0;
  fVar3 = (float)param_8;
  param_1[5] = fVar1;
  param_1[6] = fVar3;
  param_1[7] = 0.0;
  fVar4 = (float)param_7;
  param_1[10] = fVar4;
  param_1[0xb] = fVar2;
  param_1[0xc] = 0.0;
  param_1[0xf] = fVar4;
  param_1[0x10] = fVar3;
  param_1[0x11] = 0.0;
  param_1[0x14] = fVar1;
  param_1[0x15] = fVar2;
  param_1[0x16] = 0.0;
  param_1[0x19] = fVar4;
  param_1[0x1a] = fVar2;
  param_1[0x1b] = 0.0;
  param_1[0x1e] = fVar1;
  param_1[0x1f] = fVar3;
  param_1[0x20] = 0.0;
  param_1[0x23] = fVar4;
  param_1[0x24] = fVar3;
  param_1[0x25] = 0.0;
  D3DXMatrixScaling(local_4c,param_9,param_10,0);
  D3DXMatrixTranslation(local_cc,(float)param_2 - 0.5,(float)param_3 - 0.5,0);
  D3DXMatrixMultiply(local_8c,local_4c,local_cc);
  puVar6 = local_8c;
  puVar7 = local_4c;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  iVar5 = 8;
  do {
    D3DXVec3TransformCoord(param_1,param_1,local_4c);
    param_1[4] = param_4;
    param_1 = param_1 + 5;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

