
void FUN_008427c0(int param_1,int param_2,undefined4 param_3,float param_4,float param_5,
                 float param_6)

{
  float *pfVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  int iVar4;
  
  while( true ) {
    iVar4 = in_ECX * 2 + 2;
    if (param_2 <= iVar4) break;
    pfVar1 = (float *)(iVar4 * 0x50 + param_1);
    if (pfVar1[2] * param_6 + param_4 * *pfVar1 + pfVar1[1] * param_5 <
        pfVar1[-0x12] * param_6 +
        pfVar1[-0x14] * param_4 + *(float *)(iVar4 * 0x50 + -0x4c + param_1) * param_5) {
      iVar4 = in_ECX * 2 + 1;
    }
    puVar2 = (undefined4 *)(iVar4 * 0x50 + param_1);
    puVar3 = (undefined4 *)(in_ECX * 0x50 + param_1);
    if (puVar3 != puVar2) {
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      if (puVar3 + 3 != puVar2 + 3) {
        puVar3[6] = puVar2[6];
        puVar3[3] = puVar2[3];
        puVar3[4] = puVar2[4];
        puVar3[5] = puVar2[5];
      }
      puVar3[7] = puVar2[7];
      puVar3[8] = puVar2[8];
      puVar3[9] = puVar2[9];
      puVar3[10] = puVar2[10];
    }
    puVar3[0xb] = puVar2[0xb];
    puVar3[0xc] = puVar2[0xc];
    puVar3[0xd] = puVar2[0xd];
    puVar3[0xe] = puVar2[0xe];
    puVar3[0xf] = puVar2[0xf];
    puVar3[0x10] = puVar2[0x10];
    puVar3[0x11] = puVar2[0x11];
    puVar3[0x12] = puVar2[0x12];
    puVar3[0x13] = puVar2[0x13];
    in_ECX = iVar4;
  }
  if (iVar4 == param_2) {
    puVar2 = (undefined4 *)(param_1 + -0x50 + param_2 * 0x50);
    puVar3 = (undefined4 *)(in_ECX * 0x50 + param_1);
    if (puVar3 != puVar2) {
      *puVar3 = *puVar2;
      puVar3[1] = puVar2[1];
      puVar3[2] = puVar2[2];
      if (puVar3 + 3 != puVar2 + 3) {
        puVar3[6] = puVar2[6];
        puVar3[3] = puVar2[3];
        puVar3[4] = puVar2[4];
        puVar3[5] = puVar2[5];
      }
      puVar3[7] = puVar2[7];
      puVar3[8] = puVar2[8];
      puVar3[9] = puVar2[9];
      puVar3[10] = puVar2[10];
    }
    puVar3[0xb] = puVar2[0xb];
    puVar3[0xc] = puVar2[0xc];
    puVar3[0xd] = puVar2[0xd];
    puVar3[0xe] = puVar2[0xe];
    puVar3[0xf] = puVar2[0xf];
    puVar3[0x10] = puVar2[0x10];
    puVar3[0x11] = puVar2[0x11];
    puVar3[0x12] = puVar2[0x12];
    puVar3[0x13] = puVar2[0x13];
  }
  FUN_00842c30(param_1);
  return;
}

