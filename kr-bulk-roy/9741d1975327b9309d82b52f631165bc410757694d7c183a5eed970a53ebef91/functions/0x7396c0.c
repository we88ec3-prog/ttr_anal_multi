
void FUN_007396c0(float *param_1,int *param_2,undefined4 param_3,float param_4,float param_5)

{
  int *in_ECX;
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float local_78 [5];
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_4c;
  float local_48;
  float local_3c;
  float local_38;
  float local_2c;
  float local_28;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_3c = (float)*param_2;
  local_38 = (float)param_2[1];
  local_4c = (float)param_2[2];
  local_48 = local_38;
  local_2c = local_3c;
  local_28 = (float)param_2[3];
  local_58 = local_28;
  local_5c = local_4c;
  local_c = ((float)*in_ECX + 0.5) * (1.0 / param_4);
  local_8 = ((float)in_ECX[1] + 0.5) * (1.0 / param_5);
  local_14 = ((float)in_ECX[2] + 0.5) * (1.0 / param_4);
  local_10 = local_8;
  local_18 = ((float)in_ECX[3] + 0.5) * (1.0 / param_5);
  local_1c = local_14;
  local_78[0] = local_3c;
  local_78[1] = local_38;
  local_78[2] = (float)param_3;
  local_78[3] = 1.0;
  local_64 = local_c;
  local_60 = local_8;
  pfVar2 = local_78;
  pfVar3 = param_1;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_78[0] = local_4c;
  local_78[3] = 1.0;
  local_64 = local_14;
  pfVar2 = local_78;
  pfVar3 = param_1 + 7;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_78[0] = local_3c;
  local_78[1] = local_28;
  local_78[3] = 1.0;
  local_64 = local_c;
  local_60 = local_18;
  pfVar2 = local_78;
  pfVar3 = param_1 + 0xe;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_78[3] = 1.0;
  pfVar2 = local_78;
  pfVar3 = param_1 + 0x15;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_78[0] = local_4c;
  local_78[1] = local_38;
  local_78[3] = 1.0;
  local_64 = local_14;
  local_60 = local_8;
  pfVar2 = local_78;
  pfVar3 = param_1 + 0x1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  local_78[1] = local_28;
  local_78[3] = 1.0;
  local_60 = local_18;
  pfVar2 = local_78;
  pfVar3 = param_1 + 0x23;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar3 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
  }
  return;
}

