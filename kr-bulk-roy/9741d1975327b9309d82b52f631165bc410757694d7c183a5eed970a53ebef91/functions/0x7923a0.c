
void FUN_007923a0(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float *in_EAX;
  int *in_ECX;
  
  iVar6 = *in_ECX;
  iVar7 = *param_1;
  fVar1 = *(float *)(iVar7 + 8);
  fVar2 = *(float *)(iVar6 + 8);
  fVar3 = *(float *)(iVar7 + 0xc);
  fVar4 = *(float *)(iVar6 + 0xc);
  fVar5 = *param_2;
  *in_EAX = *(float *)(iVar6 + 4) + fVar5 * (*(float *)(iVar7 + 4) - *(float *)(iVar6 + 4));
  in_EAX[1] = *(float *)(iVar6 + 8) + fVar5 * (fVar1 - fVar2);
  in_EAX[2] = fVar5 * (fVar3 - fVar4) + *(float *)(iVar6 + 0xc);
  return;
}

