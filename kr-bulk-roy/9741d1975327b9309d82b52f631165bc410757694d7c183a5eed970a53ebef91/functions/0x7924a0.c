
void FUN_007924a0(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  float *in_EAX;
  int *in_ECX;
  
  iVar8 = *in_ECX;
  iVar9 = *param_1;
  fVar1 = *(float *)(iVar9 + 8);
  fVar2 = *(float *)(iVar8 + 8);
  fVar3 = *(float *)(iVar9 + 0xc);
  fVar4 = *(float *)(iVar8 + 0xc);
  fVar5 = *(float *)(iVar9 + 0x10);
  fVar6 = *(float *)(iVar8 + 0x10);
  fVar7 = *param_2;
  *in_EAX = *(float *)(iVar8 + 4) + fVar7 * (*(float *)(iVar9 + 4) - *(float *)(iVar8 + 4));
  in_EAX[1] = *(float *)(iVar8 + 8) + fVar7 * (fVar1 - fVar2);
  in_EAX[2] = (fVar3 - fVar4) * fVar7 + *(float *)(iVar8 + 0xc);
  in_EAX[3] = *(float *)(iVar8 + 0x10) + fVar7 * (fVar5 - fVar6);
  return;
}

