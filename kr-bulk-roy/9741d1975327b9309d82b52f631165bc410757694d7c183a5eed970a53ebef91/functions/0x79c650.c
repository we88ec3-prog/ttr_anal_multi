
void FUN_0079c650(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  float10 extraout_ST0;
  float10 fVar6;
  float10 extraout_ST1;
  
  fVar1 = param_1 * 5.0 + (float)unaff_ESI[2];
  unaff_ESI[2] = (int)fVar1;
  if (3.1415927 < fVar1) {
    iVar5 = FUN_008fed10();
    unaff_ESI[2] = (int)(float)(extraout_ST1 - extraout_ST0 * (float10)iVar5);
  }
  fVar2 = (float)unaff_ESI[5];
  iVar5 = unaff_ESI[3];
  iVar3 = unaff_ESI[4];
  fVar6 = (float10)FUN_008ff0a0();
  iVar4 = *unaff_ESI;
  fVar1 = (float)unaff_ESI[1];
  *(int *)(iVar4 + 0x24) = iVar5;
  *(int *)(iVar4 + 0x28) = iVar3;
  *(float *)(iVar4 + 0x2c) = (float)fVar6 * 4.0 * fVar1 + fVar2;
  FUN_007beb30(*unaff_ESI,param_1);
  return;
}

