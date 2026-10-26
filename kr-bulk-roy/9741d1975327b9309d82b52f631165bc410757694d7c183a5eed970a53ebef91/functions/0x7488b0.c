
void FUN_007488b0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float *unaff_ESI;
  float *unaff_EDI;
  
  piVar4 = (int *)FUN_00443da0();
  fVar2 = *unaff_EDI;
  iVar1 = *piVar4;
  fVar3 = unaff_EDI[1];
  iVar5 = FUN_00443da0();
  iVar5 = *(int *)(iVar5 + 4);
  *unaff_ESI = fVar2 - (float)iVar1;
  unaff_ESI[1] = fVar3 - (float)iVar5;
  return;
}

