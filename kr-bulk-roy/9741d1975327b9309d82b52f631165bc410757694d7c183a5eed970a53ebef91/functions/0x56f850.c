
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f850(int param_1,float param_2,float param_3)

{
  int in_ECX;
  float *unaff_ESI;
  float *pfStack_40;
  float *pfStack_3c;
  float fStack_38;
  float local_34;
  float fStack_30;
  float local_2c;
  float local_28;
  float local_24;
  float fStack_20;
  float local_1c;
  float local_18;
  uint local_14;
  float local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&fStack_38;
  local_2c = 180.0 / _DAT_00d6a24c;
  local_24 = *(float *)(*(int *)(param_1 + 0x74) + in_ECX * 8);
  local_1c = *(float *)(*(int *)(param_1 + 0x74) + in_ECX * 8 + 4);
  pfStack_40 = &local_18;
  local_34 = _DAT_00d6a24c * 100.0;
  local_28 = 220.0 / _DAT_00d6a24c;
  local_18 = param_2 - local_24;
  local_14 = 0;
  local_10 = param_3 - local_1c;
  pfStack_3c = pfStack_40;
  D3DXVec3Normalize();
  *unaff_ESI = local_2c;
  fStack_38 = local_2c - param_2;
  unaff_ESI[1] = local_24;
  if (0.0 < fStack_20) {
    if (local_18 <= 0.0) {
      if (0.0 <= local_18) goto LAB_0056f9fe;
      if (fStack_30 + param_3 < local_24) {
        pfStack_3c = (float *)(fStack_38 / ((fStack_30 + (local_24 - param_3)) / (float)pfStack_3c))
        ;
        *unaff_ESI = local_2c - (float)pfStack_3c;
        param_3 = local_34 + param_3;
        goto LAB_0056f96e;
      }
    }
    else if (local_24 < param_3 - fStack_30) {
      pfStack_3c = (float *)(fStack_38 / (((param_3 + local_24) - fStack_30) / (float)pfStack_3c));
      *unaff_ESI = local_2c - (float)pfStack_3c;
      param_3 = param_3 - local_34;
LAB_0056f96e:
      unaff_ESI[1] = param_3;
    }
    if (*unaff_ESI < param_2 - fStack_30) {
      *unaff_ESI = param_2 - local_34;
      __security_check_cookie(local_14 ^ (uint)&pfStack_40);
      return;
    }
    goto LAB_0056fae2;
  }
LAB_0056f9fe:
  if (0.0 <= fStack_20) goto LAB_0056fae2;
  if (0.0 <= local_18) {
    if (local_18 <= 0.0) goto LAB_0056fae2;
    if (local_24 < param_3 - fStack_30) {
      pfStack_3c = (float *)(fStack_38 / (((param_3 + local_24) - fStack_30) / (float)pfStack_3c));
      *unaff_ESI = (float)pfStack_3c + local_2c;
      param_3 = param_3 - local_34;
      goto LAB_0056fa5b;
    }
  }
  else if (fStack_30 + param_3 < local_24) {
    pfStack_3c = (float *)(fStack_38 / ((fStack_30 + (local_24 - param_3)) / (float)pfStack_3c));
    *unaff_ESI = local_2c - (float)pfStack_3c;
    param_3 = local_34 + param_3;
LAB_0056fa5b:
    unaff_ESI[1] = param_3;
  }
  if (fStack_30 + param_2 < *unaff_ESI) {
    *unaff_ESI = param_2 + local_34;
    __security_check_cookie(local_14 ^ (uint)&pfStack_40);
    return;
  }
LAB_0056fae2:
  __security_check_cookie(local_14 ^ (uint)&pfStack_40);
  return;
}

