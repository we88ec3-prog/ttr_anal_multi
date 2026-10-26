
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007398a0(int param_1,float param_2,undefined4 param_3,undefined4 param_4,float param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int *in_EAX;
  float *pfVar9;
  int *in_ECX;
  int iVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  float local_20 [5];
  float local_c;
  float local_8;
  
  fVar1 = (float)*in_ECX;
  fVar2 = (float)in_ECX[1];
  fVar3 = (float)in_ECX[2];
  fVar4 = (float)in_ECX[3];
  fVar5 = ((float)*in_EAX + 0.5) * (1.0 / param_5);
  fVar8 = ((float)in_EAX[1] + 0.5) * (1.0 / param_6);
  fVar6 = ((float)in_EAX[2] + 0.5) * (1.0 / param_5);
  fVar7 = ((float)in_EAX[3] + 0.5) * (1.0 / param_6);
  if ((_DAT_00fe3840 & 1) == 0) {
    _DAT_00fe3840 = _DAT_00fe3840 | 1;
    DAT_00fe37f0 = 0;
    DAT_00fe37f4 = 0xbf800000;
    _DAT_00fe3820 = 0xbf800000;
    DAT_00fe37f8 = 0;
    DAT_00fe37fc = 0;
    DAT_00fe3804 = 0;
    DAT_00fe3808 = 0;
    DAT_00fe380c = 0;
    _DAT_00fe3810 = 0;
    _DAT_00fe3818 = 0;
    _DAT_00fe381c = 0;
    _DAT_00fe3824 = 0;
    _DAT_00fe3828 = 0;
    _DAT_00fe382c = 0;
    _DAT_00fe3830 = 0;
    _DAT_00fe3834 = 0;
    _DAT_00fe3838 = 0;
    _DAT_00fe383c = 0;
    DAT_00fe3800 = 0x3f800000;
    _DAT_00fe3814 = 0x3f800000;
  }
  pfVar9 = (float *)&DAT_00fe37f8;
  pfVar11 = (float *)(param_1 + 0x38);
  do {
    local_20[4] = (float)param_4;
    local_20[0] = fVar1 + pfVar9[-2];
    local_20[1] = fVar2 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    local_20[3] = pfVar9[1] + 1.0;
    local_c = fVar5;
    local_8 = fVar8;
    pfVar12 = local_20;
    pfVar13 = pfVar11 + -0xe;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
    local_20[0] = fVar3 + pfVar9[-2];
    local_20[1] = fVar2 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    local_20[3] = pfVar9[1] + 1.0;
    local_c = fVar6;
    pfVar12 = local_20;
    pfVar13 = pfVar11 + -7;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
    local_20[0] = fVar1 + pfVar9[-2];
    local_20[1] = fVar4 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    local_20[3] = pfVar9[1] + 1.0;
    local_c = fVar5;
    local_8 = fVar7;
    pfVar12 = local_20;
    pfVar13 = pfVar11;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
    local_20[0] = fVar1 + pfVar9[-2];
    local_20[1] = fVar4 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    local_20[3] = pfVar9[1] + 1.0;
    pfVar12 = local_20;
    pfVar13 = pfVar11 + 7;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
    local_20[0] = fVar3 + pfVar9[-2];
    local_20[1] = fVar2 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    local_20[3] = pfVar9[1] + 1.0;
    local_c = fVar6;
    local_8 = fVar8;
    pfVar12 = local_20;
    pfVar13 = pfVar11 + 0xe;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
    pfVar12 = pfVar9 + 1;
    local_20[0] = fVar3 + pfVar9[-2];
    local_20[1] = fVar4 + pfVar9[-1];
    local_20[2] = *pfVar9 + param_2;
    pfVar13 = pfVar11 + 0x15;
    pfVar9 = pfVar9 + 4;
    local_20[3] = *pfVar12 + 1.0;
    pfVar11 = pfVar11 + 0x2a;
    local_8 = fVar7;
    pfVar12 = local_20;
    for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
      *pfVar13 = *pfVar12;
      pfVar12 = pfVar12 + 1;
      pfVar13 = pfVar13 + 1;
    }
  } while ((int)pfVar9 < 0xfe3838);
  local_20[0] = fVar1;
  local_20[4] = (float)param_3;
  local_20[1] = fVar2;
  local_20[2] = param_2;
  local_20[3] = 1.0;
  local_c = fVar5;
  local_8 = fVar8;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 0x2a0);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  local_20[0] = fVar3;
  local_20[3] = 1.0;
  local_c = fVar6;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 700);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  local_20[0] = fVar1;
  local_20[1] = fVar4;
  local_20[3] = 1.0;
  local_c = fVar5;
  local_8 = fVar7;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 0x2d8);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  local_20[3] = 1.0;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 0x2f4);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  local_20[0] = fVar3;
  local_20[1] = fVar2;
  local_20[3] = 1.0;
  local_c = fVar6;
  local_8 = fVar8;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 0x310);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  local_20[1] = fVar4;
  local_20[3] = 1.0;
  local_8 = fVar7;
  pfVar9 = local_20;
  pfVar11 = (float *)(param_1 + 0x32c);
  for (iVar10 = 7; iVar10 != 0; iVar10 = iVar10 + -1) {
    *pfVar11 = *pfVar9;
    pfVar9 = pfVar9 + 1;
    pfVar11 = pfVar11 + 1;
  }
  return;
}

