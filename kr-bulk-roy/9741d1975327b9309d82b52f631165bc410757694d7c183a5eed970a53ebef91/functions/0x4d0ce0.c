
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d0ce0(void)

{
  code *pcVar1;
  float fVar2;
  int *piVar3;
  int *in_EAX;
  int *unaff_ESI;
  float10 fVar4;
  undefined1 uStack_14;
  uint uStack_10;
  uint uStack_c;
  
  unaff_ESI[0x109] = *in_EAX;
  unaff_ESI[0x10a] = in_EAX[1];
  fVar4 = (float10)FUN_008fedca();
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  piVar3 = DAT_00fba7a4;
  fVar2 = _DAT_00fb8824 * ((float)fVar4 + 1.5707964);
  uStack_10 = uStack_10 & 0xffff0000 | 0x80000000;
  unaff_ESI[0x10c] = 0x4e6e6b28;
  uStack_c = (uint)ROUND(fVar2);
  uStack_14 = (undefined1)uStack_c;
  uStack_c = uStack_c & 0xff;
  (**(code **)(*piVar3 + 0x20))();
  pcVar1 = *(code **)(*unaff_ESI + 0x58);
  unaff_ESI[0x38] = uStack_10;
  *(undefined1 *)(unaff_ESI + 0x39) = uStack_14;
  (*pcVar1)(uStack_c);
  return;
}

