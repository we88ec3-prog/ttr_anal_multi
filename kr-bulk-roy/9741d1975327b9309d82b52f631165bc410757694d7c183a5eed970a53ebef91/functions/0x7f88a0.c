
int FUN_007f88a0(float *param_1)

{
  float fVar1;
  float fVar2;
  undefined4 in_EAX;
  undefined2 uVar5;
  int iVar3;
  int iVar4;
  float *unaff_ESI;
  float *unaff_EDI;
  
  fVar1 = *unaff_EDI;
  fVar2 = *unaff_ESI;
  uVar5 = (undefined2)((uint)in_EAX >> 0x10);
  if (fVar2 < fVar1 == (fVar2 == fVar1)) {
    iVar3 = FUN_0089289d();
    uVar5 = (undefined2)((uint)(iVar3 / 10000) >> 0x10);
    fVar1 = (fVar2 - fVar1) * (float)(iVar3 % 10000) * 0.0001 + fVar1;
  }
  *param_1 = fVar1;
  fVar1 = unaff_EDI[1];
  fVar2 = unaff_ESI[1];
  if (fVar2 < fVar1 == (fVar2 == fVar1)) {
    iVar3 = FUN_0089289d();
    uVar5 = (undefined2)((uint)(iVar3 / 10000) >> 0x10);
    fVar1 = (fVar2 - fVar1) * (float)(iVar3 % 10000) * 0.0001 + fVar1;
  }
  param_1[1] = fVar1;
  fVar1 = unaff_EDI[2];
  fVar2 = unaff_ESI[2];
  iVar3 = CONCAT22(uVar5,(ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                         (ushort)(fVar2 == fVar1) << 0xe);
  if (fVar2 < fVar1 == (fVar2 == fVar1)) {
    iVar4 = FUN_0089289d();
    iVar3 = iVar4 / 10000;
    fVar1 = (fVar2 - fVar1) * (float)(iVar4 % 10000) * 0.0001 + fVar1;
  }
  param_1[2] = fVar1;
  return iVar3;
}

