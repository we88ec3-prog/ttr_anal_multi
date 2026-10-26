
void FUN_007f8e00(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int *in_ECX;
  float *pfVar10;
  int iVar11;
  int iVar12;
  
  fVar1 = (float)in_ECX[0x49];
  iVar12 = 0;
  if (in_ECX[0x33] != 0) {
    iVar11 = 0;
    do {
      pfVar10 = (float *)(in_ECX[0x32] + iVar11);
      fVar2 = *pfVar10 + *(float *)(in_ECX[0x32] + 0xc + iVar11) * param_1;
      *pfVar10 = fVar2;
      fVar3 = pfVar10[4] * param_1 + pfVar10[1];
      pfVar10[1] = fVar3;
      fVar4 = pfVar10[2] + pfVar10[5] * param_1;
      pfVar10[2] = fVar4;
      fVar5 = pfVar10[4] * pfVar10[4] + pfVar10[3] * pfVar10[3] + pfVar10[5] * pfVar10[5];
      fVar6 = pfVar10[3] + pfVar10[6] * param_1;
      fVar7 = pfVar10[4] + pfVar10[7] * param_1;
      fVar8 = pfVar10[5] + pfVar10[8] * param_1;
      fVar9 = fVar8 * fVar8 + fVar6 * fVar6 + fVar7 * fVar7;
      if (((fVar5 < fVar9) && (fVar9 < fVar1 * fVar1)) || (fVar9 < fVar5)) {
        pfVar10[3] = fVar6;
        pfVar10[4] = fVar7;
        pfVar10[5] = fVar8;
      }
      if (((((float)in_ECX[0x39] < fVar2 == ((float)in_ECX[0x39] == fVar2)) ||
           ((float)in_ECX[0x3a] < fVar3 == ((float)in_ECX[0x3a] == fVar3))) ||
          (((float)in_ECX[0x3b] < fVar4 == ((float)in_ECX[0x3b] == fVar4) ||
           (((float)in_ECX[0x3c] < fVar2 || ((float)in_ECX[0x3d] < fVar3)))))) ||
         ((float)in_ECX[0x3e] < fVar4)) {
        (**(code **)(*in_ECX + 0x28))(pfVar10);
      }
      iVar12 = iVar12 + 1;
      iVar11 = iVar11 + 0x5c;
    } while (iVar12 != in_ECX[0x33]);
  }
  return;
}

