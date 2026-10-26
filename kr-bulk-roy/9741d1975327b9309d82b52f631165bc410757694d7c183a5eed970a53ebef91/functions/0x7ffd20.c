
void FUN_007ffd20(int param_1)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  float10 fVar6;
  undefined1 auStack_44 [4];
  int *local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c [4];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_44;
  iVar3 = *(int *)(in_ECX + 8);
  local_28 = *(float *)(param_1 + iVar3 * 0xc);
  local_24 = *(float *)(param_1 + 4 + iVar3 * 0xc);
  local_20 = *(float *)(param_1 + iVar3 * 0xc + 8);
  *(float *)(in_ECX + 0x2c) = local_28;
  *(float *)(in_ECX + 0x30) = local_24;
  local_40 = (int *)(in_ECX + 0xc);
  local_38 = param_1;
  *(float *)(in_ECX + 0x34) = local_20;
  iVar3 = 0;
  pfVar4 = (float *)(in_ECX + 0x38);
  do {
    iVar1 = local_38 + *local_40 * 0xc;
    *pfVar4 = *(float *)(local_38 + *local_40 * 0xc);
    pfVar4[1] = *(float *)(iVar1 + 4);
    pfVar4[2] = *(float *)(iVar1 + 8);
    local_34 = local_28 - *pfVar4;
    local_30 = local_24 - pfVar4[1];
    local_2c = local_20 - pfVar4[2];
    local_3c = local_2c * local_2c + local_34 * local_34 + local_30 * local_30;
    fVar6 = (float10)FUN_008ff870();
    local_40 = local_40 + 1;
    local_1c[iVar3] = (float)fVar6;
    iVar3 = iVar3 + 1;
    pfVar4 = pfVar4 + 3;
  } while (iVar3 < 4);
  if (local_1c[0] <= local_1c[1]) {
    local_40 = (int *)local_1c[1];
  }
  else {
    local_40 = (int *)local_1c[0];
  }
  if (local_1c[2] <= local_1c[3]) {
    local_3c = local_1c[3];
  }
  else {
    local_3c = local_1c[2];
  }
  if ((float)local_40 <= local_3c) {
    fVar2 = local_1c[3];
    if (local_1c[3] < local_1c[2]) goto LAB_007ffe7b;
  }
  else {
    local_1c[2] = local_1c[0];
    fVar2 = local_1c[1];
    if (local_1c[1] < local_1c[0]) goto LAB_007ffe7b;
  }
  local_1c[2] = fVar2;
LAB_007ffe7b:
  piVar5 = (int *)(in_ECX + 0x1c);
  iVar3 = 4;
  *(float *)(in_ECX + 0x68) = local_1c[2];
  do {
    if (*piVar5 != 0) {
      FUN_007ffd20(local_38);
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  __security_check_cookie(local_c ^ (uint)auStack_44);
  return;
}

