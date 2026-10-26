
void FUN_00792990(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_EAX;
  int iVar5;
  float *in_EDX;
  float *unaff_ESI;
  
  iVar5 = *in_EAX;
  fVar2 = 1.0 - *in_EDX;
  fVar3 = *in_EDX * *in_EDX;
  if ((*(uint *)(iVar5 + 0xc) & 0x1c00) != 0x800) {
    iVar1 = *param_1;
    if ((*(uint *)(iVar1 + 0xc) & 0x380) != 0x100) {
      fVar4 = (float)(*(int *)(iVar1 + 8) - *(int *)(iVar5 + 8)) / 3.0;
      *unaff_ESI = fVar2 * (fVar2 * (fVar2 * *(float *)(iVar5 + 4) +
                                    *in_EDX * 3.0 *
                                    (*(float *)(iVar5 + 0x14) * fVar4 + *(float *)(iVar5 + 4))) +
                           (*(float *)(iVar1 + 4) + *(float *)(iVar1 + 0x10) * fVar4) * fVar3 * 3.0)
                   + *(float *)(iVar1 + 4) * *in_EDX * fVar3;
      return;
    }
  }
  if (*in_EDX == 1.0) {
    iVar5 = *param_1;
  }
  *unaff_ESI = *(float *)(iVar5 + 4);
  return;
}

