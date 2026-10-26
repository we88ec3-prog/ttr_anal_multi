
undefined4 FUN_004ca890(void)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  
  if (in_ECX[0x2b] != 0) {
    (**(code **)(*in_ECX + 0x38))();
  }
  if (DAT_00fba7cc == 0) {
    iVar5 = FUN_00891268(0x1380);
    if (iVar5 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  fVar2 = 1.0 / (float)*(int *)(DAT_00fba7cc + 0x1360);
  if (in_ECX[0x35] != 1) {
    if ((*(ushort *)((int)in_ECX + 0xe2) & 0x8000) == 0) {
      uVar4 = 0x40800000;
    }
    else {
      fVar6 = (float10)(**(code **)(*in_ECX + 0x60))();
      bVar1 = *(byte *)(in_ECX + 0x39);
      fStack_10 = (float)(fVar6 * (float10)fVar2);
      if ((DAT_00fb7c18 & 1) == 0) {
        DAT_00fb7c18 = DAT_00fb7c18 | 1;
        FUN_004449d0();
      }
      fStack_18 = fStack_10 * (float)(&DAT_00fb8020)[(uint)bVar1 * 2];
      fStack_14 = fStack_10 * (float)(&DAT_00fb8024)[(uint)bVar1 * 2];
      (**(code **)(*in_ECX + 0x54))(&fStack_18);
      uVar4 = 0x40000000;
    }
    FUN_004cad60(fVar2,uVar4,0);
    return 0;
  }
  iVar5 = in_ECX[0x32];
  fStack_18 = (float)in_ECX[0x30] - (float)in_ECX[0x28];
  fStack_14 = (float)in_ECX[0x31] - (float)in_ECX[0x29];
  if (iVar5 != 0) {
    fStack_10 = fStack_18 * fStack_18 + fStack_14 * fStack_14;
    fVar6 = (float10)FUN_008ff870();
    fStack_10 = (float)iVar5;
    if (iVar5 < 0) {
      fStack_10 = fStack_10 + 4.2949673e+09;
    }
    fStack_10 = (float)fVar6 / fStack_10;
    D3DXVec2Normalize(&fStack_18,&fStack_18);
    (**(code **)(*in_ECX + 0x54))(&stack0xffffffe0);
    in_ECX[0x32] = in_ECX[0x32] + -1;
    return 0;
  }
  (**(code **)(*in_ECX + 0x44))(in_ECX + 0x30,1);
  in_ECX[0x3a] = in_ECX[0x30];
  in_ECX[0x3b] = in_ECX[0x31];
  fVar2 = (float)in_ECX[0x3a] - (float)in_ECX[0x28];
  fVar3 = (float)in_ECX[0x3b] - (float)in_ECX[0x29];
  if (4.0 < fVar3 * fVar3 + fVar2 * fVar2) {
    in_ECX[0x36] = (int)fVar2;
    in_ECX[0x37] = (int)fVar3;
  }
  *(ushort *)((int)in_ECX + 0xe2) = *(ushort *)((int)in_ECX + 0xe2) & 0x7fff;
  in_ECX[0x35] = 0;
  return 0;
}

