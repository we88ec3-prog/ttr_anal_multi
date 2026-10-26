
void FUN_007d7c50(int param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  float *pfVar11;
  int iVar12;
  int in_ECX;
  float *in_EDX;
  int iVar13;
  int unaff_ESI;
  float *unaff_EDI;
  int local_38;
  float *local_34;
  int local_24;
  int local_1c;
  undefined4 local_18;
  char acStack_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar13 = 0;
  local_1c = 0;
  local_24 = 0;
  if (1 < param_1) {
    pfVar11 = (float *)(unaff_ESI + 0x14);
    do {
      bVar8 = pfVar11[-3] * unaff_EDI[2] + pfVar11[-4] * unaff_EDI[1] + pfVar11[-5] * *unaff_EDI +
              unaff_EDI[3] < 0.0;
      acStack_14[iVar13] = bVar8;
      local_1c = local_1c + (uint)bVar8;
      bVar8 = *pfVar11 * unaff_EDI[2] + pfVar11[-1] * unaff_EDI[1] + pfVar11[-2] * *unaff_EDI +
              unaff_EDI[3] < 0.0;
      acStack_14[iVar13 + 1] = bVar8;
      local_24 = local_24 + (uint)bVar8;
      iVar13 = iVar13 + 2;
      pfVar11 = pfVar11 + 6;
    } while (iVar13 < param_1 + -1);
  }
  iVar12 = 0;
  if (iVar13 < param_1) {
    pfVar11 = (float *)(unaff_ESI + iVar13 * 0xc);
    if (0.0 <= unaff_EDI[2] * pfVar11[2] +
               *pfVar11 * *unaff_EDI + unaff_EDI[1] * *(float *)(unaff_ESI + 4 + iVar13 * 0xc) +
               unaff_EDI[3]) {
      acStack_14[iVar13] = '\0';
      iVar12 = 0;
    }
    else {
      acStack_14[iVar13] = '\x01';
      iVar12 = 1;
    }
  }
  if (local_1c + local_24 + iVar12 == param_1) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_38 = 0;
  local_34 = in_EDX;
  if (0 < param_1) {
    do {
      iVar13 = param_1;
      if (local_38 != 0) {
        iVar13 = local_38;
      }
      if (acStack_14[local_38] == '\0') {
        if (acStack_14[iVar13 + -1] != '\0') {
          local_18 = local_38 * 0xc;
          iVar13 = (iVar13 + -1) * 0xc;
          pfVar11 = (float *)(unaff_ESI + 4 + local_18);
          pfVar1 = (float *)(unaff_ESI + 8 + local_18);
          pfVar2 = (float *)(unaff_ESI + 4 + iVar13);
          pfVar3 = (float *)(unaff_ESI + 8 + iVar13);
          fVar10 = (*pfVar1 * unaff_EDI[2] +
                    unaff_EDI[1] * *pfVar11 + *(float *)(unaff_ESI + local_18) * *unaff_EDI +
                   unaff_EDI[3]) /
                   ((*pfVar1 - *pfVar3) * unaff_EDI[2] +
                   (*(float *)(unaff_ESI + local_18) - *(float *)(unaff_ESI + iVar13)) * *unaff_EDI
                   + (*pfVar11 - *pfVar2) * unaff_EDI[1]);
          fVar4 = *pfVar2;
          fVar5 = *pfVar3;
          fVar9 = 1.0 - fVar10;
          fVar6 = *pfVar11;
          fVar7 = *pfVar1;
          *local_34 = fVar9 * *(float *)(unaff_ESI + local_18) +
                      fVar10 * *(float *)(unaff_ESI + iVar13);
          local_34[1] = fVar9 * fVar6 + fVar10 * fVar4;
          local_34[2] = fVar7 * fVar9 + fVar5 * fVar10;
          fVar4 = *(float *)(iVar13 + 4 + in_ECX);
          fVar5 = *(float *)(iVar13 + 8 + in_ECX);
          fVar6 = *(float *)(local_18 + 4 + in_ECX);
          fVar7 = *(float *)(local_18 + 8 + in_ECX);
          *param_2 = fVar9 * *(float *)(local_18 + in_ECX) + *(float *)(iVar13 + in_ECX) * fVar10;
          param_2[1] = fVar6 * fVar9 + fVar4 * fVar10;
          param_2[2] = fVar9 * fVar7 + fVar5 * fVar10;
          D3DXVec3Normalize(param_2,param_2);
          local_34 = local_34 + 3;
          param_2 = param_2 + 3;
        }
        local_18 = local_38 * 0xc;
        *local_34 = *(float *)(unaff_ESI + local_18);
        local_34[1] = *(float *)(unaff_ESI + 4 + local_18);
        local_34[2] = *(float *)(unaff_ESI + 8 + local_18);
        *param_2 = *(float *)(local_18 + in_ECX);
        param_2[1] = *(float *)(local_18 + 4 + in_ECX);
        local_34 = local_34 + 3;
        param_2[2] = *(float *)(local_18 + 8 + in_ECX);
        param_2 = param_2 + 3;
      }
      else if (acStack_14[iVar13 + -1] == '\0') {
        iVar13 = (iVar13 + -1) * 0xc;
        local_18 = local_38 * 0xc;
        pfVar11 = (float *)(unaff_ESI + 4 + iVar13);
        pfVar1 = (float *)(unaff_ESI + 8 + iVar13);
        pfVar2 = (float *)(unaff_ESI + 4 + local_18);
        pfVar3 = (float *)(unaff_ESI + 8 + local_18);
        fVar9 = (*pfVar1 * unaff_EDI[2] +
                 unaff_EDI[1] * *pfVar11 + *(float *)(unaff_ESI + iVar13) * *unaff_EDI +
                unaff_EDI[3]) /
                ((*pfVar1 - *pfVar3) * unaff_EDI[2] +
                (*pfVar11 - *pfVar2) * unaff_EDI[1] +
                (*(float *)(unaff_ESI + iVar13) - *(float *)(unaff_ESI + local_18)) * *unaff_EDI);
        fVar4 = *pfVar2;
        fVar5 = *pfVar3;
        fVar10 = 1.0 - fVar9;
        fVar6 = *pfVar11;
        fVar7 = *pfVar1;
        *local_34 = fVar10 * *(float *)(unaff_ESI + iVar13) +
                    fVar9 * *(float *)(unaff_ESI + local_18);
        local_34[1] = fVar10 * fVar6 + fVar9 * fVar4;
        local_34[2] = fVar7 * fVar10 + fVar5 * fVar9;
        fVar4 = *(float *)(local_18 + 4 + in_ECX);
        fVar5 = *(float *)(local_18 + 8 + in_ECX);
        fVar6 = *(float *)(iVar13 + 4 + in_ECX);
        fVar7 = *(float *)(iVar13 + 8 + in_ECX);
        *param_2 = *(float *)(iVar13 + in_ECX) * fVar10 + *(float *)(local_18 + in_ECX) * fVar9;
        param_2[1] = fVar6 * fVar10 + fVar4 * fVar9;
        param_2[2] = fVar10 * fVar7 + fVar5 * fVar9;
        D3DXVec3Normalize(param_2,param_2);
        local_34 = local_34 + 3;
        param_2 = param_2 + 3;
      }
      local_38 = local_38 + 1;
    } while (local_38 < param_1);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

