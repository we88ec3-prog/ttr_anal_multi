
void FUN_007936c0(int *param_1)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  int *in_EAX;
  float *in_EDX;
  float *unaff_ESI;
  
  iVar14 = *in_EAX;
  fVar16 = 1.0 - *unaff_ESI;
  fVar17 = *unaff_ESI * *unaff_ESI;
  if ((*(uint *)(iVar14 + 0x14) & 0x1c00) != 0x800) {
    iVar15 = *param_1;
    if ((*(uint *)(iVar15 + 0x14) & 0x380) != 0x100) {
      fVar18 = (float)(*(int *)(iVar15 + 0x10) - *(int *)(iVar14 + 0x10)) / 3.0;
      fVar1 = *(float *)(iVar15 + 0x1c);
      fVar2 = *(float *)(iVar15 + 0x20);
      fVar3 = *(float *)(iVar15 + 8);
      fVar4 = *(float *)(iVar15 + 0xc);
      fVar19 = fVar17 * 3.0;
      fVar5 = *(float *)(iVar14 + 0x28);
      fVar6 = *(float *)(iVar14 + 0x2c);
      fVar7 = *(float *)(iVar14 + 8);
      fVar8 = *(float *)(iVar14 + 0xc);
      fVar20 = *unaff_ESI * 3.0;
      fVar9 = *(float *)(iVar14 + 8);
      fVar10 = *(float *)(iVar14 + 0xc);
      fVar11 = *unaff_ESI;
      fVar12 = *(float *)(iVar15 + 8);
      fVar13 = *(float *)(iVar15 + 0xc);
      *in_EDX = fVar11 * *(float *)(iVar15 + 4) * fVar17 +
                ((fVar16 * *(float *)(iVar14 + 4) +
                 fVar20 * (fVar18 * *(float *)(iVar14 + 0x24) + *(float *)(iVar14 + 4))) * fVar16 +
                fVar19 * (*(float *)(iVar15 + 4) + fVar18 * *(float *)(iVar15 + 0x18))) * fVar16;
      in_EDX[1] = fVar12 * fVar11 * fVar17 +
                  ((fVar9 * fVar16 + (fVar7 + fVar5 * fVar18) * fVar20) * fVar16 +
                  (fVar3 + fVar1 * fVar18) * fVar19) * fVar16;
      in_EDX[2] = fVar17 * fVar11 * fVar13 +
                  fVar16 * ((fVar10 * fVar16 + fVar20 * (fVar8 + fVar18 * fVar6)) * fVar16 +
                           fVar19 * (fVar4 + fVar18 * fVar2));
      return;
    }
  }
  if (*unaff_ESI == 1.0) {
    iVar14 = *param_1;
    *in_EDX = *(float *)(iVar14 + 4);
    in_EDX[1] = *(float *)(iVar14 + 8);
    in_EDX[2] = *(float *)(iVar14 + 0xc);
    return;
  }
  *in_EDX = *(float *)(iVar14 + 4);
  in_EDX[1] = *(float *)(iVar14 + 8);
  in_EDX[2] = *(float *)(iVar14 + 0xc);
  return;
}

