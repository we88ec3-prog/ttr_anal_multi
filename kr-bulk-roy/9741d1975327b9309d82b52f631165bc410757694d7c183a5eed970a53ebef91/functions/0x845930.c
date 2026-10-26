
void FUN_00845930(int param_1,int param_2,int param_3,int param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int local_14;
  
  local_14 = 0;
  if (3 < param_4) {
    iVar10 = (param_4 - 4U >> 2) + 1;
    local_14 = iVar10 * 4;
    pfVar7 = (float *)(param_2 + 0x14);
    pfVar8 = (float *)(param_1 + 0x18);
    pfVar9 = (float *)(param_3 + 0x20);
    do {
      fVar1 = pfVar9[-7];
      fVar2 = pfVar7[-4];
      fVar3 = pfVar9[-6];
      fVar4 = pfVar7[-3];
      fVar5 = pfVar7[-4];
      fVar6 = pfVar7[-3];
      pfVar8[-6] = pfVar7[-5] + (pfVar9[-8] - pfVar7[-5]) * param_5;
      pfVar8[-5] = fVar5 + (fVar1 - fVar2) * param_5;
      pfVar8[-4] = fVar6 + (fVar3 - fVar4) * param_5;
      fVar1 = *(float *)((param_3 - param_2) + -4 + (int)pfVar7);
      fVar2 = pfVar7[-1];
      fVar3 = *(float *)((param_3 - param_2) + (int)pfVar7);
      fVar4 = *pfVar7;
      fVar5 = pfVar7[-1];
      fVar6 = *pfVar7;
      pfVar8[-3] = pfVar7[-2] + (pfVar9[-5] - pfVar7[-2]) * param_5;
      pfVar8[-2] = fVar5 + (fVar1 - fVar2) * param_5;
      pfVar8[-1] = (fVar3 - fVar4) * param_5 + fVar6;
      fVar1 = pfVar9[-1];
      fVar2 = pfVar7[2];
      fVar3 = *pfVar9;
      fVar4 = pfVar7[3];
      iVar10 = iVar10 + -1;
      fVar5 = pfVar7[2];
      fVar6 = pfVar7[3];
      *pfVar8 = pfVar7[1] + (pfVar9[-2] - pfVar7[1]) * param_5;
      pfVar8[1] = fVar5 + (fVar1 - fVar2) * param_5;
      pfVar8[2] = fVar6 + (fVar3 - fVar4) * param_5;
      fVar1 = pfVar9[2];
      fVar2 = pfVar7[5];
      fVar3 = pfVar9[3];
      fVar4 = pfVar7[6];
      fVar5 = pfVar7[5];
      fVar6 = pfVar7[6];
      pfVar8[3] = pfVar7[4] + (pfVar9[1] - pfVar7[4]) * param_5;
      pfVar8[4] = fVar5 + (fVar1 - fVar2) * param_5;
      pfVar8[5] = fVar6 + (fVar3 - fVar4) * param_5;
      pfVar7 = pfVar7 + 0xc;
      pfVar8 = pfVar8 + 0xc;
      pfVar9 = pfVar9 + 0xc;
    } while (iVar10 != 0);
  }
  if (local_14 < param_4) {
    param_4 = param_4 - local_14;
    pfVar7 = (float *)(local_14 * 0xc + 8 + param_2);
    pfVar8 = (float *)(local_14 * 0xc + param_1);
    do {
      pfVar9 = pfVar7 + 3;
      param_4 = param_4 + -1;
      fVar1 = *(float *)((param_3 - param_2) + -0x10 + (int)pfVar9);
      fVar2 = pfVar7[-1];
      fVar3 = *(float *)((param_3 - param_2) + -0xc + (int)pfVar9);
      fVar4 = *pfVar7;
      fVar5 = pfVar7[-1];
      fVar6 = *pfVar7;
      *pfVar8 = (*(float *)((param_3 - param_1) + (int)pfVar8) - pfVar7[-2]) * param_5 + pfVar7[-2];
      pfVar8[1] = (fVar1 - fVar2) * param_5 + fVar5;
      pfVar8[2] = (fVar3 - fVar4) * param_5 + fVar6;
      pfVar7 = pfVar9;
      pfVar8 = pfVar8 + 3;
    } while (param_4 != 0);
  }
  return;
}

