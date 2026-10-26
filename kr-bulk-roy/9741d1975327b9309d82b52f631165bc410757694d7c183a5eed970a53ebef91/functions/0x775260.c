
void FUN_00775260(int param_1,float param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,undefined4 param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  float *pfVar7;
  undefined4 *puVar8;
  undefined1 local_cc [64];
  undefined4 local_8c [16];
  undefined4 local_4c [17];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  fVar1 = (float)param_5;
  pfVar7 = (float *)(param_1 + 4);
  fVar2 = (float)param_4;
  *pfVar7 = fVar1;
  *(float *)(param_1 + 8) = fVar2;
  *(undefined4 *)(param_1 + 0xc) = 0;
  fVar3 = (float)param_3;
  fVar4 = (float)param_6;
  *(float *)(param_1 + 0x18) = fVar3;
  *(float *)(param_1 + 0x1c) = fVar4;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(float *)(param_1 + 0x2c) = fVar3;
  *(float *)(param_1 + 0x30) = fVar2;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(float *)(param_1 + 0x40) = fVar1;
  *(float *)(param_1 + 0x44) = fVar4;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(float *)(param_1 + 0x54) = fVar3;
  *(float *)(param_1 + 0x58) = fVar4;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(float *)(param_1 + 0x68) = fVar1;
  *(float *)(param_1 + 0x6c) = fVar2;
  *(undefined4 *)(param_1 + 0x70) = 0;
  D3DXMatrixScaling(local_4c,param_7,param_8,0);
  D3DXMatrixTranslation(local_cc,0xbf000000,0xbf000000,0);
  D3DXMatrixMultiply(local_8c,local_4c,local_cc);
  puVar6 = local_8c;
  puVar8 = local_4c;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar5 = 6;
  do {
    D3DXVec3TransformCoord(pfVar7,pfVar7,local_4c);
    pfVar7[4] = param_2;
    pfVar7 = pfVar7 + 5;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

