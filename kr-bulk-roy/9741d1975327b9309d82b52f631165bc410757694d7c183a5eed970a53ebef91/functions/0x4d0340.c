
undefined4 FUN_004d0340(void)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  float fStack_24;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  
  (**(code **)(*in_ECX + 0x38))();
  if (DAT_00fba7cc == 0) {
    iVar5 = FUN_00891268(0x1380);
    if (iVar5 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  fVar1 = 1.0 / (float)*(int *)(DAT_00fba7cc + 0x1360);
  if (in_ECX[0x35] == 1) {
    iVar5 = in_ECX[0x32];
    fStack_1c = (float)in_ECX[0x30] - (float)in_ECX[0x28];
    fStack_18 = (float)in_ECX[0x31] - (float)in_ECX[0x29];
    if (iVar5 == 0) {
      (**(code **)(*in_ECX + 0x44))(in_ECX + 0x30,1);
      in_ECX[0x3a] = in_ECX[0x30];
      in_ECX[0x3b] = in_ECX[0x31];
      fVar1 = (float)in_ECX[0x3a] - (float)in_ECX[0x28];
      fStack_1c = (float)in_ECX[0x3b] - (float)in_ECX[0x29];
      fStack_10 = fVar1 * fVar1 + fStack_1c * fStack_1c;
      if (4.0 < fStack_10) {
        in_ECX[0x36] = (int)fVar1;
        in_ECX[0x37] = (int)fStack_1c;
        fStack_10 = fVar1;
      }
      *(ushort *)((int)in_ECX + 0xe2) = *(ushort *)((int)in_ECX + 0xe2) & 0x7fff;
      in_ECX[0x35] = 0;
      fStack_c = fStack_1c;
    }
    else {
      fStack_10 = fStack_1c * fStack_1c + fStack_18 * fStack_18;
      fVar6 = (float10)FUN_008ff870();
      fStack_10 = (float)iVar5;
      if (iVar5 < 0) {
        fStack_10 = fStack_10 + 4.2949673e+09;
      }
      fStack_10 = (float)fVar6 / fStack_10;
      D3DXVec2Normalize(&fStack_1c,&fStack_1c);
      fVar1 = fStack_18 * fVar1;
      fStack_18 = (float)in_ECX[0x28] + fStack_18 * fStack_24;
      fStack_14 = (float)in_ECX[0x29] + fVar1;
      (**(code **)(*in_ECX + 0x44))(&fStack_18,1);
      in_ECX[0x32] = in_ECX[0x32] + -1;
    }
  }
  else {
    if ((*(ushort *)((int)in_ECX + 0xe2) & 0x8000) == 0) {
      uVar4 = 0x40800000;
    }
    else {
      fVar6 = (float10)(**(code **)(*in_ECX + 0x60))();
      bVar2 = *(byte *)(in_ECX + 0x39);
      fStack_10 = (float)(fVar6 * (float10)fVar1);
      if ((DAT_00fb7c18 & 1) == 0) {
        DAT_00fb7c18 = DAT_00fb7c18 | 1;
        FUN_004449d0();
      }
      fStack_c = fStack_10 * (float)(&DAT_00fb8024)[(uint)bVar2 * 2];
      fStack_1c = (float)in_ECX[0x28] + fStack_10 * (float)(&DAT_00fb8020)[(uint)bVar2 * 2];
      fStack_18 = (float)in_ECX[0x29] + fStack_c;
      fStack_10 = fStack_10 * (float)(&DAT_00fb8020)[(uint)bVar2 * 2];
      (**(code **)(*in_ECX + 0x44))(&fStack_1c,1);
      uVar4 = 0x40000000;
    }
    FUN_004cad60(fVar1,uVar4,1);
  }
  iVar5 = in_ECX[0x3c];
  if (iVar5 != 0) {
    fStack_18 = (float)in_ECX[0x29];
    fStack_14 = (float)in_ECX[0x2a];
    iVar3 = in_ECX[0x28];
    fVar6 = (float10)FUN_008ff0a0();
    fVar1 = (float)in_ECX[0x2a];
    *(int *)(iVar5 + 0x28) = iVar3;
    *(float *)(iVar5 + 0x2c) = fStack_18;
    *(undefined4 *)(iVar5 + 0x70) = 1;
    *(float *)(iVar5 + 0x30) = (float)fVar6 * 3.0 * 0.09 + fVar1;
  }
  return 0;
}

