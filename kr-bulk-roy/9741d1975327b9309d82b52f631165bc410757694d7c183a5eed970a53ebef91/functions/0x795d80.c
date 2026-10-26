
void FUN_00795d80(void)

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
  int *in_EAX;
  int extraout_ECX;
  int iVar13;
  int *in_EDX;
  int extraout_EDX;
  int iVar14;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar15;
  
  iVar13 = *in_EAX;
  iVar14 = *in_EDX;
  if (iVar13 != iVar14) {
    fVar15 = (float10)FUN_00796000(*unaff_EDI,*(undefined4 *)(iVar13 + 0x28),
                                   *(undefined4 *)(iVar14 + 0x28));
    *unaff_EDI = (float)fVar15;
    iVar13 = extraout_ECX;
    iVar14 = extraout_EDX;
  }
  fVar1 = *unaff_EDI;
  fVar2 = fVar1 * fVar1;
  fVar9 = fVar2 * fVar1;
  fVar11 = fVar9 * 2.0 - fVar2 * 3.0;
  fVar12 = fVar11 + 1.0;
  fVar11 = -fVar11;
  fVar10 = fVar9 + (fVar1 - fVar2 * 2.0);
  fVar9 = fVar9 - fVar2;
  fVar1 = *(float *)(iVar13 + 8);
  fVar2 = *(float *)(iVar13 + 0xc);
  fVar3 = *(float *)(iVar14 + 8);
  fVar4 = *(float *)(iVar14 + 0xc);
  fVar5 = *(float *)(iVar13 + 8);
  fVar6 = *(float *)(iVar13 + 0xc);
  fVar7 = *(float *)(iVar14 + 8);
  fVar8 = *(float *)(iVar14 + 0xc);
  *unaff_ESI = fVar9 * *(float *)(iVar14 + 4) +
               fVar10 * *(float *)(iVar13 + 4) +
               fVar11 * *(float *)(iVar14 + 4) + fVar12 * *(float *)(iVar13 + 4);
  unaff_ESI[1] = fVar7 * fVar9 + fVar3 * fVar11 + fVar1 * fVar12 + fVar5 * fVar10;
  unaff_ESI[2] = fVar9 * fVar8 + fVar10 * fVar6 + fVar11 * fVar4 + fVar12 * fVar2;
  return;
}

