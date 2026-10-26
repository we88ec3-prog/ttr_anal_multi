
void FUN_00801450(void)

{
  float fVar1;
  int iVar2;
  uint *unaff_ESI;
  float *unaff_EDI;
  
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[2] + *unaff_EDI) - unaff_EDI[2] * 0.5;
  unaff_ESI[1] = (uint)fVar1;
  *unaff_ESI = (uint)((float)unaff_ESI[2] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[3] + unaff_EDI[1]) - unaff_EDI[3] * 0.5;
  unaff_ESI[2] = (uint)fVar1;
  *unaff_ESI = (uint)((float)unaff_ESI[1] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[6] + unaff_EDI[4]) - unaff_EDI[6] * 0.5;
  unaff_ESI[4] = (uint)fVar1;
  unaff_ESI[3] = (uint)((float)unaff_ESI[5] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[7] + unaff_EDI[5]) - unaff_EDI[7] * 0.5;
  unaff_ESI[5] = (uint)fVar1;
  unaff_ESI[3] = (uint)((float)unaff_ESI[4] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[10] + unaff_EDI[8]) - unaff_EDI[10] * 0.5;
  unaff_ESI[7] = (uint)fVar1;
  unaff_ESI[6] = (uint)((float)unaff_ESI[8] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[0xb] + unaff_EDI[9]) - unaff_EDI[0xb] * 0.5;
  unaff_ESI[8] = (uint)fVar1;
  unaff_ESI[6] = (uint)((float)unaff_ESI[7] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[0xe] + unaff_EDI[0xc]) - unaff_EDI[0xe] * 0.5;
  unaff_ESI[10] = (uint)fVar1;
  unaff_ESI[9] = (uint)((float)unaff_ESI[0xb] != fVar1);
  iVar2 = FUN_0089289d();
  fVar1 = (((float)iVar2 / 32767.0) * unaff_EDI[0xf] + unaff_EDI[0xd]) - unaff_EDI[0xf] * 0.5;
  unaff_ESI[0xb] = (uint)fVar1;
  if ((float)unaff_ESI[10] != fVar1) {
    unaff_ESI[9] = 1;
    return;
  }
  unaff_ESI[9] = 0;
  return;
}

