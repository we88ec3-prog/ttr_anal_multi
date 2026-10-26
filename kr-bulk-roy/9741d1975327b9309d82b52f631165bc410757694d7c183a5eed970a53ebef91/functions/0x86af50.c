
void FUN_0086af50(int param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float fVar4;
  float fVar5;
  float10 fVar6;
  float10 fVar7;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  local_48 = 0.0;
  local_44 = 0.0;
  local_40 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  if (in_ECX == (int *)0x0) {
    fVar2 = 0.0;
    fVar4 = 0.0;
    fVar5 = 0.0;
  }
  else {
    pfVar1 = (float *)(**(code **)(*in_ECX + 4))(&local_48,&stack0x00000010);
    local_54 = *pfVar1;
    local_50 = pfVar1[1];
    local_4c = pfVar1[2];
    fVar5 = *pfVar1;
    fVar4 = pfVar1[1];
    fVar2 = pfVar1[2];
  }
  *param_2 = fVar5;
  param_2[1] = fVar4;
  param_2[2] = fVar2;
  FUN_0089289d();
  FUN_0089289d();
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 0x1b8) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 0x1b8) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  FUN_0089289d();
  FUN_0089289d();
  fVar6 = (float10)FUN_008fef70();
  param_2[0xd] = (float)fVar6;
  fVar6 = (float10)FUN_008ff0a0();
  fVar7 = (float10)FUN_008fef70();
  param_2[0xb] = (float)fVar7 * (float)fVar6;
  fVar7 = (float10)FUN_008ff0a0();
  param_2[0xc] = (float)fVar7 * (float)fVar6;
  if (*(int *)(param_1 + 0x35c) != 0) {
    iVar3 = FUN_00879490();
    if (iVar3 == 1) {
      FUN_00781020(0x3f800000);
      param_2[0xb] = local_54;
      param_2[0xc] = local_50;
      param_2[0xd] = local_4c;
    }
  }
  if (*(int *)(param_1 + 0x364) == 0) {
    FUN_007cd220();
    local_48 = fStack_24 * param_2[2] + *param_2 * fStack_3c + fStack_30 * param_2[1] + fStack_18;
    local_44 = fStack_20 * param_2[2] + *param_2 * fStack_38 + fStack_2c * param_2[1] + fStack_14;
    fVar5 = param_2[1];
    fVar4 = *param_2;
    *param_2 = local_48;
    param_2[1] = local_44;
    local_40 = fStack_1c * param_2[2] + fVar4 * fStack_34 + fStack_28 * fVar5 + fStack_10;
    param_2[2] = local_40;
    pfVar1 = (float *)FUN_0077e800();
    param_2[0xb] = *pfVar1;
    param_2[0xc] = pfVar1[1];
    param_2[0xd] = pfVar1[2];
  }
  FUN_00781020(0x3f800000);
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 0x104) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 0x104) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  iVar3 = FUN_0089289d();
  param_2[0xe] = (local_44 - local_48) *
                 ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) + local_48;
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 200) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 200) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  iVar3 = FUN_0089289d();
  param_2[0xf] = (local_44 - local_48) *
                 ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) + local_48;
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 0x17c) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 0x17c) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  iVar3 = FUN_0089289d();
  param_2[0x10] =
       (local_44 - local_48) * ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) +
       local_48;
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 0x140) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 0x140) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  iVar3 = FUN_0089289d();
  param_2[0x12] =
       (local_44 - local_48) * ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) +
       local_48;
  iVar3 = FUN_008fed10();
  local_48 = *(float *)(*(int *)(param_1 + 0x50) + iVar3 * 0xc);
  iVar3 = *(int *)(param_1 + 0x50) + iVar3 * 0xc;
  local_44 = *(float *)(iVar3 + 4);
  local_40 = *(float *)(iVar3 + 8);
  iVar3 = FUN_0089289d();
  param_2[0x14] =
       (local_44 - local_48) * ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) +
       local_48;
  param_2[0x13] = 0.0;
  return;
}

