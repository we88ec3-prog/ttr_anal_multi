
void FUN_007950b0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_EAX;
  int extraout_ECX;
  int iVar5;
  int *in_EDX;
  int extraout_EDX;
  int iVar6;
  float *unaff_ESI;
  float10 fVar7;
  
  iVar5 = *in_EAX;
  iVar6 = *in_EDX;
  if (iVar5 != iVar6) {
    fVar7 = (float10)FUN_00796000(*unaff_ESI,*(undefined4 *)(iVar5 + 0x20),
                                  *(undefined4 *)(iVar6 + 0x20));
    *unaff_ESI = (float)fVar7;
    iVar5 = extraout_ECX;
    iVar6 = extraout_EDX;
  }
  fVar1 = *unaff_ESI;
  fVar4 = fVar1 * fVar1;
  fVar2 = fVar4 * fVar1;
  fVar3 = fVar2 * 2.0 - fVar4 * 3.0;
  *param_1 = *(float *)(iVar6 + 4) * (fVar2 - fVar4) +
             *(float *)(iVar5 + 4) * (fVar2 + (fVar1 - fVar4 * 2.0)) +
             *(float *)(iVar6 + 4) * -fVar3 + *(float *)(iVar5 + 4) * (fVar3 + 1.0);
  return;
}

