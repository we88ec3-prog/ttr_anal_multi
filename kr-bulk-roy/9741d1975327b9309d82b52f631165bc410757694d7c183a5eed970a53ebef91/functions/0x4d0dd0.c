
void FUN_004d0dd0(void)

{
  byte bVar1;
  code *pcVar2;
  float fVar3;
  int *unaff_ESI;
  float10 fVar4;
  float fStack_10;
  float fStack_c;
  
  if ((unaff_ESI[0x35] == 0) && ((*(ushort *)((int)unaff_ESI + 0xe2) & 0x8000) != 0)) {
    fVar4 = (float10)(**(code **)(*unaff_ESI + 0x60))();
    bVar1 = *(byte *)(unaff_ESI + 0x39);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    fStack_10 = (float)(fVar4 * (float10)0.03333333507180214) *
                (float)(&DAT_00fb8020)[(uint)bVar1 * 2];
    fStack_c = (float)(fVar4 * (float10)0.03333333507180214) *
               (float)(&DAT_00fb8024)[(uint)bVar1 * 2];
    fVar3 = (float)unaff_ESI[0x109] - (float)unaff_ESI[0x28];
    fVar3 = ((float)unaff_ESI[0x10a] - (float)unaff_ESI[0x29]) *
            ((float)unaff_ESI[0x10a] - (float)unaff_ESI[0x29]) + fVar3 * fVar3;
    if ((fVar3 <= (float)unaff_ESI[0x10c]) &&
       ((fStack_c * fStack_c + fStack_10 * fStack_10) * 3.0 <= fVar3)) {
      pcVar2 = *(code **)(*unaff_ESI + 0x54);
      unaff_ESI[0x10c] = (int)fVar3;
      (*pcVar2)(&fStack_10);
      return;
    }
    (**(code **)(*unaff_ESI + 0x44))(unaff_ESI + 0x109,1);
    (**(code **)(*unaff_ESI + 0x68))(1,0x3f800000);
    *(ushort *)((int)unaff_ESI + 0xe2) = *(ushort *)((int)unaff_ESI + 0xe2) & 0x7fff;
  }
  return;
}

