
void FUN_007d7740(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  int in_ECX;
  ushort *puVar11;
  float *pfVar12;
  float *pfVar13;
  int unaff_EDI;
  int local_124;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_f4 = *(float *)(unaff_EDI + 0x14);
  local_f8 = *(float *)(unaff_EDI + 0x10);
  local_f0 = *(float *)(unaff_EDI + 0x18);
  D3DXVec3Normalize(&local_f8,&local_f8);
  local_124 = 0;
  if (0 < param_1) {
    puVar11 = (ushort *)(param_2 + 4);
    do {
      iVar9 = (uint)*puVar11 * 0xc;
      iVar3 = (uint)puVar11[-2] * 0xc;
      fVar1 = *(float *)(iVar9 + in_ECX) - *(float *)(iVar3 + in_ECX);
      iVar4 = (uint)puVar11[-1] * 0xc;
      fVar2 = *(float *)(iVar9 + 4 + in_ECX) - *(float *)(iVar3 + 4 + in_ECX);
      fVar5 = *(float *)(iVar9 + 8 + in_ECX) - *(float *)(iVar3 + 8 + in_ECX);
      fVar6 = *(float *)(iVar4 + in_ECX) - *(float *)(iVar3 + in_ECX);
      fVar7 = *(float *)(iVar4 + 4 + in_ECX) - *(float *)(iVar3 + 4 + in_ECX);
      fVar8 = *(float *)(iVar4 + 8 + in_ECX) - *(float *)(iVar3 + 8 + in_ECX);
      local_104 = fVar5 * fVar7 - fVar2 * fVar8;
      local_100 = fVar1 * fVar8 - fVar6 * fVar5;
      local_fc = fVar6 * fVar2 - fVar1 * fVar7;
      D3DXVec3Normalize(&local_104,&local_104);
      if (0.25 < local_f0 * local_fc + local_f8 * local_104 + local_f4 * local_100) {
        local_74 = *(undefined4 *)(iVar3 + 8 + in_ECX);
        local_7c = *(undefined4 *)(iVar3 + in_ECX);
        local_78 = *(undefined4 *)(iVar3 + 4 + in_ECX);
        local_70 = *(undefined4 *)(iVar4 + in_ECX);
        local_68 = *(undefined4 *)(iVar4 + 8 + in_ECX);
        local_6c = *(undefined4 *)(iVar4 + 4 + in_ECX);
        local_64 = *(undefined4 *)(iVar9 + in_ECX);
        local_60 = *(undefined4 *)(iVar9 + 4 + in_ECX);
        local_5c = *(undefined4 *)(iVar9 + 8 + in_ECX);
        local_ec = *(undefined4 *)(iVar3 + param_3);
        local_e8 = *(undefined4 *)(iVar3 + 4 + param_3);
        local_e4 = *(undefined4 *)(iVar3 + 8 + param_3);
        local_e0 = *(undefined4 *)(iVar4 + param_3);
        local_dc = *(undefined4 *)(iVar4 + 4 + param_3);
        local_d8 = *(undefined4 *)(iVar4 + 8 + param_3);
        local_d4 = *(undefined4 *)(iVar9 + param_3);
        local_d0 = *(undefined4 *)(iVar9 + 4 + param_3);
        local_cc = *(undefined4 *)(iVar9 + 8 + param_3);
        iVar9 = FUN_007d7b30(unaff_EDI,&local_7c,&local_7c);
        if ((iVar9 != 0) && (iVar9 = FUN_007d7600(iVar9,&local_7c,&local_ec), iVar9 == 0)) break;
      }
      puVar11 = puVar11 + 3;
      local_124 = local_124 + 1;
    } while (local_124 < param_1);
  }
  fVar1 = *(float *)(unaff_EDI + 0x40);
  iVar9 = 0;
  fVar2 = *(float *)(unaff_EDI + 0x44);
  if (0 < *(int *)(unaff_EDI + 0xa8)) {
    pfVar10 = (float *)(unaff_EDI + 0x20b8);
    pfVar12 = (float *)(unaff_EDI + 0x2cb0);
    pfVar13 = (float *)(unaff_EDI + 0xcc);
    do {
      iVar9 = iVar9 + 1;
      fVar6 = pfVar10[-2] - *(float *)(unaff_EDI + 0x1c);
      fVar7 = pfVar10[-1] - *(float *)(unaff_EDI + 0x20);
      fVar8 = *pfVar10 - *(float *)(unaff_EDI + 0x24);
      fVar5 = (fVar8 * *(float *)(unaff_EDI + 0x30) +
              fVar7 * *(float *)(unaff_EDI + 0x2c) + fVar6 * *(float *)(unaff_EDI + 0x28)) *
              (1.0 / fVar1) + 0.5;
      fVar6 = (fVar7 * *(float *)(unaff_EDI + 0x38) + *(float *)(unaff_EDI + 0x34) * fVar6 +
              *(float *)(unaff_EDI + 0x3c) * fVar8) * (1.0 / fVar2) + 0.5;
      *pfVar12 = fVar5;
      pfVar12[1] = fVar6;
      pfVar13[-1] = fVar5;
      *pfVar13 = fVar6;
      pfVar10 = pfVar10 + 3;
      pfVar12 = pfVar12 + 2;
      pfVar13 = pfVar13 + 8;
    } while (iVar9 < *(int *)(unaff_EDI + 0xa8));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

